#include <iostream>


template <typename R, typename T>
R map(T x, T x0, T x1, T y0, T y1);


int main() {
    // input range = 4 000 -> 20 000
    // output range = 0 -> 850
    // Normalized values = 0 -> 1

    float x0 = -100;
    int x1 = 100;
    
    int ri_ti = map<int, int>(61, x0, x1, 0, 10);
    int ri_tf = map<int, float>(61, x0, x1, 0, 10);
    float rf_ti = map<float, int>(61, x0, x1, 0, 10);
    float rf_tf = map<float, float>(61, x0, x1, 0, 10);

    std::cout << ri_ti << std::endl;
    std::cout << ri_tf << std::endl;
    std::cout << rf_ti << std::endl;
    std::cout << rf_tf << std::endl;



    return 0;
}

template <typename R, typename T>
R map(T x, T x0, T x1, T y0, T y1) {
    R value = (double) (x-x0) / (x1-x0) * (y1-y0) + y0;
    return value;
}