#ifndef BASICFILEIOCONCEPT_HPP
#define BASICFILEIOCONCEPT_HPP

#include "IConcept.hpp"

#include <string>
#include <vector>

namespace concept
{
    class BasicFileIOConcept : public IConcept
    {
    public:
        virtual void run();

    private:
        void outputFile();
        void incrementReadCount();

        std::vector<std::string> readAllLines(std::string fileName);

        static const std::string file;
    };
}

#endif