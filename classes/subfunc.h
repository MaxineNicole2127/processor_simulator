#ifndef SUBFUNC_F
#define SUBFUNC_F
#include "register.h"
#include "memory.h"
#include <vector>
using namespace std;

class SubFunc {
public:
    void pause(float n);
    void clrScr();
    void displayAllRegisters(Register registers[], int noOfRegisters);
    void printAllRegisters(Register registers[], int noOfRegisters);
    void printMemoryCells(vector<Memory> mc);
};

#endif