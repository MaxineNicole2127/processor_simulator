#include <iostream>
#include "func.h"
#include <map>
#include <vector>
#include <ctime>
#include <limits>
#include <sstream>
using namespace std;


string Func::toHex(int n){
    // ans string to store hexadecimal number
    string ans = "";
    if(n == 0) {
        char ch = 48;
        ans += ch;
    }
    while (n != 0) {
        int rem = 0; 
        char ch;
        rem = n % 16;
        if (rem < 10) 
            ch = rem + 48;
        else 
            ch = rem + 55;
         
        ans += ch;
        n = n / 16;
    }
     
    int i = 0, j = ans.size() - 1;
    while(i <= j){
      swap(ans[i], ans[j]);
      i++;
      j--;
    }

    
    return ans.length() == 1 ? "0x0" + ans : "0x" + ans;
}


void Func::pause(float n){
    n *= CLOCKS_PER_SEC;
    clock_t now{clock()};
    while(clock() - now < n);
}
void Func::clrScr() {
    cout << "\033[2J\033[1;1H";
}

string Func::removeComma(string str) {
    size_t len = str.length();
    if(str[len - 1] == ',') {
        str = str.substr(0, len - 1);
    }
    return str;
}

vector<string> Func::strToVector(string toSeparate) {
    vector<string> v;
    stringstream stream(toSeparate);
    string str;
    while(getline(stream, str, ' ')) {
        str = removeComma(str);
        v.push_back(str);
        
    }
    return v;
}

void Func::promptEnter() {
    cout << "\n\n\n\t[PRESS ENTER..]";
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
}