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


int main() {
    const int byteSize = 4;
    // create an object to access the subfunctions
    Func f;
    Printing pr;

    // create the registers
    Register mnb("mnb");
    Register nic("nic");
    Register ole("ole");
    Register brn("brn");
    Register ale("ale");
    Register ans("ans");
    Register pct("pct");

    Register registers[7] = { pct, mnb, nic, ole, brn, ale, ans};
    size_t noOfRegisters = sizeof(registers)/sizeof(mnb);

    // collect instructions from file and store in memory
    fstream fetch;
    fetch.open("source.in", ios::in);
    
    string instruction;
    int counter = 0;

    vector<Memory> memoryCells;
    
    // convert the instruction to its bits equivalent
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

    f.clrScr();
    pr.printMemoryCells(memoryCells);

    // set program counter to 0
    pr.printReg



    
    

    
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