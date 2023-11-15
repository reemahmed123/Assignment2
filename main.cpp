#include <iostream>
#include <fstream>
#include <vector>
#include<string>
#include<cstring>
using namespace std;
//create memory class
class Memory {
protected:
    vector<int> memory;

public:
    Memory(int size) : memory(size) {}

    int read(int address) const {
        return memory[address];
    }

    void write(int address, int value) {
        memory[address] = value;
    }

    int getSize() const {
        return memory.size();
    }
};

class MainMemory : public Memory {
public:
    MainMemory(int size) : Memory(size) {}
};

class Register : public Memory {
public:
    Register(int size) : Memory(size) {}
};
class Instruction {
private:
    int opcode;
    string operand;

public:
   Instruction(int opcode, string operand) : opcode(opcode), operand(operand) {}

    int getOpcode() const {
        return opcode;
    }

    string getOperand() const {
        return operand;
    }
};

class CPU  {
private:
    int pc; // Program Counter
    int ir; // Instruction Register
    Register registers;

public:
    CPU(int registerSize) : pc(0), ir(0), registers(registerSize){}

    void fetch(const Memory& memory) {
        ir = memory.read(pc);
        pc++;
    }
    void decode(const Instruction& instruction, Memory& memory) {
        int opcode=instruction.getOpcode();
        string operand=instruction.getOperand();
        int IndexRegister = operand[0] - '0';
        int addresse =stoi(operand.substr(1));
        int valueofaddresse=memory.read(addresse);
        int valueofRegister=registers.read(IndexRegister);
        switch (opcode) {
          case 1:
          // Instruction: Load 
          registers.write(IndexRegister, valueofaddresse);
           break;
            case 2:
            //instruction load
            registers.write(IndexRegister,addresse);
            break;
            case 3:
            memory.write(addresse,valueofRegister);
                break;


            // Add more instruction types as needed
        }
    }

    int getPC() const {
        return pc;
    }

    int getIR() const {

        return ir;
    }

    int readRegister(int index) const {
        return registers.read(index);
    }

    int getRegisterSize() const {
        return registers.getSize();
    }
};

class Machine {
private:
    MainMemory mainMemory;
    CPU cpu;

public:
    Machine(int memorySize, int registerSize) : mainMemory(memorySize), cpu(registerSize) {}

    void loadProgram(const string& programFile ) {
        ifstream file(programFile);
        std::string line;
        int address = 0;
        int instruction;
        while (file>>std::hex>>instruction) {
                mainMemory.write(address, instruction);
                address++;
        }
    }

    void displayState() const {
        std::cout << "Memory Contents:" << std::endl;
        for (int i = 0; i < mainMemory.getSize(); i++) {
            std::cout << "Address " << i << ": " << std::hex << mainMemory.read(i) << std::endl;
        }
        cout << "-----------------" << std::endl;
        cout << "Register Contents:" << std::endl;
        for (int i = 0; i < cpu.getRegisterSize(); i++) {
            cout << "Register " << i << ": " << std::hex << cpu.readRegister(i) << std::endl;
        }
        cout << "-----------------" << std::endl;
    }

    void runProgram() {
        while (cpu.getPC() < mainMemory.getSize()) {
            cpu.fetch(mainMemory);
            int opcode = cpu.getIR(); 
            cpu.fetch(mainMemory);
            string operand = to_string(cpu.getIR());  
            cpu.fetch(mainMemory);
            operand += to_string(cpu.getIR());
            Instruction instruction(opcode, operand);  
            cpu.decode(instruction,mainMemory);   
        }
    }
};

int main() {
    const int memorySize = 256;
    const int registerSize = 16;
    Machine machine(memorySize, registerSize);

    string programFile = "program.txt"; // File containing program instructions

    // Load the program into memory from file
    machine.loadProgram("program.txt");

    // Run the program
    machine.runProgram();

    // Display the machine state
    machine.displayState();
}
