#ifndef ACTIONS_H
#define ACTIONS_H

#include <map>
#include <vector>
#include "func.h"
#include "memory.h"
using namespace std;

class Actions {
public:
    Func f;
    void printAllRegisters(map<int, int> regs, pair<int, string> IR, int regChanged = -20);
    void displayAllRegisters(map<int, int> regs, pair<int, string> IR );
    void printMemoryCells(vector<Memory> mc);
    string registerName(int n);
    Memory *pointToMemory(vector<Memory> *cells, int memoryNo);
};






#endif