#pragma once
#include <string>

#include "memory.hpp"
#include "registers.hpp"

class Loader {
private:
  Memory* memory;

public:
  Loader(Memory& memory);

  bool load(const std::string& filename, uint32_t startAddress = 0);
};