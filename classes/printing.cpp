#include "printing.h"
#include <iostream>
#include <ctime>
using namespace std;

void Printing::printAllRegisters(Register registers[], int noOfRegisters) {
    cout << "REGISTERS: " << endl;
    for(int i = 0; i < noOfRegisters; i++) {
        registers[i].printRegister();
    }
}

void Printing::printMemoryCells(vector<Memory> mc) {
    for(Memory m : mc) {
        m.printMemory();
    }
}