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
public:
    // getter
    string getBitsInstruction();
    int getMemoryNo(); 

    void displayContent();
    Memory(int memoryNo);
    void displayMemory();
    void printMemory();
    void setInstruction(string instruction, bool display = true);
    void convertToBits();
};

#endif