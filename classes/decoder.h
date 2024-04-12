#ifndef DECODER_H
#define DECODER_H

#include <string>
#include "conversion.h"
#include <vector>
using namespace std;

class Decoder {
private:
    Conversion c;
    string instructionString;
    string opCode;
    int opCode_Decimal;
    vector<string> arguments;
    vector<int> argumentsDec;
public:
    Decoder();

    // getter
    int getOPCode_Dec();
    vector<string> getArguments();
    vector<int> getArguments_Dec();
    void setInstructionString(string instruction);
    string getInstructionString();
    void organize();
    void displayContents();
    void fillArguments(int opCodeDecimal, string argumentStr);
};

#endif