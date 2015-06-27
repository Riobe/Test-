#include "FunctionPointerConcept.hpp"

#include <iostream>
#include <string>

using namespace std;
using namespace concept;

// static keyword placed in .cpp file means that a certain function has a 
// static linkage, ie. it is accessible only from other functions in the same 
// file.
static void nonMemberGlobalFunction(string message)
{
    cout << "nonMemberGlobalFunction(\"" << message << "\");" << endl;
}

void FunctionPointerConcept::run()
{
    //cout << "outputInstanceFunc(&FunctionPointerConcept::
    outputInstanceFunc(&FunctionPointerConcept::instanceMemberFunction, "First call");
    outputNonInstanceFunc(staticMemberFunction, "Second call");
    outputNonInstanceFunc(nonMemberGlobalFunction, "Third call");
}

void FunctionPointerConcept::staticMemberFunction(std::string message)
{
    cout << "staticMemberFunction(\"" << message << "\");" << endl;
}

void FunctionPointerConcept::instanceMemberFunction(std::string message)
{
    cout << "instanceMemberFunction(\"" << message << "\");" << endl;
}


void FunctionPointerConcept::outputNonInstanceFunc(void(*func)(std::string), string message)
{
    cout << "outputNonInstanceFunc() called" << endl;
    func(message);
    cout << "outputNonInstanceFunc() ending" << endl;
    cout << endl;
}

void FunctionPointerConcept::outputInstanceFunc(void(FunctionPointerConcept::*func)(string), string message)
{
    cout << "outputInstanceFunc() called" << endl;
    (this->*func)(message);
    cout << "outputInstanceFunc() ending" << endl;
    cout << endl;
}
