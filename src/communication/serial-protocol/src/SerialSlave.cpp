#include "SerialProtocol/SerialSlave.h"
#include "DataRegister/DataRegister.h"
#include "SerialPort/SerialPort.h"
#include <cstdint>


SerialSlave::SerialSlave(SerialPort *port, DataRegister *reg)
{
  _port = port;
  _init = true;
}

short SerialSlave::scan() {
  if (!_init) {
    return -100;
  }
  short resp = 0;

  bool new_message = _port->available() >= 3;
  if (new_message) {
    uint8_t bytes[3];
    _port->readBytes(bytes, 3);
    bool valid = bytes[0] == 0xff;
    uint8_t function = bytes[1];
    uint8_t num = bytes[2]; //word num = *(word*)&bytes[2];
    if (valid) {
      resp = 1;
      switch (function) {
        case SER_READ:
          handleRead(num);
          break;
        case SER_WRITE:
          handleWrite(num);
          break;
        default:
          handleInvalid();
          resp = -2;
          break;
      }
    } else {
      handleInvalid();
      resp = -1;
    }
  }
  return resp;
}

void SerialSlave::setRegister(DataRegister data_register) {
}

void SerialSlave::handleWrite(uint8_t num) {
  uint8_t primer[] = {SER_WRITE};
  _port->writeBytes(primer, 1);
  for (short i = 0; i < num; i++) {
    uint8_t reg_num[1];
    _port->readBytes(reg_num, 1);
    Register reg_object = _reg->get(reg_num[0]);
    uint8_t bytes[reg_object.n];
    _port->readBytes(bytes, reg_object.n);
    _reg->put(bytes, reg_num[0]);
  }
}

void SerialSlave::handleRead(uint8_t num) {
  uint8_t primer[] = {SER_READ};
  _port->writeBytes(primer, 1);
  for (short i = 0; i < num; i++) {
    uint8_t reg_num[1];
    _port->readBytes(reg_num, 1);
    Register reg_object = _reg->get(reg_num[0]);
    _port->writeBytes(reg_object.pointer, reg_object.n);
  }
}

void SerialSlave::handleInvalid() {
  short num_available = _port->available();
  if (num_available > 0) {
    uint8_t waste[num_available];
    _port->readBytes(waste, num_available);
  }
  uint8_t primer[] = {SER_ERROR};
  _port->writeBytes(primer, 1);
}