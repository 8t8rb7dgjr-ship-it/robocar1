#include "stm32f1xx_hal.h"
#include "motor.h"

extern TIM_HandleTypeDef htim3;//声明PWM使能TIM3

void Wheel_FL(int16_t speed) { //左前轮PB4 PB5
    uint16_t pwm = 0;
    if (speed > 0) {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
        pwm = (uint16_t)speed;
    } else if (speed < 0) {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
        pwm = (uint16_t)(-speed);
    } else {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
        pwm = 0;
    }
		if (pwm > 1000) pwm = 1000;
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, pwm);//PA6
}

void Wheel_FR(int16_t speed) { //右前轮PB12 PB15
    uint16_t pwm = 0;
    if (speed > 0) {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
        pwm = (uint16_t)speed;
    } else if (speed < 0) {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
        pwm = (uint16_t)(-speed);
    } else {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
        pwm = 0;
    }
    if (pwm > 1000) pwm = 1000;
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, pwm); //PA7
}

void Wheel_RL(int16_t speed) { //左后轮PA8 PA9
    uint16_t pwm = 0;
    if (speed > 0) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
        pwm = (uint16_t)speed;
    } else if (speed < 0) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
        pwm = (uint16_t)(-speed);
    } else {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
        pwm = 0;
    }
    if (pwm > 1000) pwm = 1000;
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, pwm); //PB0
}

void Wheel_RR(int16_t speed) { //右后轮PA10 PA11
    uint16_t pwm = 0;
    if (speed > 0) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
        pwm = (uint16_t)speed;
    } else if (speed < 0) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET);
        pwm = (uint16_t)(-speed);
    } else {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
        pwm = 0;
    }
    if (pwm > 1000) pwm = 1000;
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, pwm); //PB1
}
												
void Motor_Init(void) {                      //使能PWM
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
    
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);  //拉高STBY  PB3 PB6                                                                                                                                                                    
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);  

    Motor_StopAll();

}

void Motor_StopAll(void) {
    Wheel_FL(0);
    Wheel_FR(0);
    Wheel_RL(0);
    Wheel_RR(0);
}

