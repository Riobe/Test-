#ifndef ICONCEPT_HPP
#define ICONCEPT_HPP

#include "Interface.hpp"

namespace concept
{
    class IConcept : public Interface
    {
    public:
        virtual ~IConcept() { }

        virtual void run() = 0;
    };
}
#endif
