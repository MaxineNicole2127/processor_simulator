#include "register.h"
#include <iostream>
using namespace std;


Register::Register(string regName) {
    this->regName = regName;
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