#include "printing.h"
#include <iostream>
#include <ctime>
using namespace std;

void Printing::printAllRegisters(Register registers[], int noOfRegisters) {
    cout << "REGISTERS: " << endl;
    for(int i = 0; i < noOfRegisters; i++) {
        registers[i].printRegister();
    }

    for(Register r : registers) {
        cout << "\t";
        m.printMemory();
    }
}

void Printing::printMemoryCells(vector<Memory> mc) {
    cout << "MEMORY CELLS: " << endl << endl;
    for(Memory m : mc) {
        cout << "\t";
        m.printMemory();
    }
}