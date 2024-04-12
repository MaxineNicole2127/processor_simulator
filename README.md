# Processor Simulator

_Midterm Project for CSMC223_

A simple processor simulator that mimics the basic functionalities of a processor. The simulator will execute instructions from a predefined instruction set architecture (ISA) and operate on a simulated memory system.

## OPCodes

| OPCode     | Keyword     | Syntax                                                   | Function |
| ---------- | ----------- | -------------------------------------------------------- | ------------------------------
| `0000`     | INIT        | INIT `<register to initialize>`                          | Initializes a register with 0.
| `0001`     | FILL        | FILL `<register to fill>`, `<data>`                      | Fills the register with an integer. Data must be a whole number from -2047 to 2047.
| `0010`     | MOVE        | MOVE `<destinationRegister>`, `<sourceRegister>`         | Fills the destinationRegister with the contents of the source register. Both arguments must be registers.
| `0011`     | ADDT        | ADDT `<destinationRegister>`, `<dataRegister>`           | Adds content of dataRegister to the content of destinationRegister.
| `0100`     | ADDS        | ADDS `<operandReg1>`, `<operandReg2>`, `<destinationRegister>` | Adds content of operandReg1 and operandReg2 to the content of destinationRegister. (operandReg1 and operandReg2 are both registers)
| `0101`     | SUBT        | SUBT `<register to subtract from>`, `<data>`             | Subtracts content of dataRegister to the content of destinationRegister.
| `0110`     | SUBS        | SUBS `<minuendReg>`, `<subtrahendReg>`, `<destinationRegister>`| Subtracts content of minuendReg and subtrahendReg to the content of destinationRegister. (minuendReg and subtrahendReg are both registers)
| `0111`     | POWT        | POWT `<register>`                                        | Raises the content of the register to 2
|            | POWT        | POWT `<register>`, `<destinationRegister>`               | If there is a second argument, fill the destinationRegister with the answer.
| `1000`     | SQRT        | SQRT `<register>`                                        | Computes the square root of the content of the register and rounds it off.
|            | SQRT        | SQRT `<register>`, `<destinationRegister>`               | If there is a second argument, fill the destinationRegister with the answer.

## Registers

6 General-Purpose Registers and 1 Special Register

Size: 32-bits

`0001`- `mnb`

`0010`- `nic`

`0011`- `ole`

`0100`- `ale`

`0101`- `brn`

`0110`- `ans`

`0111` - `ins` : A special register that keeps track of the instruction being executed.

`0000`- `pct` : A special register that serves as the program counter of the processor, keeping track of the memory cell of the next instruction to be executed.

