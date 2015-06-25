#include <iostream>
#include "HelloWorldConcept.hpp"
#include "ConsoleInputConcept.hpp"

using namespace std;
using namespace concept;

int main()
{
    IConcept *concept = new ConsoleInputConcept();

    concept->run();

    cout << endl << "Press enter to finish...";
    
    cin.get();

    delete concept;

    return 0;
}