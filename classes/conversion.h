#ifndef CONVERSION_H
#define CONVERSION_H

#include <string>
using namespace std;


class Conversion {
public:
    string instructionToOpCode(string instruction);
    int binaryToDec(string bin);
    string decToBinary(int n, bool isData = true);
    string negativeToHex(int n);
    string toHex(int n);
    string registerToBinCode(string regName);
};

#endif