#include "SerialProtocol/SerialMaster.h"
#include "DataRegister/DataRegister.h"
#include "SerialPort/SerialPort.h"
#include <iostream>
#include <cstdint>

SerialMaster::SerialMaster(SerialPort *port, DataRegister *data_register) {
    _port = port;
    _data_register = data_register;
    _init = true;
}

bool SerialMaster::read(uint8_t *reg_nums, uint8_t n) {
    Register registers[n];
    short rx_expected = 0;

    uint8_t header[] = {0xff, SER_READ, n};
    _port->writeBytes(header, 3);
    _port->writeBytes(reg_nums, n);
    for (short i = 0; i < n; i++) {
        registers[i] = _data_register->get(reg_nums[i]);
        rx_expected += registers[i].n;        
    }
    uint8_t rx_buffer[rx_expected];
    _port->readBytes(rx_buffer, 1);
    
    bool success = rx_buffer[0] == SER_READ;
    if (success == true) {
        _port->readBytes(rx_buffer, rx_expected);
        short start_index = 0;
        for (short i = 0; i < n; i++) {
            uint8_t *start = &rx_buffer[start_index];
            _data_register->put(start, reg_nums[i]);
            start_index += registers[i].n;    
        }
    }
    return success;
}

bool SerialMaster::write(uint8_t *reg_nums, uint8_t n) {
    uint8_t header[] = {0xff, SER_WRITE, n};
    _port->writeBytes(header, 3);

    for (short i = 0; i < n; i++) {
        Register reg = _data_register->get(reg_nums[i]);
        _port->writeBytes(&reg_nums[i], 1);
        _port->writeBytes(reg.pointer, reg.n);
    }

    uint8_t response_code[1];
    _port->readBytes(response_code, 1);

    return response_code[0] == SER_WRITE;
}
