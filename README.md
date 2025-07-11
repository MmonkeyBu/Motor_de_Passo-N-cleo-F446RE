# Driver de Motor de Passo para STM32

Este repositório contém um driver modular em linguagem C para o controle de motores de passo bipolares, desenvolvido para a plataforma STM32 utilizando o STM32CubeIDE e a biblioteca HAL.

O código foi estruturado para ser de fácil integração e configuração, separando a lógica de controle do motor da aplicação principal.

---

## Hardware de Referência

Este driver foi desenvolvido e testado com o seguinte hardware, mas pode ser facilmente adaptado para outros microcontroladores e componentes:

* **Microcontrolador:** STM32F446RE (Placa NUCLEO-F446RE)
* **IDE:** STM32CubeIDE (v1.18.1 ou superior)
* **Driver do Motor:** ULN2003
* **Motor de Passo:** 28BYJ-48 (5.625°/64 )

---

## Funcionalidades

* **Controle Modular:** Lógica do motor encapsulada nos arquivos `MOTOR_DE_PASSO.c` e `.h`.
* **Controle de Direção:** Funções para rotação nos sentidos horário e anti-horário.
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

// ===================================================================
```
###Para chamar na main.c
```c
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
  motor_velocidade(SPEED_LOW);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
	  motor_volta_completa();
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}
```
