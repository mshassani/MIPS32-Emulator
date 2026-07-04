#include "registers.hpp"

void Registers::write(uint8_t reg, uint32_t value) {
    if (reg == 0) {
        return;
    }

    registers[reg] = value;
}

uint32_t Registers::read(uint8_t reg) const {
    return registers[reg];
}

void Registers::setPc(uint32_t pc) {
    this->pc = pc;
}

uint32_t Registers::getPc() const {
    return pc;
}

void Registers::reset() {
    pc = 0x0000;
    flags = 0;

    for (uint32_t& reg : registers) {
        reg = 0;
    }
}
