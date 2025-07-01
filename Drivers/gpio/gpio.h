/*
 * ***************************************************************************
 * @file gpio/gpio.h
 * @brief GPIO Base Addresses for STM32F4xx Microcontrollers
 * @details This header file defines the base addresses for GPIO ports A through K 
 *          and the different GPIO registers.
 * @author houssem Jarray
 * @date 2025-06-30
 * @version 1.0
 * ***************************************************************************
 */

#ifndef GPIO_GPIO_H_
#define GPIO_GPIO_H_

/* Includes ------------------------------------------------------------------*/
/*
 * @brief GPIO Base Addresses
 */
#define GPIO_A (unsigned int *)  (0x40020000)
#define GPIO_B (unsigned int *)  (0x40020400)
#define GPIO_C (unsigned int *)  (0x40020800)
#define GPIO_D (unsigned int *)  (0x40020C00)
#define GPIO_E (unsigned int *)  (0x40021000)
#define GPIO_F (unsigned int *)  (0x40021400)
#define GPIO_G (unsigned int *)  (0x40021800)
#define GPIO_H (unsigned int *)  (0x40021C00)
#define GPIO_I (unsigned int *)  (0x40022000)
#define GPIO_J (unsigned int *)  (0x40022400)
#define GPIO_K (unsigned int *)  (0x40022800)

/* GPIO Registers Offsets */
#define MODER                       0x00
#define OTYPER                      0x04
#define OSPEEDR                     0x08
#define PUPDR                       0x0C
#define IDR                         0x10
#define ODR                         0x14
#define BSRR                        0x18
#define LCKR                        0x1C
#define AFRL                        0x20
#define AFRH                        0x24
#define BRR                         0x28
#define ASCR                        0x2C

/* Pin Numbers */
#define PIN_0                       0x00
#define PIN_1                       0x01
#define PIN_2                       0x02
#define PIN_3                       0x03
#define PIN_4                       0x04
#define PIN_5                       0x05
#define PIN_6                       0x06
#define PIN_7                       0x07
#define PIN_8                       0x08
#define PIN_9                       0x09
#define PIN_10                      0x0A
#define PIN_11                      0x0B
#define PIN_12                      0x0C
#define PIN_13                      0x0D
#define PIN_14                      0x0E
#define PIN_15                      0x0F

/* GPIO Modes */
#define INPUT                       0X00 // Input Mode
#define OUTPUT                      0X01 // Output Mode
#define AF                          0X02 // Alternate Function Mode
#define AN                          0X03 // Analog Mode

/* Output Types */
#define PP                          0X00 // Push-Pull Output
#define OD                          0X01 // Open-Drain Output

/* GPIO Speed */
#define LOW_SPEED                   0X00 // Low Speed
#define MEDIUM_SPEED                0X01 // Medium Speed
#define HIGH_SPEED                  0X02 // High Speed
#define VERY_HIGH_SPEED             0X03 // Very High Speed

/* Pull-up/Pull-down */
#define NO_PULL                     0X00 // No Pull-up/Pull-down
#define PULL_UP                     0X01 // Pull-up
#define PULL_DOWN                   0X02 // Pull-down

/* GPIO Init structure definition */
/* @defgroup GPIO_pins Masks */

#define GPIO_Pin_0               ((unsigned short)0x0001)  /* Pin 0 selected */
#define GPIO_Pin_1               ((unsigned short)0x0002)  /* Pin 1 selected */
#define GPIO_Pin_2               ((unsigned short)0x0004)  /* Pin 2 selected */
#define GPIO_Pin_3               ((unsigned short)0x0008)  /* Pin 3 selected */
#define GPIO_Pin_4               ((unsigned short)0x0010)  /* Pin 4 selected */
#define GPIO_Pin_5               ((unsigned short)0x0020)  /* Pin 5 selected */
#define GPIO_Pin_6               ((unsigned short)0x0040)  /* Pin 6 selected */
#define GPIO_Pin_7               ((unsigned short)0x0080)  /* Pin 7 selected */
#define GPIO_Pin_8               ((unsigned short)0x0100)  /* Pin 8 selected */
#define GPIO_Pin_9               ((unsigned short)0x0200)  /* Pin 9 selected */
#define GPIO_Pin_10              ((unsigned short)0x0400)  /* Pin 10 selected */
#define GPIO_Pin_11              ((unsigned short)0x0800)  /* Pin 11 selected */
#define GPIO_Pin_12              ((unsigned short)0x1000)  /* Pin 12 selected */
#define GPIO_Pin_13              ((unsigned short)0x2000)  /* Pin 13 selected */
#define GPIO_Pin_14              ((unsigned short)0x4000)  /* Pin 14 selected */
#define GPIO_Pin_15              ((unsigned short)0x8000)  /* Pin 15 selected */


/* Bit Values */
#define Bit_RESET                 0x00
#define Bit_SET                   0x01

/* Functions Prototypes */


/* GPIO Clock Control function */
void GPIO_ClockEnable(unsigned int *gpio_x);
void GPIO_ClockDisable(unsigned int *gpio_x);

/* GPIO Configuration function */
void GPIO_Init(unsigned int *gpio_x, char mode, char typeOutput, short int pin);
void GPIO_ConfigSpeed(unsigned int *gpio_x, short int pin, char speed);
void GPIO_ConfigPullUpDown(unsigned int *gpio_x, short int pin, char pupd);


/* GPIO Read Functions */
unsigned char GPIO_ReadInputDataBit(unsigned int *gpio_x, unsigned short int GPIO_Pin);
unsigned short int GPIO_ReadInputData(unsigned int *gpio_x);
unsigned char GPIO_ReadOutputDataBit(unsigned int *gpio_x, unsigned short int GPIO_Pin);
unsigned short int GPIO_ReadOutputData(unsigned int *gpio_x);


/* GPIO Write Functions */
void GPIO_WriteBit(unsigned int *gpio_x, unsigned short GPIO_Pin, char BitVal);
void GPIO_Write(unsigned int *gpio_x, unsigned short int PortVal);
void GPIO_SetBits(unsigned int *gpio_x, unsigned short GPIO_Pin);
void GPIO_ResetBits(unsigned int *gpio_x, unsigned short GPIO_Pin);
void GPIO_ToggleBits(unsigned int *gpio_x, unsigned short GPIO_Pin);


#endif /* GPIO_GPIO_H_ */
