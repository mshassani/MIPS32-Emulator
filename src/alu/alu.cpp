#include "alu.hpp"

ALUOutput ALU::execute(ALUOperation operation, uint32_t A, uint32_t B) {

    ALUOutput output;

    switch (operation) {
        case ALUOperation::ADD:
            output.value = A + B;
            break;
        case ALUOperation::SUB:
            output.value = A - B;
            break;
        case ALUOperation::AND:
            output.value = A & B;
            break;
        case ALUOperation::OR:
            output.value = A | B;
            break;
        case ALUOperation::NOR:
            output.value = ~(A | B);
            break;
        case ALUOperation::XOR:
            output.value = A ^ B;
            break;
        case ALUOperation::SLL:
            output.value = A << B;
            break;
        case ALUOperation::SRL:
            output.value = A >> B;
            break;
        case ALUOperation::SRA:
            output.value = static_cast<int32_t>(A) >> B;
            break;
        case ALUOperation::SLT:
            output.value = (static_cast<int32_t>(A) < static_cast<int32_t>(B));
            break;
        case ALUOperation::PASS:
            output.value = A;
            break;
        default:
            output.value = 0;
            break;
    }

    output.zero = (output.value == 0);

    output.negative = (output.value >> 31);

    output.carry = false;

    output.overflow = false;

    return output;
}
