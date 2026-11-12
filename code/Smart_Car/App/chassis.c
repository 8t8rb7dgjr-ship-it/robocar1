#include "stm32f1xx_hal.h"
#include "chassis.h"
#include "motor.h"

// vx: 前后(+前 -后)  vy: 左右(+右 -左)  omega: 旋转(+顺时针 -逆时针)
static void Chassis_Move(int16_t vx, int16_t vy, int16_t omega) {
    // 麦轮逆运动学公式
    int16_t fl = vx + vy + omega;
    int16_t fr = vx - vy - omega;
    int16_t rl = vx - vy + omega;
    int16_t rr = vx + vy - omega;

    // 安全限幅
    if (fl >  1000) fl =  1000;  if (fl < -1000) fl = -1000;
    if (fr >  1000) fr =  1000;  if (fr < -1000) fr = -1000;
    if (rl >  1000) rl =  1000;  if (rl < -1000) rl = -1000;
    if (rr >  1000) rr =  1000;  if (rr < -1000) rr = -1000;

    // 发送给底层驱动
    Wheel_FL(fl);
    Wheel_FR(fr);
    Wheel_RL(rl);
    Wheel_RR(rr);
}


// 前进：vx 为正，vy 和 omega 为 0
void Car_Forward(uint16_t speed) {
    Chassis_Move((int16_t)speed, 0, 0);  
}

// 后退：vx 为负，vy 和 omega 为 0
void Car_Backward(uint16_t speed) {
    Chassis_Move(-(int16_t)speed, 0, 0); 
}

// 原地左转：omega 为负
void Car_LeftCircle(uint16_t speed) {
    Chassis_Move(0, 0, -(int16_t)speed); 
}

// 原地右转：omega 为正
void Car_RightCircle(uint16_t speed) {
    Chassis_Move(0, 0, (int16_t)speed);
}

// 向左平移：vy 为负
void Car_StrafeLeft(uint16_t speed) {
    Chassis_Move(0, -(int16_t)speed, 0);
}

// 向右平移：vy 为正
void Car_StrafeRight(uint16_t speed) {
    Chassis_Move(0, (int16_t)speed, 0);
}

// 向前左转,前进速度给 speed，左转旋转给 speed/2
void Car_TurnLeftF(uint16_t speed) {
    Chassis_Move((int16_t)speed, 0, -(int16_t)(speed / 2)); 
}

// 向前右转,前进速度给 speed，右转旋转给 speed/2
void Car_TurnRightF(uint16_t speed) {
    Chassis_Move((int16_t)speed, 0, (int16_t)(speed / 2));
}

// 向后左转,前进速度给 speed，左转旋转给 speed/2
void Car_TurnLeftB(uint16_t speed) {
    Chassis_Move(-(int16_t)speed, 0, -(int16_t)(speed / 2)); 
}

// 向后右转,前进速度给 speed，右转旋转给 speed/2
void Car_TurnRightB(uint16_t speed) {
    Chassis_Move(-(int16_t)speed, 0, (int16_t)(speed / 2));
}

// 停止：调用底层的全停函数
void Car_Stop(void) {
    Motor_StopAll();
}