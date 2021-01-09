#include "SerialPort/SerialPort.h"
#include <cstdint>
#include <asio.hpp>
#include <asio/serial_port.hpp>


SerialPort::SerialPort(const char* com_port, long baud_rate):
    _io(),
    _port(_io),
    _baud(baud_rate),
    _csize(8),
    _flow(asio::serial_port_base::flow_control::none),
    _parity(asio::serial_port_base::parity::none),
    _stop_bits(asio::serial_port_base::stop_bits::one)
{
    _com_port = com_port;
}

void SerialPort::open() {
    _port.open(_com_port);
    //8 data bits, no parity, one stop bit.
    _port.set_option(_baud);
    _port.set_option(_csize);
    _port.set_option(_flow);
    _port.set_option(_parity);
    _port.set_option(_stop_bits);
}

void SerialPort::close() {
    _port.close();
}

bool SerialPort::connected() {
    return _port.is_open();
}

short SerialPort::available() {
    int value = 0;
    asio::error::get_system_category();
    ::GetLastError();
    COMSTAT status;
    if (0 != ::ClearCommError(_port.lowest_layer().native_handle(), NULL, &status)) {
        value = status.cbInQue;
    }
    
    return value;
}

void SerialPort::readBytes(uint8_t* buffer, short n) {
    asio::read(_port, asio::buffer(buffer, n));
}

void SerialPort::writeBytes(uint8_t* buffer, short n) {
    asio::write(_port, asio::buffer(buffer, n));
}
