#ifndef PARAMETERTYPESCONCEPT_HPP
#define PARAMETERTYPESCONCEPT_HPP

#include "IConcept.hpp"

namespace concept
{
    class ParamaterTypesConcept : public IConcept
    {
    public:
        virtual void run();

    private:
        void passByValue(int x);
        void passByReference(int &x);
        void passToPointer(int* x);
    } currentConcept;
}

#endif // !PARAMETERTYPESCONCEPT_HPP
