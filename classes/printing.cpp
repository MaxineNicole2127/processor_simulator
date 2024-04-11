#include "printing.h"
#include <iostream>
#include <ctime>
using namespace std;

void Printing::printAllRegisters(Register registers[], int noOfRegisters) {
    cout << "\nREGISTERS: " << endl << endl;
    for(int i = 0; i < noOfRegisters; i++) {
        cout << "\t";
        registers[i].printRegister();
    }

}

void Printing::printMemoryCells(vector<Memory> mc) {
    cout << "\nMEMORY CELLS: " << endl << endl;
    for(Memory m : mc) {
        cout << "\t";
        m.printMemory();
    }
}