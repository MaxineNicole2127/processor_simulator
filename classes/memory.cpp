#include "memory.h"
#include <iostream>
#include "func.h"
#include <vector>
#include <string>
using namespace std;


Memory::Memory(int memoryNo) {
    this->memoryNo = memoryNo;
    this->memoryHex = f.toHex(memoryNo);
}
void Memory::displayMemory() {
    
    cout << "    " <<  " * * * * * * * * * *" << endl;
    cout << "    " <<  " *                 *" << endl;
    cout << memoryHex <<"  *                 *" << endl;
    cout << "    " <<  " *                 *" << endl;
    cout << "    " <<  " * * * * * * * * * *" << endl;
}

void Memory::printMemory() {
    cout << memoryHex << ": " << instruction << endl;
}

void Memory::setInstruction(string instruction) {
    this->instruction = instruction;
    this->convertToBits();
    cout << "opCode: " << this->opCode << endl;
    cout << "arguments: ";
    for(string s: arguments) {
        cout << s << "" ;
    }

}

void Memory::convertToBits() {
    arguments = f.strToVector(this->instruction);
    this->opCode = c.instructionToOpCode(arguments.at(0));
    arguments.erase(arguments.begin());

}