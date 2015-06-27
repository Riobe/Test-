#ifndef CONSTUSESCONCEPT_HPP
#define CONSTUSESCONCEPT_HPP

#include "IConcept.hpp"

namespace concept
{
    class ConstUsesConcept : public IConcept
    {
    public:
        virtual void run();
    };
}

#endif // !CONSTUSESCONCEPT_HPP
