#include <iostream>
#include "decoder.h"
#include <string>
using namespace std;

Decoder::Decoder() {
    this->instructionString = "";
}

void Decoder::setInstructionString(string instruction){
    this->instructionString = instruction;
}

string Decoder::getInstructionString() {
    return instructionString;
}

void Decoder::organize() {
    // take the opcode first
    this->opCode = instructionString.substr(0, 4);
    this->opCode_Decimal = c.binaryToDec(opCode);
    string argumentStr = instructionString.substr(4, instructionString.length() - 4);
    fillArguments(opCode_Decimal, argumentStr);
}

void Decoder::displayContents() {
    cout << "\n\n  Instruction: " << instructionString << "\n";
    cout << "  OPCODE: " << opCode << "\n";
    cout << "  OPCODE-Decimal: " << opCode_Decimal << "\n";
    //cout << "ArgumentStr: " << argumentStr << "\n";
    //fillArguments(opCode_Decimal, argumentStr);
    cout << "  Arguments: ";
    for(string arg: arguments) 
        cout << "   " << arg << "  ";
}

void Decoder::fillArguments(int opCodeDecimal, string argumentStr) {
    string argStr = argumentStr;
    string current = "";

    switch(opCodeDecimal) {
    case 0: // INIT <4-bit register>
        current = argStr.substr(0, 4);  // take 4 bits from the argumentStr
        arguments.push_back(current);
        break;
    case 1: // FILL <4-bit register> <12-bit number>
        current = argStr.substr(0, 4);  // take 4 bits from the argumentStr
        arguments.push_back(current);
        argStr = argStr.substr(4, argStr.length() - 4);
        current = argStr.substr(0, 12);  // take 12 bits from the argumentStr
        arguments.push_back(current);
        
        break;
    case 2: // MOVE <4-bit register> <4-bit register>
        current = argStr.substr(0, 4);  // take 4 bits from the argumentStr
        arguments.push_back(current);
        argStr = argStr.substr(4, argStr.length() - 4);
        current = argStr.substr(0, 4);  // take 4 bits from the argumentStr
        arguments.push_back(current);
        
        break;
    case 3: // ADDT <4-bit register> <4-bit register>
        current = argStr.substr(0, 4);  // take 4 bits from the argumentStr
        arguments.push_back(current);
        argStr = argStr.substr(4, argStr.length() - 4);
        current = argStr.substr(0, 4);  // take 4 bits from the argumentStr
        arguments.push_back(current);
        
        break;
    case 4: // ADDS <4-bit register> <4-bit register> <4-bit register>
        current = argStr.substr(0, 4);  // take 4 bits from the argumentStr
        arguments.push_back(current);
        argStr = argStr.substr(4, argStr.length() - 4);
        current = argStr.substr(0, 4);  // take 4 bits from the argumentStr
        arguments.push_back(current);
        argStr = argStr.substr(4, argStr.length() - 4);
        current = argStr.substr(0, 4);  // take 4 bits from the argumentStr
        arguments.push_back(current);
        
        break;
    case 5: // SUBT <4-bit register> <4-bit register>
        current = argStr.substr(0, 4);  // take 4 bits from the argumentStr
        arguments.push_back(current);
        argStr = argStr.substr(4, argStr.length() - 4);
        current = argStr.substr(0, 4);  // take 4 bits from the argumentStr
        arguments.push_back(current);
        
        break;
    case 6: // SUBS <4-bit register> <4-bit register> <4-bit register>
        current = argStr.substr(0, 4);  // take 4 bits from the argumentStr
        arguments.push_back(current);
        argStr = argStr.substr(4, argStr.length() - 4);
        current = argStr.substr(0, 4);  // take 4 bits from the argumentStr
        arguments.push_back(current);
        argStr = argStr.substr(4, argStr.length() - 4);
        current = argStr.substr(0, 4);  // take 4 bits from the argumentStr
        arguments.push_back(current);
        
        break;
    case 7:  
        if(argStr.length() == 4){ // POWT <4-bit register>
            current = argStr.substr(0, 4);  // take 4 bits from the argumentStr
            arguments.push_back(current);
        } else { // POWT <4-bit register> <4-bit register>
            current = argStr.substr(0, 4);  // take 4 bits from the argumentStr
            arguments.push_back(current);
            argStr = argStr.substr(4, argStr.length() - 4);
            current = argStr.substr(0, 4);  // take 4 bits from the argumentStr
            arguments.push_back(current);
        }
        break;
    case 8:  
        if(argStr.length() == 4){ // SQRT <4-bit register>
            current = argStr.substr(0, 4);  // take 4 bits from the argumentStr
            arguments.push_back(current);
        } else { // SQRT <4-bit register> <4-bit register>
            current = argStr.substr(0, 4);  // take 4 bits from the argumentStr
            arguments.push_back(current);
            argStr = argStr.substr(4, argStr.length() - 4);
            current = argStr.substr(0, 4);  // take 4 bits from the argumentStr
            arguments.push_back(current);
        }
        break;
    }
}

int Decoder::getOPCode_Dec() {
    return this->opCode_Decimal;
}

vector<string> Decoder::getArguments() {
    return this->arguments;
}

vector<int> Decoder::getArguments_Dec() {
   for(string s: arguments) {
        argumentsDec.push_back(c.binaryToDec(s));
   }
   return argumentsDec;
}
/********************************
    0000 - INIT - 0
    0001 - FILL - 1
    0010 - MOVE - 2
    0011 - ADDT - 3
    0100 - ADDS - 4
    0101 - SUBT - 5
    0110 - SUBS - 6
    0111 - POWT - 7
    1000 - SQRT - 8
********************************/