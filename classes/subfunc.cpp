#include "subfunc.h"
#include <iostream>
#include <ctime>
using namespace std;

void SubFunc::pause(float n){
    n *= CLOCKS_PER_SEC;
    clock_t now{clock()};
    while(clock() - now < n);
}
void SubFunc::clrScr() {
    cout << "\033[2J\033[1;1H";
}

void SubFunc::displayAllRegisters(Register registers[], int noOfRegisters) {
    cout << "REGISTERS: " << endl;
    for(int i = 0; i < noOfRegisters; i++) {
        registers[i].displayRegister();
    }
}

void SubFunc::printAllRegisters(Register registers[], int noOfRegisters) {
    cout << "REGISTERS: " << endl;
    for(int i = 0; i < noOfRegisters; i++) {
        registers[i].printRegister();
    }
}

void SubFunc::printMemoryCells(vector<Memory> mc) {
    for(Memory m : mc) {
        m.printMemory();
    }
}