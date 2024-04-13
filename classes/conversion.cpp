#include "conversion.h"
#include <iostream>
#include <string>
#include <bitset>
#include <cmath>
using namespace std;

/********************************
    0000 - INIT
    0001 - FILL
    0010 - MOVE
    0011 - ADDT
    0100 - ADDS
    0101 - SUBT
    0110 - SUBS
    0111 - POWT
    1000 - SQRT
********************************/

// returns equivalent binary number of a keyword
string Conversion::instructionToOpCode(string instruction) {
    if(instruction == "INIT")
        return "0000";
    else if(instruction == "FILL") 
        return "0001";
    else if(instruction == "MOVE") 
        return "0010";
    else if(instruction == "ADDT") 
        return "0011";
    else if(instruction == "ADDS") 
        return "0100";
    else if(instruction == "SUBT") 
        return "0101";
    else if(instruction == "SUBS") 
        return "0110";
    else if(instruction == "POWT") 
        return "0111";
    else if(instruction == "SQRT") 
        return "1000";
    return "0000";
}

/********************
0001- mnb
0010- nic
0011- ole
0100- ale
0101- brn
0110- ans
0000- pct
*****************/

// returns equivalent binary number of a register
string Conversion::registerToBinCode(string regName) {
    if(regName == "mnb")
        return "0001";
    else if(regName == "nic") 
        return "0010";
    else if(regName == "ole") 
        return "0011";
    else if(regName == "ale") 
        return "0100";
    else if(regName == "brn") 
        return "0101";
    else if(regName == "ans") 
        return "0110";
    else if(regName == "pct") 
        return "0000";
    return "0000";
}


int Conversion::binaryToDec(string bin) { // returns decimal equivalent of a binary number
    if(bin.length() == 12) { // handles data input 
        int sign = 1;
        if(bin[0] == '1') { // first bit is the sign indicator
            sign = -1;
        }
        bin = bin.substr(1, 11); // next 11 bits will be the numerical data itself
        int dec = stoi(bin, nullptr, 2);
        return dec * sign;
    } else { 
        int dec = stoi(bin, nullptr, 2); // dec = 13
        return dec;
    }
}


string Conversion::decToBinary(int n, bool isData) { // returns binary equivalent of a decimal number
    string sign = "0";   // 0 if positive, 1 if negative
    string binary = "";
    if(isData) { 
        if(n < 0) {
            sign = "1";
            binary = std::bitset<11>(abs(n)).to_string();
        } else {
            binary = std::bitset<11>(n).to_string();
        }
        return sign + binary;
    } else {
        binary = std::bitset<16>(n).to_string();
    }
    return binary;
}


string Conversion::negativeToHex(int n) { // return hexadecimal equivalent of a negative decimal number
    /***********************************
    1 Absolute value
    2 Get binary equivalent (16-bits)
    3 Negate the value
    4 Convert to decimal
    5 Add 1 to decimal
    6 Convert to hex
    ***********************************/
    int num = abs(n);
    string bin = decToBinary(num, false);
    
    for(int i = 0; i < bin.length(); i++) {
        bin[i] = (bin[i] == '0') ? '1' : '0';
    }
    
    int decimal = binaryToDec(bin);
    decimal += 1;
    
    string hexEquiv = toHex(decimal);
    return hexEquiv;
    
}

string Conversion::toHex(int n){ // return hexadecimal equivalent of a decimal number
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
