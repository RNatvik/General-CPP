#include "SerialProtocol/SerialMaster.h"
#include "SerialPort/SerialPort.h"
#include "DataRegister/DataRegister.h"
#include <iostream>
#include <cstdint>
#include <chrono>
#include <thread>


void delay(int);
void test(void);

int main() {
    const unsigned short num_regs = 23;
    uint8_t* register_buffer[num_regs];
    short size_array[num_regs];

    DataRegister data_register(num_regs, register_buffer, size_array);
    short loop_time = 0; data_register.link(2,  (uint8_t*) &loop_time, 2);
    float roll      = 0; data_register.link(9,  (uint8_t*) &roll,      4);
    float pitch     = 0; data_register.link(10, (uint8_t*) &pitch,     4);
    float temp      = 0; data_register.link(22, (uint8_t*) &temp,      4);

    const char *PORT = "COM5";
    SerialPort serial_port(PORT, 115200);

    SerialMaster master(&serial_port, &data_register);
    serial_port.open();
    std::cout << "Setup complete. Waiting 2 sec..." << std::endl;
    delay(5000);
    std::cout << "Delay complete" << std::endl;

    { // Local scope
    auto t0 = std::chrono::high_resolution_clock::now();
    uint8_t tx_buffer[] = {2, 9, 10, 22};
    for (int i = 0; i < 1000; i++) {
        
        bool success = master.read(tx_buffer, 4);
        //std::cout << success << ":";
        if (success) {
            //std::cout << "\tloop_time: " << loop_time;
            //std::cout << "\troll: " << roll;
            //std::cout << "\tpitch: " << pitch;
            //std::cout << "\ttemp: " << temp << std::endl;
        } else {
            //std::cout << "\tSomething went wrong during read..." << std::endl;
            return 0;
        }
    }
    auto t = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t - t0);
    std::cout << duration.count() << std::endl;
    }

    { // Local scope
    loop_time = 100;
    uint8_t tx_buffer[] = {2};
    std::cout << "Writing loop_time = " << loop_time << " to slave." << std::endl;
    bool success = master.write(tx_buffer, 1);
    loop_time = 10;
    std::cout << "Set local loop_time = " << loop_time << std::endl;
    std::cout << "Reading slave loop_time..." << std::endl;
    success = master.read(tx_buffer, 1);
    std::cout << "Result local loop_time = " << loop_time << std::endl;      
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