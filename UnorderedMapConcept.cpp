#include "UnorderedMapConcept.hpp"

#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;
using namespace concept;

void UnorderedMapConcept::run()
{
    // Slower for key lookup, faster for iteration.
    map<string, int> values;
    // Faster for key lookup, slower for iteration.
    unordered_map<string, int> unordered_values;

    cout << "MapAndUnorderedMapConcept" << endl;
}
