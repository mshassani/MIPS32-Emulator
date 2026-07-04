#include "decoder.hpp"

DecodedInstruction Decoder::decode(uint32_t instruction) {
    DecodedInstruction decoded;

    decoded.opcode = (instruction >> 26) & 0x3F;
    decoded.rs = (instruction >> 21) & 0x1F;
    decoded.rd = (instruction >> 11) & 0x1F;
    decoded.rt = (instruction >> 16) & 0x1F;
    decoded.immediate = instruction & 0xFFFF;
    decoded.shamt = instruction & 0x1F;
    decoded.funct = (instruction >> 0) & 0x3F;
    decoded.address = instruction & 0x03FFFFFF;

    return decoded;
}