#ifndef FUNC_H
#define FUNC_H

#include <vector>
#include <map>
using namespace std;


class Func {
public:
    string toHex(int n);
    void pause(float n);
    void clrScr();
    string removeComma(string str);
    vector<string> strToVector(string toSeparate);
    void promptEnter();
};

#endif