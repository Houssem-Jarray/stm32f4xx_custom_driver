/**
  ******************************************************************************
  * @file    tim/tim_pwm.c
  * @author  Houssem Jarray
  * @version V1.0.0
  * @date    2025-06-30
  * @brief   Basic PWM driver over TIMx for STM32F4 (Channel 1 only)
  ******************************************************************************
  */

   /* Includes --------------------------------------------------------------- */
#include "tim_pwm.h"
#include "tim.h"  // for base control: EnableClock, etc.

void TIM_PWM_Init(unsigned int *TIMx, unsigned short prescaler, unsigned short period, unsigned short duty) {
    TIM_EnableClock(TIMx);

    *((volatile unsigned int *)(TIMx + TIM_PSC / 4)) = prescaler;
    *((volatile unsigned int *)(TIMx + TIM_ARR / 4)) = period;
    *((volatile unsigned int *)(TIMx + TIM_CCR1 / 4)) = duty;

    volatile unsigned int *ccmr1 = (volatile unsigned int *)(TIMx + TIM_CCMR1 / 4);
    *ccmr1 &= ~(0xFF);  // Clear channel 1 config
    *ccmr1 |= TIM_CCMR1_OC1M_PWM1 | TIM_CCMR1_OC1PE;

    volatile unsigned int *ccer = (volatile unsigned int *)(TIMx + TIM_CCER / 4);
    *ccer |= TIM_CCER_CC1E;

    *((volatile unsigned int *)(TIMx + TIM_EGR / 4)) |= TIM_EGR_UG;   // Force update
    *((volatile unsigned int *)(TIMx + TIM_CR1 / 4)) |= TIM_CR1_CEN;  // Start
}

void TIM_PWM_SetDuty(unsigned int *TIMx, unsigned short duty) {
    *((volatile unsigned int *)(TIMx + TIM_CCR1 / 4)) = duty;
}
