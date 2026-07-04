#include <cassert>
#include <cstdint>
#include <iostream>

#include "../src/registers/registers.hpp"

int main()
{
    Registers regs;

    //==========================
    // reset()
    //==========================
    regs.reset();

    assert(regs.getPc() == 0);

    for (uint8_t i = 0; i < 32; i++)
    {
        assert(regs.read(i) == 0);
    }

    std::cout << "[PASS] reset()\n";

    //==========================
    // write() / read()
    //==========================
    regs.write(5, 12345);

    assert(regs.read(5) == 12345);

    std::cout << "[PASS] read()/write()\n";

    //==========================
    // PC
    //==========================
    regs.setPc(0x1000);

    assert(regs.getPc() == 0x1000);

    std::cout << "[PASS] PC\n";

    //==========================
    // Multiple Registers
    //==========================
    regs.write(1, 10);
    regs.write(2, 20);
    regs.write(31, 999);

    assert(regs.read(1) == 10);
    assert(regs.read(2) == 20);
    assert(regs.read(31) == 999);

    std::cout << "[PASS] Multiple Registers\n";

    //===========================
    // Zero Register Test
    //===========================
    regs.write(0, 9999);

    assert(regs.read(0) == 0);

    std::cout << "[PASS] R0 is hardwired to zero\n";

    std::cout << "\nAll Register Tests Passed.\n";

    return 0;
}
