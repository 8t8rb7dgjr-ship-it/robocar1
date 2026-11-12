#ifndef __CHASSIS_H
#define __CHASSIS_H

#include "main.h"

void Car_Forward(uint16_t speed);    // 前进
void Car_Backward(uint16_t speed);   // 后退
void Car_LeftCircle(uint16_t speed); //原地左转
void Car_RightCircle(uint16_t speed);//原地右转
void Car_TurnLeftF(uint16_t speed);   // 向前左转
void Car_TurnRightF(uint16_t speed);  // 向前右转
void Car_TurnLeftB(uint16_t speed);  // 向后左转
void Car_TurnRightB(uint16_t speed); // 向后右转
void Car_StrafeLeft(uint16_t speed); // 向左平移
void Car_StrafeRight(uint16_t speed);// 向右平移

void Car_Stop(void);//停止

#endif