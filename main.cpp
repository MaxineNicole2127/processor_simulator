#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>
#include <vector>
#include "classes/register.h"
#include "classes/func.h"
#include "classes/printing.h"
#include "classes/memory.h"
#include "classes/conversion.h"
#include <bitset>
#include<limits>
using namespace std;

Memory pointToMemory(vector<Memory> cells, int cellNo);

int main() {
    const int byteSize = 4;
    // create an object to access the subfunctions
    Func f;
    Printing pr;

    // create the registers
    Register mnb("mnb", 1);
    Register nic("nic", 2);
    Register ole("ole", 3);
    Register brn("brn", 4);
    Register ale("ale", 5);
    Register ans("ans", 6);
    Register ins("ins", 7);
    Register pct("pct", 0);

    Register registers[] = { pct, ins, mnb, nic, ole, brn, ale, ans};
    size_t noOfRegisters = sizeof(registers)/sizeof(mnb);

    // collect instructions from file and store in memory
    fstream fetch;
    fetch.open("source.in", ios::in);
    
    string instruction;
    int counter = 0;

    vector<Memory> memoryCells;
    
    // convert the instruction to its bits equivalent

    // return later later
    /*
    while(getline(fetch, instruction)) {
        f.clrScr();
        cout << "Collecting instructions from file..." << flush;
        f.pause(1);
        cout << instruction << "\n";
        Memory m(counter * byteSize);
        counter++;
        m.setInstruction(instruction);
        memoryCells.push_back(m);
        f.pause(0.5);
        pr.printMemoryCells(memoryCells);
        
        cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
        //f.pause(1);
    }  
    */

    while(getline(fetch, instruction)) {
        Memory m(counter * byteSize);
        counter++;
        m.setInstruction(instruction, false);
        memoryCells.push_back(m);
    }

    // show all program to 0
    f.clrScr();
    
    pr.printMemoryCells(memoryCells);
    pr.printAllRegisters(registers, noOfRegisters);

    // set program counter to 0
    pct.setRegData(0); pct.displayContent();

    // look for the memory cell
    
    Memory memory_with_instruction = pointToMemory(memoryCells, pct.getRegData());
    memory_with_instruction.displayContent();
    
    

    
}

Memory pointToMemory(vector<Memory> cells, int cellNo) {
    size_t noOfCells = cells.size();
    Memory m = cells.at(0);
    for(int i = 0; i < noOfCells; i++) {
        Memory m = cells.at(i);
        if(m.getMemoryNo() == cellNo) {
            return m;
        }
    }
    return m;
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


// while(getline(fetch, instruction)) {
    //     cout << "\n\n#" << counter << endl << endl;
    //     // f.clrScr();
    //     Memory m(counter * byteSize);
    //     counter++;
    //     m.setInstruction(instruction);
    //     memoryCells.push_back(m);
        
    // }