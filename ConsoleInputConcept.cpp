#include "ConsoleInputConcept.hpp"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;
using namespace concept;

void ConsoleInputConcept::run()
{
    string input;
    cout << "Enter any text: ";
    getline(cin, input);

    cout << endl << "You entered: " << input << endl;

    double inputNumber;
    cout << endl << "Enter a number: ";
    getline(cin, input);
    // In the ()'s, make a stringstream from the input string, then put the 
    // result into inputNumber. The input stream is the result of this
    // expression. Outside of the ()'s, call .fail() on the istream and store
    // the result.
    bool fail = (stringstream(input) >> inputNumber).fail();

    cout << endl << (fail
        ? "That is not a number."
        : "You entered: " + to_string(inputNumber)) << endl;
}