#include <iostream>
#include "HelloWorldConcept.hpp"
#include "ConsoleInput.hpp"

using namespace std;
using namespace concept;

int main()
{
    IConcept *concept = new ConsoleInput();

    concept->Run();

    cout << endl << "Press enter to finish...";
    
    cin.get();

    delete concept;

    return 0;
}