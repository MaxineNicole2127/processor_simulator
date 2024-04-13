#include <iostream>
using namespace std;
#include "classes/memory.h" // contains class Memory which imitates a memory
#include "classes/actions.h" // contains methods used for actions involving registers and memory
#include "classes/decoder.h" // contains methods used for the decoding process of the instruction
#include "classes/func.h" // contains trivial subfunctions used in the program
#include <iterator>
#include <map>
#include <cmath>
#include <fstream>
#include <vector>
#include <limits>
using namespace std;

// submitted by: Maxine Nicole B. Bernales (CSMC223)


int executeInstruction(map<int, int> &registers, int opCode, vector<int> arguments);

int main() {
    const int byteSize = 4;
    Func f;
    Actions act;
    Conversion c;

    // create registers and initialize them with zero
    map<int, int> registers;

    registers[0] = 0; // pct
    registers[1] = 0; // mnb
    registers[2] = 0; // nic
    registers[3] = 0; // ole
    registers[4] = 0; // ale
    registers[5] = 0; // brn
    registers[6] = 0; // ans
    
    pair<int, string> instruction_register; // ins
    instruction_register.first = 7;
    instruction_register.second = "0x00";


    // collects instructions from the file and stores it in memory cells
    fstream fetch;

    fetch.open("source.in", ios::in);
    
    string instruction;
    int counter = 0;

    vector<Memory> memoryCells;

    
    while(getline(fetch, instruction)) {
        f.clrScr();
        cout << "\n    Collecting instructions from file..." << flush; f.pause(1);
        cout << instruction << "\n";
        Memory m(counter * byteSize);
        counter++;
        m.setInstruction(instruction);
        m.convertToBits();
        memoryCells.push_back(m);
        f.pause(0.5);
        act.printMemoryCells(memoryCells);
        f.promptEnter();
        //f.pause(1);
    }

    fetch.close();


    f.clrScr();
    act.printMemoryCells(memoryCells);
    

    // goes through every instruction in the memory
    for(int i = 0; i < counter; i++) {
        // set pct to the memory cell of the next instruction
        registers[0] = i * byteSize;
        
        f.clrScr();
        act.printMemoryCells(memoryCells);
        act.printAllRegisters(registers, instruction_register);
        f.pause(1);

        // fetch instruction from the memory cell pointer to by the pct
        Memory *mem = act.pointToMemory(&memoryCells, registers[0]);
        string instruction = mem->getBitsInstruction();
        instruction_register.second = instruction;       // load memory content to the instruction register

        f.clrScr();
        act.printMemoryCells(memoryCells);
        act.printAllRegisters(registers, instruction_register);
        f.pause(1);

        // decode the instruction bits
        Decoder d;
        d.setInstructionString(instruction_register.second);
        d.organize();
        d.displayContents();
        f.pause(1);

        int opCode_Decimal = d.getOPCode_Dec();
        vector<int> arguments = d.getArguments_Dec();

        // execute instruction
        int register_changed = executeInstruction(registers, opCode_Decimal, arguments);

        f.clrScr();
        act.printMemoryCells(memoryCells);
        act.printAllRegisters(registers, instruction_register, register_changed);
        d.displayContents();
        f.promptEnter();

        cout << endl;

    }

}






/******************************* EXECUTION ****************************/

int executeInstruction(map<int, int> &registers, int opCode, vector<int> arguments) {
    int arg, arg2, arg3;
    int reg_changed = 0;

    switch(opCode){
    case 0: // INIT <register>
        arg = arguments.at(0);
        registers[arg] = 0;
        reg_changed = arg;
        break;
    case 1: // FILL <register>, <data>
        arg = arguments.at(0);
        arg2 = arguments.at(1);
        registers[arg] = arg2;
        reg_changed = arg;
        break;
    case 2: // MOVE <register>, <register>
        arg = arguments.at(0);
        arg2 = arguments.at(1);
        registers[arg] = registers[arg2];
        reg_changed = arg;
        break;
    case 3: // ADDT <register>, <register>
        arg = arguments.at(0);
        arg2 = arguments.at(1);
        registers[arg] += registers[arg2];
        reg_changed = arg;
        break;
    case 4: // ADDS <register>, <register>, <register>
        arg = arguments.at(0);
        arg2 = arguments.at(1);
        arg3 = arguments.at(2);
        registers[arg3] = registers[arg] + registers[arg2];
        reg_changed = arg3;
        break;
    case 5: // SUBT <register>, <register>
        arg = arguments.at(0);
        arg2 = arguments.at(1);
        registers[arg] -= registers[arg2];
        reg_changed = arg;
        break;
    case 6: // SUBS <register>, <register>, <register>
        arg = arguments.at(0);
        arg2 = arguments.at(1);
        arg3 = arguments.at(2);
        registers[arg3] = registers[arg] - registers[arg2];
        reg_changed = arg3;
        break;
    case 7: // POWT <register> OR POWT <register>, <register>
        if(arguments.size() == 1) {
            arg = arguments.at(0);
            registers[arg] *= registers[arg];
            reg_changed = arg;
        } else {
            arg = arguments.at(0);
            arg2 = arguments.at(1);
            registers[arg2] = registers[arg] * registers[arg];
            reg_changed = arg2;
        }
        break;
    case 8: // SQRT <register> OR POWT <register>, <register>
        if(arguments.size() == 1) {
            arg = arguments.at(0);
            registers[arg] = floor(sqrt(registers[arg]));
            reg_changed = arg;
        } else {
            arg = arguments.at(0);
            arg2 = arguments.at(1);
            registers[arg2] = floor(sqrt(registers[arg]));
            reg_changed = arg2;
        }
        break;
    }

    return reg_changed;
        
}