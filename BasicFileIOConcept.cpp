#include "BasicFileIOConcept.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <vector>

using namespace std;
using namespace concept;

class userException : public exception
{
public:
    userException(string message = "An exception was thrown")
        : exception()
        , _message(message)
    {}

    virtual const char* what() const throw()
    {
        return "Could not open file";
    }

private:
    string _message;
};

const string BasicFileIOConcept::file = "test.txt";

void BasicFileIOConcept::run()
{
    incrementReadCount();
    outputFile();
}

void BasicFileIOConcept::outputFile()
{
    cout << "Outputting " << file << "." << endl;
    cout << string(80, '=');
    vector<string> fileLines = readAllLines(file);

    for (auto line : fileLines)
    {
        cout << line << endl;
    }

    cout << string(80, '=') << endl;
    cout << "Counted " << fileLines.size() << " lines." << endl;
}

void BasicFileIOConcept::incrementReadCount()
{
    const string editLineStart = "Times this file has been opened: ";
    vector<string> lines = readAllLines(file);

    // http://www.cplusplus.com/reference/string/string/compare/
    auto strStartsWith = [](string value, string prefix)
    {
        return value.compare(0, prefix.size(), prefix) == 0;
    };

    for (size_t i = 0; i < lines.size(); i++)
    {
        if (!strStartsWith(lines[i], editLineStart))
        {
            continue;
        }

        string line = lines[i];
        cout << "Found line to modify on line " << (i + 1) << endl;
        cout << line << endl;
        cout << endl;

        int numberIndex = editLineStart.length();

        cout << "string(line.begin(), line.begin() + numberIndex) == " << string(line.begin(), line.begin() + numberIndex) << endl;
        cout << "string(line.begin() + numberIndex, line.end()) == " << string(line.begin() + numberIndex, line.end()) << endl;
        cout << endl;

        // http://www.cplusplus.com/reference/string/stoi/
        // stoi == string to int
        int newOpenCount = stoi(string(line.begin() + editLineStart.length(), line.end())) + 1;
        lines[i] = line.replace(line.begin() + editLineStart.length(), line.end(), to_string(newOpenCount));
    }

    ofstream fout(file, ios::out | ios::trunc);
    for (auto it = lines.begin(); it != lines.end() - 1; ++it)
    {
        fout << *it << endl;
    }

    fout << lines.back();
}

vector<string> BasicFileIOConcept::readAllLines(string fileName)
{
    // Don't need to close it myself because ifstream destructor will.
    ifstream fin(file);
    vector<string> lines;

    //if (fin.is_open())
    if (!fin) // prettier
    {
        throw new userException("Could not open test.txt");
    }

    string line;
    while (getline(fin, line))
    {
        lines.push_back(line);
    }

    return lines;
}
