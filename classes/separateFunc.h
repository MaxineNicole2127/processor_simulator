#ifndef SEPARATEFUNC_H
#define SEPARATEFUNC_H

#include <string>
#include <vector>
using namespace std;

class SeparateFunc {
public:
    string toHex(int num);
    string removeComma(string str);
    vector<string> strToVector(string toSeparate);
};

#endif