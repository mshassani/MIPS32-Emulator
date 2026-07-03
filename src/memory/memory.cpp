#include "memory.hpp"

void Memory::write8(uint32_t address, uint8_t value) {
    mem[address] = value;
}
uint8_t Memory::read8(uint32_t address) {
    return mem[address];
}



void Memory::write16(uint32_t address, uint16_t value) {
    mem[address] = value & 0xff;
    mem[address + 1] = value >> 8;
}
uint16_t Memory::read16(uint32_t address) {
    return static_cast<uint16_t>(mem[address + 1] << 8) | mem[address];
}

void Memory::write32(uint32_t address, uint32_t value) {
    write16(address, value & 0xffff);
    write16(address + 2, value >> 16);
}
uint32_t Memory::read32(uint32_t address) {
    return static_cast<uint32_t>(read16(address + 2)) << 16 | read16(address);
}

void Memory::reset() {
    for (uint8_t& i : mem)
        i = 0;
}


