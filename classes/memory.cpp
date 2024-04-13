#include "memory.h"
#include <iostream>
#include "func.h"
#include <vector>
#include <string>
using namespace std;



Memory::Memory(int memoryNo) { // constructor
    this->memoryNo = memoryNo;
    this->memoryHex = f.toHex(memoryNo);
}
/*
void Memory::displayMemory() {
    
    cout << "    " <<  " * * * * * * * * * *" << endl;
    cout << "    " <<  " *                 *" << endl;
    cout << memoryHex <<"  *                 *" << endl;
    cout << "    " <<  " *                 *" << endl;
    cout << "    " <<  " * * * * * * * * * *" << endl;
}
*/

void Memory::printMemory() { // prints the contents of the memory
    cout << memoryHex << ": " << bitsInstruction << endl;
}

void Memory::setInstruction(string instruction, bool display) { // sets the instruction in the memory
    this->instruction = instruction;
    this->convertToBits(); // converts the instruction to its bits equivalent
    if(display) this->displayContent();
}


void Memory::convertToBits() {
    arguments = f.strToVector(this->instruction);

    // convert instruction to operation code (ex. INIT --> 0000)
    this->opCode = c.instructionToOpCode(arguments.at(0));
    arguments.erase(arguments.begin());
    this->noOfArguments = arguments.size();

    // converts OPCode to decimal for easier use of switch case
    this->opCodeDecimal = c.binaryToDec(this->opCode);
    
    // decide what to do with the arguments depending on the OPCode
    //size_t len = arguments.size();
    switch(opCodeDecimal) {
    case 0: // INIT <register>
        arguments_bin.push_back(c.registerToBinCode(arguments.at(0)));
        break;
    case 1: // FILL <register>, <data>
        arguments_bin.push_back(c.registerToBinCode(arguments.at(0)));
        arguments_bin.push_back(c.decToBinary(stoi(arguments.at(1))));
        break;
    case 2: // MOVE <register>, <register>
        arguments_bin.push_back(c.registerToBinCode(arguments.at(0)));
        arguments_bin.push_back(c.registerToBinCode(arguments.at(1)));
        break;
    case 3: // ADDT <register>, <register>
        arguments_bin.push_back(c.registerToBinCode(arguments.at(0)));
        arguments_bin.push_back(c.registerToBinCode(arguments.at(1)));
        break;
    case 4: // ADDS <operandReg1>, <operandReg2>, <destinationRegister>
        arguments_bin.push_back(c.registerToBinCode(arguments.at(0)));
        arguments_bin.push_back(c.registerToBinCode(arguments.at(1)));
        arguments_bin.push_back(c.registerToBinCode(arguments.at(2)));
        break;
    case 5: // SUBT <register to subtract from>, <data>
        arguments_bin.push_back(c.registerToBinCode(arguments.at(0)));
        arguments_bin.push_back(c.registerToBinCode(arguments.at(1)));
        break;
    case 6: // SUBS <minuendReg>, <subtrahendReg>, <destinationRegister>
        arguments_bin.push_back(c.registerToBinCode(arguments.at(0)));
        arguments_bin.push_back(c.registerToBinCode(arguments.at(1)));
        arguments_bin.push_back(c.registerToBinCode(arguments.at(2)));
        break;
    case 7: // POWT <register>  or  POWT <register>, <destinationRegister>
        if(noOfArguments == 1) {
            arguments_bin.push_back(c.registerToBinCode(arguments.at(0)));
        } else {
            arguments_bin.push_back(c.registerToBinCode(arguments.at(0)));
            arguments_bin.push_back(c.registerToBinCode(arguments.at(1)));
        }
        break;
    case 8: // SQRT <register>  or  SQRT <register>, <destinationRegister>
        if(noOfArguments == 1) {
            arguments_bin.push_back(c.registerToBinCode(arguments.at(0)));
        } else {
            arguments_bin.push_back(c.registerToBinCode(arguments.at(0)));
            arguments_bin.push_back(c.registerToBinCode(arguments.at(1)));
        }
        break;
    }

    // formulate the instruction in bits
    this->bitsInstruction = opCode;

    for(size_t i = 0; i < noOfArguments; i++) {
        this->bitsInstruction += arguments_bin.at(i);
    }
}

void Memory::displayContent() { //displays content of memory for visual purposes
    cout << "\n\tInstruction: " << instruction << endl;
    cout << "\tOPCode: " << this->opCode << "(" << opCodeDecimal << ")" << endl;
    cout << "\tArguments: ";

    for(size_t i = 0; i < noOfArguments; i++) {
        cout << arguments_bin.at(i) << "(" << arguments.at(i) << ") ";
    }

    cout << "\n\n\tBITS INSTRUCTION: " << bitsInstruction << endl << endl;
}

string Memory::getBitsInstruction() {
    return this->bitsInstruction;
}

int Memory::getMemoryNo() {
    return this->memoryNo;
}
