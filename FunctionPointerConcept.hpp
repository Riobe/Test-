#ifndef FUNCTIONPOINTERCONCEPT_HPP
#define FUNCTIONPOINTERCONCEPT_HPP

#include "IConcept.hpp"

#include <string>

namespace concept
{
    class FunctionPointerConcept : public IConcept
    {
    public:
        virtual void run();

    private:
        static void staticMemberFunction(std::string message);

        void instanceMemberFunction(std::string message);

        void outputNonInstanceFunc(void(*func)(std::string), std::string message);
        void outputInstanceFunc(void(FunctionPointerConcept::*func)(std::string), std::string message);
    };
}

#endif
