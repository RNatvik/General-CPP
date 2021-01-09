#ifndef SerialSlave_h
#define SerialSlave_h

#include "DataRegister/DataRegister.h"
#include "SerialPort/SerialPort.h"

class SerialSlave {
  public:
    SerialSlave(SerialPort *port, DataRegister *reg);

    void setRegister(DataRegister data_register);
    short scan();
    
  private:
    #define SER_READ 0xaa
    #define SER_WRITE 0xbb
    #define SER_ERROR 0xee
    SerialPort *_port;
    DataRegister *_reg;
    bool _init;
    void handleWrite(uint8_t num);
    void handleRead(uint8_t num);
    void handleInvalid();
};



#endif