#include <iostream>
#include "func.h"
#include "conversion.h"
#include <map>
#include <vector>
#include <ctime>
#include <limits>
#include <sstream>
using namespace std;


string Func::toHex(int n){
    Conversion c;
    string hex = "";
    if(n >= 0) {
        hex = c.toHex(n);
    } else {
        hex = c.negativeToHex(n);
    }

    return hex;
}


void Func::pause(float n){ // pauses program for n seconds
    n *= CLOCKS_PER_SEC;
    clock_t now{clock()};
    while(clock() - now < n);
}
void Func::clrScr() { // clears the screen
    cout << "\033[2J\033[1;1H";
}

string Func::removeComma(string str) { // removes comma
    size_t len = str.length();
    if(str[len - 1] == ',') {
        str = str.substr(0, len - 1);
    }
    return str;
}

vector<string> Func::strToVector(string toSeparate) { // takes a string and returns a vector of strings without the comma
    vector<string> v;
    stringstream stream(toSeparate);
    string str;
    while(getline(stream, str, ' ')) {
        str = removeComma(str);
        v.push_back(str);
        
    }
    return v;
}

void Func::promptEnter() { // prompts user to press enter to proceed
    cout << "\n\n\n\t[PRESS ENTER..]";
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
}