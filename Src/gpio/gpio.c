/*
 * ***************************************************************************
 * @file gpio/gpio.c
 * @brief GPIO Base Addresses for STM32F4xx Microcontrollers
 * @details This header file defines the base addresses for GPIO ports A through K 
 *          and the different GPIO registers.
 * @author houssem Jarray
 * @date 2025-06-30
 * @version 1.0
 * ***************************************************************************
 */

 /* Includes --------------------------------------------------------------- */
#include "gpio.h"

/* RCC Registers fro Clock Control */
#define RCC_BASE_ADDR          0x40023800UL
#define RCC_AHB1ENR_OFFSET     0x30UL
#define RCC_AHB1RSTR_OFFSET    0x10UL

// AHB1ENR RegisteR <-- RCC_BASE_ADDR + RCC_AHB1ENR_OFFSET
volatile unsigned short *RCC_GPIO_Clock = (volatile short int *)(RCC_BASE_ADDR + RCC_AHB1ENR_OFFSET);
volatile unsigned short *RCC_GPIO_Reset = (volatile short int *)(RCC_BASE_ADDR + RCC_AHB1RSTR_OFFSET);


/**
 * @brief Enable clock for the gpio_x peripheral.
 * @param gpio_x: where x can be (A..K) to select the GPIO peripheral.
 * @retval None
 */
void GPIO_ClockEnable(unsigned int *gpio_x) {
    if (gpio_x == GPIO_A) {
    	*RCC_GPIO_Clock |= (1 << 0);
    } else if (gpio_x == GPIO_B) {
        *RCC_GPIO_Clock |= (1 << 1);
    } else if (gpio_x == GPIO_C) {
        *RCC_GPIO_Clock |= (1 << 2);
    } else if (gpio_x == GPIO_D) {
        *RCC_GPIO_Clock |= (1 << 3);
    } else if (gpio_x == GPIO_E) {
        *RCC_GPIO_Clock |= (1 << 4);
    } else if (gpio_x == GPIO_F) {
        *RCC_GPIO_Clock |= (1 << 5);
    } else if (gpio_x == GPIO_G) {
        *RCC_GPIO_Clock |= (1 << 6);
    } else if (gpio_x == GPIO_H) {
        *RCC_GPIO_Clock |= (1 << 7);
    } else if (gpio_x == GPIO_I) {
        *RCC_GPIO_Clock |= (1 << 8);
    } else if (gpio_x == GPIO_J) {
        *RCC_GPIO_Clock |= (1 << 9);
    } else {
    	if (gpio_x == GPIO_K) {
    		*RCC_GPIO_Clock |= (1 << 10);
    	}
    }
}


/**
 * @brief Disable clock for the gpio_x peripheral.
 * @param gpio_x: where x can be (A..K) to select the GPIO peripheral.
 * @retval None
 */
void GPIO_ClockDisable(unsigned int *gpio_x) {
    if (gpio_x == GPIO_A) {
        *RCC_GPIO_Clock &= ~(1 << 0);
    } else if (gpio_x == GPIO_B) {
        *RCC_GPIO_Clock &= ~(1 << 1);
    } else if (gpio_x == GPIO_C) {
        *RCC_GPIO_Clock &= ~(1 << 2);
    } else if (gpio_x == GPIO_D) {
        *RCC_GPIO_Clock &= ~(1 << 3);
    } else if (gpio_x == GPIO_E) {
        *RCC_GPIO_Clock &= ~(1 << 4);
    } else if (gpio_x == GPIO_F) {
        *RCC_GPIO_Clock &= ~(1 << 5);
    } else if (gpio_x == GPIO_G) {
        *RCC_GPIO_Clock &= ~(1 << 6);
    } else if (gpio_x == GPIO_H) {
        *RCC_GPIO_Clock &= ~(1 << 7);
    } else if (gpio_x == GPIO_I) {
        *RCC_GPIO_Clock &= ~(1 << 8);
    } else if (gpio_x == GPIO_J) {
        *RCC_GPIO_Clock &= ~(1 << 9);
    } else if (gpio_x == GPIO_K) {
        *RCC_GPIO_Clock &= ~(1 << 10);
    }
}

/**
 * @brief Reset the gpio_x peripheral registers to their default reset values.
 * @param gpio_x: where x can be (A..K) to select the GPIO peripheral.
 * @retval None
 */
void GPIO_DeInit(unsigned int *gpio_x) {
    /* RESET USING AHB1RSTR */
    if (gpio_x == GPIO_A) {
    	*RCC_GPIO_Reset |= (1 << 0);
    	*RCC_GPIO_Reset &= ~(1 << 0);
    } else if (gpio_x == GPIO_B) {
    	*RCC_GPIO_Reset |= (1 << 1);
    	*RCC_GPIO_Reset &= ~(1 << 1);
    } else if (gpio_x == GPIO_C) {
    	*RCC_GPIO_Reset |= (1 << 2);
    	*RCC_GPIO_Reset &= ~(1 << 2);
    } else if (gpio_x == GPIO_D) {
    	*RCC_GPIO_Reset |= (1 << 3);
    	*RCC_GPIO_Reset &= ~(1 << 3);
    } else if (gpio_x == GPIO_E) {
    	*RCC_GPIO_Reset |= (1 << 4);
    	*RCC_GPIO_Reset &= ~(1 << 4);
    } else if (gpio_x == GPIO_F) {
    	*RCC_GPIO_Reset |= (1 << 5);
    	*RCC_GPIO_Reset &= ~(1 << 5);
    } else if (gpio_x == GPIO_G) {
    	*RCC_GPIO_Reset |= (1 << 6);
    	*RCC_GPIO_Reset &= ~(1 << 6);
    } else if (gpio_x == GPIO_H) {
    	*RCC_GPIO_Reset |= (1 << 7);
    	*RCC_GPIO_Reset &= ~(1 << 7);
    } else if (gpio_x == GPIO_I) {
    	*RCC_GPIO_Reset |= (1 << 8);
    	*RCC_GPIO_Reset &= ~(1 << 8);
    } else if (gpio_x == GPIO_J) {
    	*RCC_GPIO_Reset |= (1 << 9);
    	*RCC_GPIO_Reset &= ~(1 << 9);
    } else {
    	if(gpio_x == GPIO_K) {
        	*RCC_GPIO_Reset |= (1 << 10);
        	*RCC_GPIO_Reset &= ~(1 << 10);
    	}
    }
}

/**
 * @brief Configure the gpio_x pin
 * @param gpio_x: where x can be (A..K) to select the GPIO peripheral.
 * @param mode: can be INPUT, OUTPUT, AF or AN
 * @param typeOutput: can be PP (Push-Pull) or OD (Open-Drain)
 * @param pin: can be 0...15
 * @retval None
 */
void GPIO_Init(unsigned int *gpio_x, char mode, char typeOutput, short int pin) {
    // Validate pin number
    if (pin > 15) return;

    // Configure MODER register
    volatile unsigned int *MODER_REG = (unsigned int *)((unsigned int)gpio_x + MODER);
    // Clear the mode bits for this pin (2 bits per pin)
    *MODER_REG &= ~(0x3 << (pin * 2));
    // Set the new mode
    *MODER_REG |= ((mode & 0x03) << (pin * 2));

    // Configure OTYPER register (only for output mode)
    if (mode == OUTPUT) {
        volatile unsigned int *OTYPER_REG = (unsigned int *)((unsigned int)gpio_x + OTYPER);
        // Clear the output type bit for this pin
        *OTYPER_REG &= ~(1 << pin);
        // Set the output type
        *OTYPER_REG |= ((typeOutput & 0x01) << pin);
    }
}


/**
 * @brief Configure GPIO pin speed
 * @param gpio_x: GPIO port
 * @param pin: Pin number (0-15)
 * @param speed: Speed setting (LOW_SPEED, MEDIUM_SPEED, HIGH_SPEED, VERY_HIGH_SPEED)
 * @retval None
 */
void GPIO_ConfigSpeed(unsigned int *gpio_x, short int pin, char speed) {
    if (pin > 15) return;

    volatile unsigned int *OSPEEDR_REG = (unsigned int *)((unsigned int)gpio_x + OSPEEDR);
    // Clear speed bits for this pin (2 bits per pin)
    *OSPEEDR_REG &= ~(0x3 << (pin * 2));
    // Set new speed
    *OSPEEDR_REG |= ((speed & 0x03) << (pin * 2));
}


/**
 * @brief Configure GPIO pin pull-up/pull-down
 * @param gpio_x: GPIO port
 * @param pin: Pin number (0-15)
 * @param pupd: Pull setting (NO_PUPD, PULL_UP, PULL_DOWN)
 * @retval None
 */
void GPIO_ConfigPullUpDown(unsigned int *gpio_x, short int pin, char pupd) {
    if (pin > 15) return;

    volatile unsigned int *PUPDR_REG = (unsigned int *)((unsigned int)gpio_x + PUPDR);
    // Clear pull bits for this pin (2 bits per pin)
    *PUPDR_REG &= ~(0x3 << (pin * 2));
    // Set new pull setting
    *PUPDR_REG |= ((pupd & 0x03) << (pin * 2));
}

/**
 * @brief Read the specified input port pin.
 * @param gpio_x: GPIO port
 * @param GPIO_Pin: Pin mask (GPIO_Pin_x)
 * @retval The input port pin value (0 or 1)
 */
unsigned char GPIO_ReadInputDataBit(unsigned int *gpio_x, unsigned short int GPIO_Pin) {
    volatile unsigned int *GPIO_IDR_REG = (unsigned int *)((unsigned int)gpio_x + IDR);
    return ((*GPIO_IDR_REG & GPIO_Pin) != 0) ? 1 : 0;
}

/**
 * @brief Read the specified GPIO input data port.
 * @param gpio_x: GPIO port
 * @retval GPIO input data port value
 */
unsigned short int GPIO_ReadInputData(unsigned int *gpio_x) {
    volatile unsigned int *GPIO_IDR_REG = (unsigned int *)((unsigned int)gpio_x + IDR);
    return (unsigned short int)(*GPIO_IDR_REG & 0xFFFF);
}

/**
 * @brief Read the specified output port pin.
 * @param gpio_x: GPIO port
 * @param GPIO_Pin: Pin mask (GPIO_Pin_x)
 * @retval The output port pin value (0 or 1)
 */
unsigned char GPIO_ReadOutputDataBit(unsigned int *gpio_x, unsigned short int GPIO_Pin) {
    volatile unsigned int *GPIO_ODR_REG = (unsigned int *)((unsigned int)gpio_x + ODR);
    return ((*GPIO_ODR_REG & GPIO_Pin) != 0) ? 1 : 0;
}


/**
 * @brief Read the specified GPIO output data port.
 * @param gpio_x: GPIO port
 * @retval GPIO output data port value
 */
unsigned short int GPIO_ReadOutputData(unsigned int *gpio_x) {
    volatile unsigned int *GPIO_ODR_REG = (unsigned int *)((unsigned int)gpio_x + ODR);
    return (unsigned short int)(*GPIO_ODR_REG & 0xFFFF);
}

/**
 * @brief Set or clear the selected data port bit.
 * @param gpio_x: GPIO port
 * @param GPIO_Pin: Pin mask (GPIO_Pin_x)
 * @param BitVal: Value to write (Bit_RESET or Bit_SET)
 * @retval None
 */
void GPIO_WriteBit(unsigned int *gpio_x, unsigned short GPIO_Pin, char BitVal) {
    volatile unsigned int *GPIO_ODR_REG = (unsigned int *)((unsigned int)gpio_x + ODR);
    if (BitVal == Bit_RESET) {
        // Clear the bit
        *GPIO_ODR_REG &= ~GPIO_Pin;
    } else {
        // Set the bit
        *GPIO_ODR_REG |= GPIO_Pin;
    }
}

/**
 * @brief Write data to the specified GPIO data port.
 * @param gpio_x: GPIO port
 * @param PortVal: Value to be written to the port output data register
 * @retval None
 */
void GPIO_Write(unsigned int *gpio_x, unsigned short int PortVal) {
    volatile unsigned int *GPIO_ODR_REG = (unsigned int *)((unsigned int)gpio_x + ODR);
    *GPIO_ODR_REG = ((*GPIO_ODR_REG & 0xFFFF0000) | (PortVal & 0xFFFF));
}


/**
 * @brief Set the selected data port bits.
 * @param gpio_x: GPIO port
 * @param GPIO_Pin: Pin mask to set
 * @retval None
 */
void GPIO_SetBits(unsigned int *gpio_x, unsigned short GPIO_Pin) {
    volatile unsigned int *GPIO_BSRR_REG = (unsigned int *)((unsigned int)gpio_x + BSRR);
    *GPIO_BSRR_REG = GPIO_Pin; // Set bits (lower 16 bits)
}

/**
 * @brief Reset the selected data port bits.
 * @param gpio_x: GPIO port
 * @param GPIO_Pin: Pin mask to reset
 * @retval None
 */
void GPIO_ResetBits(unsigned int *gpio_x, unsigned short GPIO_Pin) {
    volatile unsigned int *GPIO_BSRR_REG = (unsigned int *)((unsigned int)gpio_x + BSRR);
    *GPIO_BSRR_REG = (GPIO_Pin << 16); // Reset bits (upper 16 bits)
}

/**
 * @brief Toggle the selected data port bits.
 * @param gpio_x: GPIO port
 * @param GPIO_Pin: Pin mask to toggle
 * @retval None
 */
void GPIO_ToggleBits(unsigned int *gpio_x, unsigned short GPIO_Pin) {
    volatile unsigned int *GPIO_ODR_REG = (unsigned int *)((unsigned int)gpio_x + ODR);
    *GPIO_ODR_REG ^= GPIO_Pin;
}


