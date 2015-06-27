#include <iostream>
#include <memory>

// TODO: Implement ArrayAndVectorConcept
//#include "ArrayAndVectorConcept.hpp"

#include "BasicFileIOConcept.hpp"
#include "ConsoleInputConcept.hpp"
#include "ConstUsesConcept.hpp"

// TODO: Implement CopyAndAssignmentConcept
//#include "CopyAndAssignmentConcept.hpp"

// TODO: Implement ExplicitVsImplicitConversionConcept
//#include "ExplicitVsImplicitConversionConcept.hpp"

#include "FunctionPointerConcept.hpp"
#include "HelloWorldConcept.hpp"

// TODO: Implement IterationConcept
//#include "IterationConcept.hpp"

#include "UnorderedMapConcept.hpp"
#include "SmartPointerConcept.hpp"
#include "ParameterTypesConcept.hpp"


using namespace std;
using namespace concept;

int main()
{
    unique_ptr<IConcept> currentConcept(new ConstUsesConcept);
    currentConcept->run();

    cout << endl << "Press enter to finish...";
    cin.get();

    return 0;
}