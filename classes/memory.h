#ifndef MEMORY_H
#define MEMORY_H
#include <iostream>
#include <vector>
#include "func.h"
#include "conversion.h"
using namespace std;

class Memory {
private:
    Func f;
    Conversion c;
    int memoryNo;
    string memoryHex;
    string instruction;
    string opCode;
    vector<string> arguments;
    vector<string> arguments_bin;
    size_t noOfArguments;
    int opCodeDecimal;
    string bitsInstruction;
    void displayContent();
public:
    Memory(int memoryNo);
    void displayMemory();
    void printMemory();
    void setInstruction(string instruction);
    void convertToBits();
};

#endif