#include <cassert>
#include <iostream>

#include "../src/alu/alu.hpp"

int main()
{
    ALU alu;
    ALUOutput out;

    //==========================
    // ADD
    //==========================
    out = alu.execute(ALUOperation::ADD, 10, 20);
    assert(out.value == 30);
    std::cout << "[PASS] ADD\n";

    //==========================
    // SUB
    //==========================
    out = alu.execute(ALUOperation::SUB, 20, 5);
    assert(out.value == 15);
    std::cout << "[PASS] SUB\n";

    //==========================
    // AND
    //==========================
    out = alu.execute(ALUOperation::AND, 0b1100, 0b1010);
    assert(out.value == 0b1000);
    std::cout << "[PASS] AND\n";

    //==========================
    // OR
    //==========================
    out = alu.execute(ALUOperation::OR, 0b1100, 0b1010);
    assert(out.value == 0b1110);
    std::cout << "[PASS] OR\n";

    //==========================
    // XOR
    //==========================
    out = alu.execute(ALUOperation::XOR, 0b1100, 0b1010);
    assert(out.value == 0b0110);
    std::cout << "[PASS] XOR\n";

    //==========================
    // NOR
    //==========================
    out = alu.execute(ALUOperation::NOR, 0b1100, 0b1010);
    assert(out.value == ~(0b1100 | 0b1010));
    std::cout << "[PASS] NOR\n";

    //==========================
    // SLL
    //==========================
    out = alu.execute(ALUOperation::SLL, 1, 3);
    assert(out.value == 8);
    std::cout << "[PASS] SLL\n";

    //==========================
    // SRL
    //==========================
    out = alu.execute(ALUOperation::SRL, 16, 2);
    assert(out.value == 4);
    std::cout << "[PASS] SRL\n";

    //==========================
    // SLT
    //==========================
    out = alu.execute(ALUOperation::SLT, 5, 10);
    assert(out.value == 1);

    out = alu.execute(ALUOperation::SLT, 10, 5);
    assert(out.value == 0);

    std::cout << "[PASS] SLT\n";

    //==========================
    // PASS
    //==========================
    out = alu.execute(ALUOperation::PASS, 12345, 999);
    assert(out.value == 12345);
    std::cout << "[PASS] PASS\n";

    //==========================
    // Zero Flag
    //==========================
    out = alu.execute(ALUOperation::SUB, 10, 10);
    assert(out.value == 0);
    assert(out.zero == true);

    std::cout << "[PASS] Zero Flag\n";

    std::cout << "\nAll ALU Tests Passed.\n";

    return 0;
}