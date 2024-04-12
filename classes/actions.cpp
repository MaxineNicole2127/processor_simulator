#include <iostream>
#include "actions.h"
using namespace std;

void Actions::printAllRegisters(map<int, int> regs, pair<int, string> IR ) {
    map<int, int>::iterator it = regs.begin();

    cout << "\nREGISTERS: " << endl << endl;
    int counter = 0;
    while (it != regs.end()) { // print content of the registers (except the instruction register)
        int key = it->first;
        int value = it->second;
        cout << "\t" << registerName(key) << " : " << (f.toHex(value)) << " ("<< value << ") " << endl;
        ++it;
    }

    // instruction register
    int key = IR.first;
    string value = IR.second;
    cout << "\t" << registerName(key) << " : " << value << endl;
}

string Actions::registerName(int n) {
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

void Actions::printMemoryCells(vector<Memory> mc) {
    cout << "MEMORY CELLS: " << endl << endl;
    for(Memory m : mc) {
        cout << "\t";
        m.printMemory();
    }
}

void Actions::mockPrintRegisters(map<int, int> regs, pair<int, string> IR ) {
    map<int, int>::iterator it = regs.begin();

    cout << "\nREGISTERS: " << endl << endl;
    int counter = 0;
    while (it != regs.end()) { // print content of the registers (except the instruction register)
        int key = it->first;
        int value = it->second;
        cout << "\t" << registerName(key) << " : " << value << endl;
        ++it;
    }

    // instruction register
    int key = IR.first;
    string value = IR.second;
    cout << "\t" << registerName(key) << " : " << value << endl;
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



