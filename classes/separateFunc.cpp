#include "separateFunc.h"
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

string SeparateFunc::toHex(int n){
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

string SeparateFunc::removeComma(string str) {
    size_t len = str.length();
    if(str[len - 1] == ',') {
        str = str.substr(0, len - 1);
    }
    return str;
}

vector<string> SeparateFunc::strToVector(string toSeparate) {
    vector<string> v;
    stringstream stream(toSeparate);
    string str;
    while(getline(stream, str, ' ')) {
        str = removeComma(str);
        v.push_back(str);
        
    }
    return v;
}