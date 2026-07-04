#pragma once
#include <cstdint>

class Registers {
private:
    uint32_t registers[32];

    uint32_t pc;
    uint32_t flags;
public:
    void write(uint8_t reg , uint32_t value);
    uint32_t read(uint8_t reg) const;

    void setPc(uint32_t pc);
    uint32_t getPc() const;

    void reset();

};
