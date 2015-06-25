#ifndef CONSOLEINPUT_HPP
#define CONSOLEINPUT_HPP

#include "IConcept.hpp"

namespace concept
{
    class ConsoleInput :  public IConcept
    {
        virtual void Run();
    };
}

#endif