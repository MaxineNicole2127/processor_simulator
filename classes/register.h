#ifndef REGISTER_H
#define REGISTER_H
#include <iostream>
#include "conversion.h"
#include "func.h"
using namespace std;

class Register {
private:
    Conversion c;
    Func f;
    int regNo;
    string regName;
    int data;
    string hexData; 
    bool isINS;
public:
    Register(string regName, int regNo);
    void setRegData(int data);
    int getRegData();
    void displayRegister();
    void printRegister();
    void displayContent();
};

#endif