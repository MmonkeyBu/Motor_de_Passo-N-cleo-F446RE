# Driver de Motor de Passo para STM32

Este repositório contém um driver modular em linguagem C para o controle de motores de passo bipolares, desenvolvido para a plataforma STM32 utilizando o STM32CubeIDE e a biblioteca HAL.

O código foi estruturado para ser de fácil integração e configuração, separando a lógica de controle do motor da aplicação principal.

---

## Hardware de Referência

Este driver foi desenvolvido e testado com o seguinte hardware, mas pode ser facilmente adaptado para outros microcontroladores e componentes:

* **Microcontrolador:** STM32F446RE (Placa NUCLEO-F446RE)
* **IDE:** STM32CubeIDE (v1.18.1 ou superior)
* **Driver do Motor:** A4988 ou DRV8825
* **Motor de Passo:** NEMA 17 (1.8° por passo, 200 passos/volta)

---

## Funcionalidades

* **Controle Modular:** Lógica do motor encapsulada nos arquivos `MOTOR_DE_PASSO.c` e `.h`.
* **Controle de Direção:** Funções para rotação nos sentidos horário e anti-horário.
* **Sequência de Meio-Passo (Half-Step):** Permite uma rotação mais suave e com o dobro da resolução (400 passos/volta).
* **Controle de Velocidade:** Função para ajustar a velocidade de rotação dinamicamente.
* **Configuração Flexível:** Pinos e porta GPIO facilmente configuráveis através de macros no arquivo de header.

---

## Como Usar

Para integrar este driver ao seu projeto no STM32CubeIDE, siga os passos abaixo:

### 1. Copie os Arquivos

* Copie o arquivo `MOTOR_DE_PASSO.h` para a pasta `Core/Inc` do seu projeto.
* Copie o arquivo `MOTOR_DE_PASSO.c` para a pasta `Core/Src` do seu projeto.

### 2. Configure o Hardware

Abra o arquivo `MOTOR_DE_PASSO.h` e ajuste as macros na seção de configuração para corresponder aos pinos que você configurou no STM32CubeMX.

```c
// MOTOR_DE_PASSO.h

// ===================================================================
// ==          CONFIGURAÇÃO DE HARDWARE E MOTOR                     ==
// ===================================================================
#define MOTOR_GPIO_PORT   GPIOC    // A porta onde os pinos estão (ex: GPIOC)

#define MOTOR_IN1_PIN     IN1_Pin  // O nome do pino para a Bobina 1
#define MOTOR_IN2_PIN     IN2_Pin  // O nome do pino para a Bobina 2
#define MOTOR_IN3_PIN     IN3_Pin  // O nome do pino para a Bobina 3
#define MOTOR_IN4_PIN     IN4_Pin  // O nome do pino para a Bobina 4

// ** IMPORTANTE: Verifique o datasheet do seu motor! **
// Para um motor de 1.8°/passo, são 200 passos completos ou 400 meio-passos.
#define MOTOR_PASSOS_POR_VOLTA 400
// ===================================================================
