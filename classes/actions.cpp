#include <iostream>
#include "actions.h"
using namespace std;

void Actions::printAllRegisters(map<int, int> regs, pair<int, string> IR, int regChanged) {
    map<int, int>::iterator it = regs.begin();

    cout << "\n    REGISTERS: " << endl << endl;
    int counter = 0;
    while (it != regs.end()) { // print content of the registers (except the instruction register)
        int key = it->first;
        int value = it->second;
        if(regChanged == -20)
            cout << "\t" << registerName(key) << " : " << (f.toHex(value)) << " ("<< value << ") " << endl;
        else
            if(key == regChanged)
                cout << "    --> " << registerName(key) << " : " << (f.toHex(value)) << " ("<< value << ") " << endl;
            else 
                cout << "\t" << registerName(key) << " : " << (f.toHex(value)) << " ("<< value << ") " << endl;

        ++it;
    }

    // instruction register
    int key = IR.first;
    string value = IR.second;
    cout << "\t" << registerName(key) << " : " << value << endl;
}

string Actions::registerName(int n) { // returns the instruction name with registerNo of n
    switch(n) {
    case 0:
        return "pct";
        break;
    case 1:
        return "mnb";
        break;
    case 2:
        return "nic";
        break;
    case 3:
        return "ole";
        break;
    case 4:
        return "ale";
        break;
    case 5:
        return "brn";
        break;
    case 6:
        return "ans";
        break;
    case 7:
        return "ins";
        break;
    }
    return "ooo";
}

void Actions::printMemoryCells(vector<Memory> mc) { // prints the memory cells and their contents
    cout << "\n    MEMORY CELLS: " << endl << endl;
    for(Memory m : mc) {
        cout << "\t";
        m.printMemory();
    }
}


Memory *Actions::pointToMemory(vector<Memory> *cells, int memoryNo) {
    size_t noOfCells = cells->size();
    Memory m = cells->at(0);
    for(int i = 0; i < noOfCells; i++) {
        Memory *m = &((*cells)[i]);
        if(m->getMemoryNo() == memoryNo) {
            return m;
        }
    }
    return nullptr;
}



void Actions::displayAllRegisters(map<int, int> regs, pair<int, string> IR ) {
    map<int, int>::iterator it = regs.begin();

    cout << "\n    REGISTERS: " << endl << endl;
    int counter = 0;
    while (it != regs.end()) { // print content of the registers (except the instruction register)
        int key = it->first;
        int value = it->second;

        string hexData = f.toHex(value);
        string numData = to_string(value);
        int len = hexData.length() + numData.length();

        for(int i = 0; i < 5; i++) {
            if(i == 0 || i == 4) {
                for(int j = 0; j < len*2; j++)
                    cout << "-";
            } else if(i == 1 || i == 3) {
                cout << "|";
                for(int space = 0; space < len*2; space++)
                    cout << " ";
                cout << "|";
            } else {
                cout << "| " << (f.toHex(value)) << " ("<< value << ") " << " |";
            }
            cout << endl;
        }

        ++it;
    }

    int key = IR.first;
    string value = IR.second;
    
    int len = value.length();

    for(int i = 0; i < 5; i++) {
        if(i == 0 || i == 4) {
            for(int j = 0; j < len*2; j++)
                cout << "-";
        } else if(i == 1 || i == 3) {
            cout << "|";
            for(int space = 0; space < len*2; space++)
                cout << " ";
            cout << "|";
        } else {
            cout << "| " << value << " |";
        }
        cout << endl;
    }

}