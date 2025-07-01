/**
  ******************************************************************************
  * @file    tim/tim_pwm.h
  * @author  Houssem Jarray
  * @version V1.0.0
  * @date    2025-06-30
  * @brief   Basic PWM driver over TIMx for STM32F4 (Channel 1 only)
  ******************************************************************************
  */

#ifndef TIM_PWM_H_
#define TIM_PWM_H_

/* Timer Registers Offsets */
#define TIM_CCMR1        0x18
#define TIM_CCER         0x20
#define TIM_CCR1         0x34

/* CCMR1 Config */
#define TIM_CCMR1_OC1M_PWM1  (0b110 << 4) // Output Compare Mode 1
#define TIM_CCMR1_OC1PE      (1 << 3)     // Preload Enable

/* CCER Config */
#define TIM_CCER_CC1E        (1 << 0)     // Enable output on channel 1

/* Function Prototypes */
void TIM_PWM_Init(unsigned int *TIMx, unsigned short prescaler, unsigned short period, unsigned short duty);
void TIM_PWM_SetDuty(unsigned int *TIMx, unsigned short duty);

#endif /* TIM_PWM_H_ */
