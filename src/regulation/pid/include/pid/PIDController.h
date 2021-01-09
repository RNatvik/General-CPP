#ifndef PIDController_h
#define PIDController_h

struct PIDResponse {
    double output;
    double p;
    double i;
    double d;
};

class PID {
    private:
    double _kp;
    double _ki;
    double _kd;
    double _isum;
    double _e0;

    unsigned short _timescale;
    bool _normalize;
    double _x0;
    double _x1;
    double _y0;
    double _y1;

    public:
    PID(double kp, double ki, double kd, bool normalize);
    void setGain(double kp, double ki, double kd);
    void setTimescale(unsigned short scale);
    void setNormalized(double x0, double x1, double y0, double y1);
    PIDResponse run(double input, double setpoint, unsigned int dt);

};


#endif