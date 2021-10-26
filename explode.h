#ifndef EXPLODE_H_INCLUDED
#define EXPLODE_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <utility>

using namespace std;

vector<string> explode(string const & s, char delim)
{
    vector<string> result;
    istringstream iss(s);

    for (string token; getline(iss, token, delim); )
    {
        result.push_back(move(token));
    }

    return result;
}

#endif // EXPLODE_H_INCLUDED
