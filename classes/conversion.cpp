#include "conversion.h"
#include <iostream>
#include <string>
using namespace std;

/********************************
    0000 - INIT
    0001 - FILL
    0010 - MOVE
    0011 - ADDT
    0100 - ADDS
    0101 - SUBT
    0110 - SUBS
    0111 - POWT
    1000 - SQRT
********************************/


string Conversion::instructionToOpCode(string instruction) {
        if(instruction == "INIT")
            return "0000";
        else if(instruction == "INIT") 
            return "0001";
        else if(instruction == "MOVE") 
            return "0010";
        else if(instruction == "ADDT") 
            return "0011";
        else if(instruction == "ADDS") 
            return "0100";
        else if(instruction == "SUBT") 
            return "0101";
        else if(instruction == "SUBS") 
            return "0110";
        else if(instruction == "POWT") 
            return "0111";
        else if(instruction == "SQRT") 
            return "1000";
        return "0000";
    }