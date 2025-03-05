#ifndef STEPMOTOR_H
#define STEPMOTOR_H

#include <Arduino.h>
// enum Step {
//     KB_BTN1,
//     KB_IDLE
// };
class StepMotor {
public:
    StepMotor(int p1, int p2, int p3, int p4);  // 建構子
    void Init();                                // 初始化: 設定相關腳位
    void Move(bool dir, int steps, int speed);  // 馬達轉動: 方向、步數和速度

private:
    int _p1;
    int _p2;
    int _p3;
    int _p4;
    const int phases[8][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1},
        {1, 0, 0, 1}
    };
    void _step_positive();  // 正向一步
    void _step_negetive();  // 逆向一步
};

#endif