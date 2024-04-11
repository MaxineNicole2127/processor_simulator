#include "conversion.h"
#include <iostream>
#include <string>
#include <bitset>
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
    else if(regName == "ins") 
        return "0111";
    return "0000";
}


int Conversion::binaryToDec(string bin) {
    int dec = stoi(bin, nullptr, 2); // dec = 13
    return dec;
}

string Conversion::decToBinary(int n) {
    string sign = "0";   // 0 if positive, 1 if negative
    if(n < 0) {
        sign = "1";
    }
    string binary = std::bitset<11>(10).to_string();
    return sign + binary;
}