#include "DataRegister/DataRegister.h"
#include <cstdint>

DataRegister::DataRegister(short num_registers, uint8_t** buffer, short* size_array) {
    _pointers = buffer;
    _num_registers = num_registers;
    _size_array = size_array;
}

void DataRegister::link(short reg_num, uint8_t* value, short reg_size) {
    _pointers[reg_num] = value;
    _size_array[reg_num] = reg_size;
}

Register DataRegister::get(short reg_num) {
    Register reg = {
        _pointers[reg_num],
        _size_array[reg_num]
    };
    return reg;
}

void DataRegister::put(uint8_t* value, short reg_num) {
    short n = _size_array[reg_num];
    for (short i = 0; i < n; i++) {
        _pointers[reg_num][i] = value[i];
    }
}