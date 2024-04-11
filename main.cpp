#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>
#include <vector>
#include "classes/register.h"
#include "classes/subfunc.h"
#include "classes/memory.h"
using namespace std;


int main() {
    const int byteSize = 4;
    // create an object to access the subfunctions
    SubFunc f;

    // create the registers
    Register mnb("mnb");
    Register nic("nic");
    Register ole("ole");
    Register brn("brn");
    Register ale("ale");
    Register ans("ans");
    Register pcr("pcr");

    Register registers[7] = { pcr, mnb, nic, ole, brn, ale, ans};
    size_t noOfRegisters = sizeof(registers)/sizeof(mnb);

    // collect instructions from file and store in memory
    fstream fetch;
    fetch.open("source.in", ios::in);
    
    string instruction;
    int counter = 0;

    vector<Memory> memoryCells;

    while(getline(fetch, instruction)) {
        f.clrScr();
        Memory m(counter * byteSize);
        counter++;
        m.setInstruction(instruction);
        memoryCells.push_back(m);
        
    }
    

    
}



/*
while(getline(fetch, instruction)) {
    f.clrScr();
    Memory m(counter * byteSize);
    counter++;
    m.setInstruction(instruction);
    memoryCells.push_back(m);
    cout << "Collecting instructions from file...";
    cout << instruction << "\n";
    f.printMemoryCells(memoryCells);
    f.pause(1);
}


*/