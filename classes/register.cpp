#include "register.h"
#include "conversion.h"
#include "func.h"
#include <iostream>
using namespace std;


Register::Register(string regName, int regNo) {
    this->regName = regName;
    this->regNo = regNo;
    this->isINS = (regNo == 7) ? true: false;
}
void Register::displayRegister() {
 
    cout << "    " <<  " * * * * * * * * * *" << endl;
    cout << "    " <<  " *                 *" << endl;
    cout << this->regName <<"  *                 *" << endl;
    cout << "    " <<  " *                 *" << endl;
    cout << "    " <<  " * * * * * * * * * *" << endl;
}

void Register::printRegister() {
    cout << regName << ": " << endl;
}

void Register::setRegData(int data) {
    this->data = data;
    if(!isINS){
        this->hexData = f.toHex(this->data);
    }
}



void Register::displayContent() {
    cout << "o " << this->regName << "==> " << this->hexData << endl;
}

int Register::getRegData() {
    return this->data;
}