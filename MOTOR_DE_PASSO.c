/*
 * MOTOR_DE_PASSO.c
 *
 *  Created on: Jul 10, 2025
 *      Author: pdnv2
 */
#include "MOTOR_DE_PASSO.h"

int g_motor_delay_ms = 0;

void motor_passo_set(int s1, int s2, int s3, int s4){
	HAL_GPIO_WritePin(MOTOR_GPIO_PORT , MOTOR_IN1_PIN , s1 ? SET : RESET);
	HAL_GPIO_WritePin(MOTOR_GPIO_PORT , MOTOR_IN2_PIN , s2 ? SET : RESET);
	HAL_GPIO_WritePin(MOTOR_GPIO_PORT , MOTOR_IN3_PIN , s3 ? SET : RESET);
	HAL_GPIO_WritePin(MOTOR_GPIO_PORT , MOTOR_IN4_PIN , s4 ? SET : RESET);
}

void motor_velocidade(uint32_t speed_ms)
{
    g_motor_delay_ms = speed_ms;
}

void motor_volta_completa(void){
	motor_passo_set(1, 0, 0, 0);
    HAL_Delay(g_motor_delay_ms);

    motor_passo_set(1, 1, 0, 0);
    HAL_Delay(g_motor_delay_ms);

    motor_passo_set(0, 1, 0, 0);
    HAL_Delay(g_motor_delay_ms);

    motor_passo_set(0, 1, 1, 0);
    HAL_Delay(g_motor_delay_ms);

    motor_passo_set(0, 0, 1, 0);
    HAL_Delay(g_motor_delay_ms);

    motor_passo_set(0, 0, 1, 1);
    HAL_Delay(g_motor_delay_ms);

    motor_passo_set(0, 0, 0, 1);
    HAL_Delay(g_motor_delay_ms);

    motor_passo_set(1, 0, 0, 1);
    HAL_Delay(g_motor_delay_ms);
}

void motor_volta_completa_inversa(void){
    motor_passo_set(1, 0, 0, 1);
    HAL_Delay(g_motor_delay_ms);

    motor_passo_set(0, 0, 0, 1);
    HAL_Delay(g_motor_delay_ms);

    motor_passo_set(0, 0, 1, 1);
    HAL_Delay(g_motor_delay_ms);

    motor_passo_set(0, 0, 1, 0);
    HAL_Delay(g_motor_delay_ms);

    motor_passo_set(0, 1, 1, 0);
    HAL_Delay(g_motor_delay_ms);

    motor_passo_set(0, 1, 0, 0);
    HAL_Delay(g_motor_delay_ms);

    motor_passo_set(1, 1, 0, 0);
    HAL_Delay(g_motor_delay_ms);

	motor_passo_set(1, 0, 0, 0);
    HAL_Delay(g_motor_delay_ms);
}
