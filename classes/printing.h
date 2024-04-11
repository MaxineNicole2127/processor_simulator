#ifndef PRINTING_F
#define PRINTING_F
#include "register.h"
#include "memory.h"
#include <vector>
using namespace std;

class Printing {
public:
    void displayAllRegisters(Register registers[], int noOfRegisters);
    void printAllRegisters(Register registers[], int noOfRegisters);
    void printMemoryCells(vector<Memory> mc);
};

#endif