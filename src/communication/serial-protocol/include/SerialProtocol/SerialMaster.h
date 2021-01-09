#ifndef SerialMaster_h
#define SerialMaster_h

#include "DataRegister/DataRegister.h"
#include "SerialPort/SerialPort.h"
#include <iostream>
#include <cstdint>


#define SER_READ 0xaa
#define SER_WRITE 0xbb
#define SER_ERROR 0xee

class SerialMaster {
  public:
    SerialMaster(SerialPort *port, DataRegister *data_register);

    bool read(uint8_t *reg_nums, uint8_t n);
    bool write(uint8_t *reg_nums, uint8_t n);
    

  private:
    SerialPort *_port;
    DataRegister *_data_register;
    bool _init;
};



#endif