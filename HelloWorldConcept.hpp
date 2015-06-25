#ifndef HELLO_WORLD_CONCEPT_HPP
#define HELLO_WORLD_CONCEPT_HPP

#include "IConcept.hpp"

namespace concept
{
    class HelloWorldConcept : public IConcept
    {
    public:
        virtual void Run();
    };
}

#endif