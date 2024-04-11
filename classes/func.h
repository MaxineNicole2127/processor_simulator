#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Func {
public:
    void pause(float n);
    void clrScr();
    string toHex(int num);
    string removeComma(string str);
    vector<string> strToVector(string toSeparate);
};

#endif