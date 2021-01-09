#ifndef DataRegister_h
#define DataRegister_h
#include <cstdint>

struct Register {
    uint8_t* pointer;
    int n;
};

class DataRegister {
    private:
        uint8_t** _pointers;
        short* _size_array;
        short _num_registers;

    public:
        DataRegister(short num_registers, uint8_t** buffer, short* size_array);
        void link(short reg_num, uint8_t* value, short reg_size);
        Register get(short reg_num);
        void put(uint8_t* value, short reg_num);

};

#endif