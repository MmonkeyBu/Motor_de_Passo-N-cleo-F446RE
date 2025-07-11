/*
 * MOTOR_DE_PASSO.H
 *
 *  Created on: Jul 10, 2025
 *      Author: pdnv2
 */
#ifndef MOTOR_DE_PASSO_H_
#define MOTOR_DE_PASSO_H_

#include "main.h"

// ===================================================================
// ==          CONFIGURAÇÃO DE HARDWARE DO MOTOR DE PASSO           ==
// ===================================================================
//
// SÓ PRECISA ALTERAR AS LINHAS ABAIXO, CASO VÁ USAR OUTROS PINOS OU GPIO.
#define MOTOR_GPIO_PORT   GPIOC    // A porta onde os pinos do motor estão conectados

#define MOTOR_IN1_PIN      GPIO_PIN_5 // O pino para a Bobina 1
#define MOTOR_IN2_PIN      GPIO_PIN_6 // O pino para a Bobina 2
#define MOTOR_IN3_PIN      GPIO_PIN_7  // O pino para a Bobina 3
#define MOTOR_IN4_PIN      GPIO_PIN_8  // O pino para a Bobina 4

// ===================================================================
//Passo manual
void motor_passo_set(int s1, int s2, int s3, int s4);
//Velocidade do motor, lembre-se +velocidade - torque e virse e versa
void motor_velocidade(uint32_t speed_ms);
// Volta completa
void motor_volta_completa(void);
void motor_volta_completa_inversa(void);

// --- DEFINIÇÕES DE VELOCIDADE ---
#define SPEED_LOW     10
#define SPEED_MEDIUM  5
#define SPEED_HIGH    1


#endif /* INC_MOTOR_DE_PASSO_H_ */
