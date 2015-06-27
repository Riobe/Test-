#include "UnorderedMapConcept.hpp"

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
using namespace concept;

void UnorderedMapConcept::run()
{
    // map - Slower for key lookup, faster for iteration.
    // unordered_map - Faster for key lookup, slower for iteration.
    unordered_map<string, int> grades;
    grades["Jeremy"] = 72;

    cout << "grades[\"Jeremy\"] = 72;" << endl;
    cout << "grades[\"Jeremy\"] == " << grades["Jeremy"] << endl;

    cout << endl;
    cout << "grades.size() == " << grades.size() << endl;
    
    cout << endl;
    cout << "Checking if key \"Joel\" exists" << endl;
    cout << "grades.count(\"Joel\") == " << grades.count("Joel") << endl;
    
    cout << endl;
    cout << "Checking if key \"Jeremy\" exists" << endl;
    cout << "grades.count(\"Jeremy\") == " << grades.count("Jeremy") << endl;

    cout << endl;
    grades.clear();
    cout << "grades.clear()" << endl;
    cout << "grades.size() == " << grades.size() << endl;
}
