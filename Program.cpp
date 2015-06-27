#include <iostream>
#include <memory>

// TODO: Implement ArrayAndVectorConcept
//#include "ArrayAndVectorConcept.hpp"

#include "BasicFileIOConcept.hpp"
#include "ConsoleInputConcept.hpp"

// TODO: Implement ConstUsesConcept
//#include "ConstUsesConcept.hpp"

// TODO: Implement CopyAndAssignmentConcept
//#include "CopyAndAssignmentConcept.hpp"

// TODO: Implement ExplicitVsImplicitConversionConcept
//#include "ExplicitVsImplicitConversionConcept.hpp"

#include "FunctionPointerConcept.hpp"
#include "HelloWorldConcept.hpp"

// TODO: Implement MapAndUnorderedMapConcept
//#include "MapAndUnorderedMapConcept.hpp"

#include "MemoryManagementConcept.hpp"
#include "ParameterTypesConcept.hpp"


using namespace std;
using namespace concept;

int main()
{
    unique_ptr<IConcept> currentConcept(new FunctionPointerConcept);
    currentConcept->run();

    cout << endl << "Press enter to finish...";
    cin.get();

    return 0;
}