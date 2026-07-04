#include <cassert>
#include <iostream>

#include "../src/decoder/decoder.hpp"

int main()
{
    Decoder decoder;

    // add $t0, $t1, $t2
    // opcode=0
    // rs=9
    // rt=10
    // rd=8
    // shamt=0
    // funct=0x20
    uint32_t instruction = 0x012A4020;

    DecodedInstruction d = decoder.decode(instruction);

    assert(d.opcode == 0);
    assert(d.rs == 9);
    assert(d.rt == 10);
    assert(d.rd == 8);
    assert(d.shamt == 0);
    assert(d.funct == 0x20);

    std::cout << "[PASS] R-Type Decode\n";

    // lw $v0, 4($at)
    // opcode=0x23
    // rs=1
    // rt=2
    // immediate=4
    instruction = 0x8C220004;

    d = decoder.decode(instruction);

    assert(d.opcode == 0x23);
    assert(d.rs == 1);
    assert(d.rt == 2);
    assert(d.immediate == 4);

    std::cout << "[PASS] I-Type Decode\n";

    // j 0x00000004
    // opcode=2
    // address=4
    instruction = 0x08000004;

    d = decoder.decode(instruction);

    assert(d.opcode == 0x02);
    assert(d.address == 0x00000004);

    std::cout << "[PASS] J-Type Decode\n";

    std::cout << "\nAll Decoder Tests Passed.\n";

    return 0;
}