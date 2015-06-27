#include "MemoryManagementConcept.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <memory>

using namespace std;
using namespace concept;

const char MemoryManagementConcept::INDENT = '  ';
const int MemoryManagementConcept::INDENT_SIZE = 2;

void MemoryManagementConcept::run()
{
    uniqueSmartPointer();
    sharedSmartPointer();
    weakSmartPointer();
}

void MemoryManagementConcept::uniqueSmartPointer()
{
    int nestLevel = 0;
    output("Demonstrating unique_ptr", nestLevel);
    output("{", nestLevel);

    nestLevel++; 
    output("{", nestLevel);

    {
        nestLevel++;
        output("Creating object in nested scope using unique_ptr", nestLevel);
        unique_ptr<Object> object(new Object(nestLevel));
        output("Exiting nested scope.", nestLevel);
    }

    nestLevel--;
    output("}", nestLevel);
    output("Outside of nested scope.", nestLevel);
    output("{", nestLevel);

    {
        nestLevel++;
        unique_ptr<Object> first(new Object(nestLevel));
        unique_ptr<Object> second;

        // http://stackoverflow.com/questions/7627098/what-is-a-lambda-expression-in-c11
        auto outputPointers = [&first, &second, &nestLevel]()
        {
            stringstream format;
            format << "first: " << first.get() << " | second: " << second.get() << "\n";
            output(format.str(), nestLevel);
        };

        outputPointers();

        second = move(first);

        output("After second = move(first)", nestLevel);
        outputPointers();

        first.reset(second.release());

        output("After first.reset(second.release());", nestLevel);
        outputPointers();

        output("Sending first.get() to void outputObject(Object* const value, int nestLevel) const;", nestLevel);
        outputObject(first.get(), nestLevel);
    }

    nestLevel--;
    output("}", nestLevel);

    nestLevel--;
    output("}", nestLevel);
}

void MemoryManagementConcept::sharedSmartPointer()
{
    int nestLevel = 0;
    output("Demonstrating shared_ptr", nestLevel);
    output("{", nestLevel);
    nestLevel++;

    output("{", nestLevel);
    {
        nestLevel++;
        output("Creating object in nested scope using shared_ptr", nestLevel);
        shared_ptr<Object> object(new Object(nestLevel));
        output("Exiting nested scope.", nestLevel);
    }
    nestLevel--;
    output("{", nestLevel);

    output("{", nestLevel);
    {
        nestLevel++;
        shared_ptr<Object> first(new Object(nestLevel));
        shared_ptr<Object> second;

        // http://stackoverflow.com/questions/7627098/what-is-a-lambda-expression-in-c11
        auto outputPointers = [&first, &second, &nestLevel]()
        {
            stringstream format;
            format << "first: " << first.get() << " | second: " << second.get() << "\n";
            output(format.str(), nestLevel);
        };

        outputPointers();

        second = move(first);

        output("After second = move(first)", nestLevel);
        outputPointers();

        first = second;

        output("After first = second;", nestLevel);
        outputPointers();

        output("Sending first.get() to void outputObject(Object* const value, int nestLevel) const;", nestLevel);
        outputObject(first.get(), nestLevel);

        output("Demonstrating shared_ptr getting destroyed, but not releasing memory unless it was last pointer.", nestLevel);
        output("{", nestLevel);
        nestLevel++;
        {
            stringstream format;
            shared_ptr<Object> third = second;

            output("shared_ptr<Object> third = second;", nestLevel);
            output("", nestLevel);

            outputPointers();
            format << "third: " << third.get();
            output(format.str(), nestLevel);
        }
        nestLevel--;
        output("}", nestLevel);

        output("", nestLevel);
        output("third out of scope", nestLevel);
    }
    nestLevel--;
    output("}", nestLevel);

    nestLevel--;
    output("}", nestLevel);
}

void MemoryManagementConcept::weakSmartPointer()
{
    int nestLevel = 0;
    output("Demonstrating weak_ptr", nestLevel);
    output("{", nestLevel);
    nestLevel++;

    weak_ptr<Object> weak;
    auto outputWeak = [&weak, &nestLevel]()
    {
        stringstream format;
        format << "weak " << (weak.expired() ? "is" : "is not") << " expired\n";
        output(format.str(), nestLevel);
    };

    output("Referencing shared_ptr from weak_ptr<Object> weak.", nestLevel);
    output("{", nestLevel);
    nestLevel++;
    {
        shared_ptr<Object> shared(new Object(nestLevel));

        // http://stackoverflow.com/questions/7627098/what-is-a-lambda-expression-in-c11
        auto outputPointers = [&weak, &shared, &nestLevel]()
        {
            stringstream format;
            format << "shared: " << shared.get() << " | weak " << (weak.expired() ? "is" : "is not") << " expired\n";
            output(format.str(), nestLevel);
        };

        output("shared_ptr<Object> shared(new Object(nestLevel));", nestLevel);
        outputPointers();

        weak = shared;
        output("weak = shared;", nestLevel);
        outputPointers();

        output("", nestLevel);
        output("Getting a lock from weak to use referenced object.", nestLevel);
        // auto could be used here to make it (auto sharedObject = weak.lock())
        if (shared_ptr<Object> sharedObject =  weak.lock())
        {
            outputObject(sharedObject.get(), nestLevel);
            outputWeak();
        }
    }
    nestLevel--;
    output("}", nestLevel);

    output("", nestLevel);
    output("Outside of nested block.", nestLevel);
    // A weak pointer won't keep the object around now that the shared_ptr let go of it.
    outputWeak();

    nestLevel--;
    output("}", nestLevel);
}

void MemoryManagementConcept::outputObject(Object* const value, int nestLevel) const
{
    output("outputObject: Object::nestLevel() == " + to_string(value->nestLevel()), nestLevel);
}

MemoryManagementConcept::Object::Object(int nestLevel)
    : _nestLevel(nestLevel)
{
    MemoryManagementConcept::output("MemoryManagementConcept::Object()", _nestLevel);
}

MemoryManagementConcept::Object::~Object()
{
    MemoryManagementConcept::output("MemoryManagementConcept::Object::~Object()", _nestLevel);
}

void MemoryManagementConcept::output(string message, int indentLevel)
{
    cout << string(indentLevel * INDENT_SIZE, INDENT) << message << endl;
}

int MemoryManagementConcept::Object::nestLevel() const
{
    return _nestLevel;
}

