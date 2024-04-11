#ifndef REGISTER_H
#define REGISTER_H
#include <iostream>
using namespace std;

class Register {
private:
    string regName;
    int data;
    string hexadecimal; 
public:
    Register(string regName);
    void displayRegister();
    void printRegister();
};

#endif