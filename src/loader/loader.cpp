#include "loader.hpp"

#include <fstream>

Loader::Loader(Memory& memory) : memory(&memory) {}

bool Loader::load(const std::string& filename, uint32_t startAddress)
{
    std::ifstream file(filename, std::ios::binary);

    if (!file.is_open())
        return false;

    uint32_t instruction;
    uint32_t address = startAddress;

    while (file.read(reinterpret_cast<char*>(&instruction), sizeof(instruction))) {
        memory->write32(address, instruction);
        address += 4;
    }

    return true;
}
