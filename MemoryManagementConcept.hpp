#ifndef MEMORYMANAGEMENTCONCEPT_HPP
#define MEMORYMANAGEMENTCONCEPT_HPP

#include "IConcept.hpp"

#include <string>

namespace concept
{
    class MemoryManagementConcept : public IConcept
    {
    public:
        virtual void run();

    private:
        class Object
        {
        public:
            Object(int nestLevel);
            ~Object();

            int nestLevel() const;

        private:
            int _nestLevel;
        };

    private:
        void uniqueSmartPointer();
        void sharedSmartPointer();
        void weakSmartPointer();

        void outputObject(Object* const value, int nestLevel) const;

        static void output(std::string message, int indentLevel);

        static const char INDENT;
        static const int INDENT_SIZE;
    };
}

#endif
