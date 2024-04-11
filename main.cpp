#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>
using namespace std;

class Register {
private:
    string regName;
    int data;
    string hexadecimal; 

public:
    Register(string regName) {
        this->regName = regName;
    }
    void printRegister() {
        
        cout << "    " <<  " * * * * * * * * * *" << endl;
        cout << "    " <<  " *                 *" << endl;
        cout << regName <<"  *                 *" << endl;
        cout << "    " <<  " *                 *" << endl;
        cout << "    " <<  " * * * * * * * * * *" << endl;
    }
};

void printAllRegisters(Register registers[], int noOfRegisters) {
    for(int i = 0; i < noOfRegisters; i++) {
        registers[i].printRegister();
    }
}

void pause(float n){
    n *= CLOCKS_PER_SEC;
    clock_t now{clock()};
    while(clock() - now < n);
}

void clrScr() {
    cout << "\033[2J\033[1;1H";
}

int main() {
    // create the registers
    Register mnb("mnb");
    Register nic("nic");
    Register ole("ole");
    Register brn("brn");
    Register ale("ale");
    Register ans("ans");

    Register registers[6] = { mnb, nic, ole, brn, ale, ans};
    size_t noOfRegisters = sizeof(registers)/sizeof(mnb);


    // fetch from memory
    fstream fetch;
    fetch.open("source.in", ios::in);
    
    string line;
    while(getline(fetch, line)) {
        clrScr();
        cout << "Fetching from memory..." << flush;
        pause(1);
        cout << line << "\n" << flush;
        pause(1);
        printAllRegisters(registers, noOfRegisters);
        pause(2);
    }

    
}






// mnb.printRegister();
// nic.printRegister();
// ole.printRegister();
// ale.printRegister();
// brn.printRegister();
// ans.printRegister();