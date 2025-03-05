#include "StepMotor.h"
StepMotor:: StepMotor(int int1, int int2, int int3, int int4){
    this->_p1 = int1;
    this->_p2 = int2;
    this->_p3 = int3;
    this->_p4 = int4;
}

void StepMotor:: Init() {
    pinMode(_p1, OUTPUT);
    pinMode(_p2, OUTPUT);
    pinMode(_p3, OUTPUT);
    pinMode(_p4, OUTPUT);
}

void StepMotor:: Move(bool direction, int steps, int _delay){
    // 以 28BYJ-48 為例，步進角度是 5.625度，馬達減速比是 1:64，
    // 馬達旋轉一圈是 360 度，轉一圈共需要 360/(5.635/64) = 4096 步
    if(direction){
        for(int i=0; i<steps; i++){
            _step_positive();
            delay(_delay);
        }
    }
    else{
        for(int i=0; i<steps; i++){
            _step_negetive();
            delay(_delay);
        }
    }
}

void StepMotor:: _step_positive(){
    for(int i = 0; i < 8; i++){
        digitalWrite(_p1, phases[i][0]);
        digitalWrite(_p2, phases[i][1]);
        digitalWrite(_p3, phases[i][2]);
        digitalWrite(_p4, phases[i][3]);
        delay(5);
    }
}

void StepMotor:: _step_negetive(){
    for(int i = 7; i >= 0; i--){
        digitalWrite(_p1, phases[i][0]);
        digitalWrite(_p2, phases[i][1]);
        digitalWrite(_p3, phases[i][2]);
        digitalWrite(_p4, phases[i][3]);
        delay(5);
    }
}