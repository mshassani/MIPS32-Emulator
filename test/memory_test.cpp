#include <cassert>
#include <cstdint>
#include <iostream>

#include "../src/memory/memory.hpp"

int main()
{
    Memory memory;

    //==========================
    // reset()
    //==========================
    memory.reset();

    for (uint32_t i = 0; i < 1024; i++)
    {
        assert(memory.read8(i) == 0);
    }

    std::cout << "[PASS] reset()\n";

    //==========================
    // write8 / read8
    //==========================
    memory.write8(100, 0xAB);

    assert(memory.read8(100) == 0xAB);

    std::cout << "[PASS] read8/write8\n";

    //==========================
    // write16 / read16
    //==========================
    memory.write16(200, 0x1234);

    assert(memory.read16(200) == 0x1234);

    assert(memory.read8(200) == 0x34);
    assert(memory.read8(201) == 0x12);

    std::cout << "[PASS] read16/write16\n";

    //==========================
    // write32 / read32
    //==========================
    memory.write32(300, 0x12345678);

    assert(memory.read32(300) == 0x12345678);

    assert(memory.read8(300) == 0x78);
    assert(memory.read8(301) == 0x56);
    assert(memory.read8(302) == 0x34);
    assert(memory.read8(303) == 0x12);

    std::cout << "[PASS] read32/write32\n";

    std::cout << "\nAll Memory Tests Passed.\n";

    return 0;
}