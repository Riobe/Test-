#include <iostream>

// TODO: Implement ArrayAndVectorConcept
//#include "ArrayAndVectorConcept.hpp"

// TODO: Implement BasicFileIO
//#include "BasicFileIO.hpp"

//#include "ConsoleInputConcept.hpp"

// TODO: Implement FunctionPointerConcept
//#include "FunctionPointerConcept.hpp"

//#include "HelloWorldConcept.hpp"

// TODO: Implement MapAndUnorderedMapConcept
//#include "MapAndUnorderedMapConcept.hpp"

// TODO: Implement MemoryManagementConcept
//#include "MemoryManagementConcept.hpp"

#include "ParameterTypesConcept.hpp"


using namespace std;
using namespace concept;

int x;
int main()
{
    currentConcept.run();

    cout << endl << "Press enter to finish...";
    cin.get();

    return 0;
}