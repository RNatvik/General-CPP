#include <iostream>
#include <cstdint>
#include "SerialPort/SerialPort.h"
#include <chrono>

void delay(int);

int main() {
    std::cout << "SerialPort is fun" << std::endl;
    const char *PORT = "COM5";
    SerialPort serial_port(PORT, 115200);
    std::cout << "Constructed serial_port object" << std::endl;

    serial_port.open();
    std::cout << "Serial port open" << std::endl;
    std::cout << "Waiting 2 sec..." << std::endl;
    delay(2000);

    std::cout << "Writing message..." << std::endl;
    const short num = 14;
    char message[] = "Please repeat!";
    float test_message = 13.37;
    float test_message2 = 80.08;
    serial_port.writeBytes((uint8_t*)&test_message, 4);
    serial_port.writeBytes((uint8_t*)&test_message2, 4);
    
    int available;
    uint8_t rx_buffer[num];
    // do {
    //     available = serial_port.available();
    //     std::cout << available << std::endl;
    // } while (available < num);
    // serial_port.readBytes(rx_buffer, num);

    // for (short i = 0; i < num; i++) {
    //     std::cout << rx_buffer[i];
    // }

    serial_port.readBytes(rx_buffer, 1);
    std::cout << "num: " << (int)rx_buffer[0] << std::endl;

    for (short i = 0; i < 8; i++) {
        serial_port.readBytes(rx_buffer, 1);
        std::cout << (int)rx_buffer[0] << std::endl;
    }

    return 0;
}

void delay(int milliseconds) {
    auto t0 = std::chrono::high_resolution_clock::now();
    auto t = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t - t0);
    do {
        t = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(t - t0);
    } while (duration.count() < milliseconds);
}
