#include "ParameterTypesConcept.hpp"

#include <iostream>

using namespace std;
using namespace concept;

void ParamaterTypesConcept::run()
{
    int x = 0;
    cout << "Initial value: " << x << endl;

    passByValue(x);
    cout << "After passByValue(x): " << x << endl;

    passByReference(x);
    cout << "After passByReference(x): " << x << endl;

    passToPointer(&x);
    cout << "After passToPointer(&x): " << x << endl;
}

void ParamaterTypesConcept::passByValue(int x)
{
    x = 5;
}

void ParamaterTypesConcept::passByReference(int &x)
{
    x = 15;
}

void ParamaterTypesConcept::passToPointer(int* x)
{
    *x = 25;
}
