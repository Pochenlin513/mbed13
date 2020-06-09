#include "mbed.h"
#include "bbcar.h"

Ticker servo_ticker;
PwmOut pin8(D8), pin9(D9);

BBCar car(pin8, pin9, servo_ticker);

int main() {
    // please contruct you own calibration table with each servo
    double pwm_table0[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150}; //pin8
    double speed_table0[] = {-7.815, -7.257, -7.177, -7.417, -5.981, 0.000, 5.582, 7.098, 6.938, 7.257, 7.177};
    double pwm_table1[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150}; //pin9
    double speed_table1[] = {-9.410, -9.969, -9.889, -8.852, -5.822, 0.000, 4.705, 8.453, 9.490, 9.650, 10.288};


    // first and fourth argument : length of table
    car.setCalibTable(11, pwm_table0, speed_table0, 11, pwm_table1, speed_table1);

    while (1) {
        car.goStraightCalib(5);
        wait(5);
        car.stop();
        wait(5);
    }
}