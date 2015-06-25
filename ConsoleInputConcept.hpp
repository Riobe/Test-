#ifndef CONSOLEINPUTCONCEPT_HPP
#define CONSOLEINPUTCONCEPT_HPP

#include "IConcept.hpp"

namespace concept
{
    class ConsoleInputConcept : public IConcept
    {
    public:
        virtual void run();
    };
}

#endif