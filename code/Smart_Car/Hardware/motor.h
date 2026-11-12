#ifndef __MOTOR_H_
#define __MOTOR_H_
#include "main.h"

void Motor_Init(void);

//声明四个轮子分别有不同的速度控制
void Wheel_FL(int16_t speed);
void Wheel_FR(int16_t speed);
void Wheel_RL(int16_t speed);
void Wheel_RR(int16_t speed);

void Motor_StopAll(void);

#endif
