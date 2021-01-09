#include "DataRegister/DataRegister.h"
#include <iostream>
#include <cstdint>

void display_hex(std::string, Register);

int main() {
    const unsigned short num_registers = 3;
    uint8_t* pointers[num_registers];
    short size_array[num_registers];

    DataRegister data_register = DataRegister(num_registers, pointers, size_array);
    int   r0 = 1337;   data_register.link(0, (uint8_t*) &r0, 4);
    short r1 = 8008;   data_register.link(1, (uint8_t*) &r1, 2);
    float r2 = 123.45; data_register.link(2, (uint8_t*) &r2, 4);

    std::cout << "r0: " << r0 << "\tr1: " << r1 << "\tr2: " << r2 << std::endl;

    Register reg0 = data_register.get(0);
    Register reg1 = data_register.get(1);
    Register reg2 = data_register.get(2);

    display_hex("r0", reg0);
    display_hex("r1", reg1);
    display_hex("r2", reg2);

    r0 = 10;

    short new_r1_value = -123;
    data_register.put((uint8_t*)&new_r1_value, 1);

    std::cout << "r0: " << r0 << "\tr1: " << r1 << "\tr2: " << r2 << std::endl;

    reg0 = data_register.get(0);
    reg1 = data_register.get(1);
    reg2 = data_register.get(2);

    display_hex("r0", reg0);
    display_hex("r1", reg1);
    display_hex("r2", reg2);

    return 0;
}

void display_hex(std::string header, Register reg) {
    std::cout << header << ": " << std::hex << (int)reg.pointer[0];
    for (short i = 1; i < reg.n; i++) {
        std::cout << ", " << (int)reg.pointer[i];
    }
    std::cout << std::dec << std::endl;
}