#ifndef SerialPort_h
#define SerialPort_h

#include <cstdint>
#include <asio.hpp>
#include <asio/serial_port.hpp>
#include <asio/io_service.hpp>


class SerialPort {
    //8 data bits, no parity, one stop bit.

    private:
    asio::io_service _io;
    asio::serial_port _port;
    asio::serial_port_base::baud_rate _baud;
    asio::serial_port_base::character_size _csize;
    asio::serial_port_base::flow_control _flow;
    asio::serial_port_base::parity _parity;
    asio::serial_port_base::stop_bits _stop_bits;
    const char* _com_port;

    public:
    SerialPort(const char* com_port, long baud_rate);
    void open();
    void close();
    bool connected();
    short available();
    void readBytes(uint8_t* buffer, short n);
    void writeBytes(uint8_t* buffer, short n);
};

#endif