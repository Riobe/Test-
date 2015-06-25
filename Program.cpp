#include <iostream>

// TODO: Implement ArrayAndVectorConcept
//#include "ArrayAndVectorConcept.hpp"

// TODO: Implement BasicFileIO
//#include "BasicFileIO.hpp"

#include "ConsoleInputConcept.hpp"

// TODO: Implement FunctionPointerConcept
//#include "FunctionPointerConcept.hpp"

// TODO: Implement HelloWorldConcept
//#include "HelloWorldConcept.hpp"

// TODO: Implement MapAndUnorderedMapConcept
//#include "MapAndUnorderedMapConcept.hpp"

// TODO: Implement MemoryManagementConcept
//#include "MemoryManagementConcept.hpp"

// TODO: Implement ParameterTypesConcept
//#include "ParameterTypesConcept.hpp"


using namespace std;
using namespace concept;

int x;
int main()
{
    IConcept *concept = new ConsoleInputConcept();

    concept->run();

    cout << x;

    cout << endl << "Press enter to finish...";
    
    cin.get();

    delete concept;

    return 0;
}