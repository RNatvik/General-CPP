#include "pid/PIDController.h"
#include <stdexcept>
#include <cmath>


PID::PID(double kp, double ki, double kd, bool normalize){
    _kp = kp;
    _ki = ki;
    _kd = kd;
    _isum = 0;
    _e0 = 0;
    _timescale = 1000;
    _normalize = normalize;
    _x0 = 0;
    _x1 = 100;
    _y0 = 0;
    _y1 = 100;
}

void PID::setGain(double kp, double ki, double kd) {
    _kp = kp;
    _ki = ki;
    _kd = kd;
}

void PID::setTimescale(unsigned short scale) {
    _timescale = scale;
}

void PID::setNormalized(double x0, double x1, double y0, double y1) {
    _x0 = x0;
    _x1 = x1;
    _y0 = y0;
    _y1 = y1;
}


PIDResponse PID::run(double input, double setpoint, unsigned int dt) {
    if (dt == 0) {
        dt = 1;
    } 
    double _dt = (double) dt / std::pow(10, _timescale);  
    
    double error = setpoint - input;
    double d_error = error - _e0;
    _isum += error;
    _e0 = error;

    double p = _kp * error;
    double i = _ki * _isum * dt;
    double d = _kd * d_error / dt;
    return PIDResponse{(p+i+d), p, i, d};
}