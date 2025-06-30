/**
  ******************************************************************************
  * @file    tim/tim.h
  * @author  Houssem Jarray
  * @version V1.0.0
  * @date    2025-06-30
  * @brief   Basic Timer driver for STM32F4xx (Polling-based)
  ******************************************************************************
  */

#ifndef TIM_TIM_H_
#define TIM_TIM_H_

/* Timer Base Addresses */
#define TIM2_BASE       ((unsigned int*) 0x40000000)
#define TIM3_BASE       ((unsigned int*) 0x40000400)
#define TIM4_BASE       ((unsigned int*) 0x40000800)
#define TIM5_BASE       ((unsigned int*) 0x40000C00)

/* Register Offsets */
#define TIM_CR1         0x00
#define TIM_DIER        0x0C
#define TIM_SR          0x10
#define TIM_EGR         0x14
#define TIM_CNT         0x24
#define TIM_PSC         0x28
#define TIM_ARR         0x2C

/* Bit Definitions */
#define TIM_CR1_CEN     (1 << 0)
#define TIM_EGR_UG      (1 << 0)
#define TIM_SR_UIF      (1 << 0)
#define TIM_DIER_UIE    (1 << 0)

/* Function Prototypes */
void TIM_ClockEnable(unsigned int *TIMx);
void TIM_ClockDisable(unsigned int *TIMx);
void TIM_Reset(unsigned int *TIMx);

void TIM_Init(unsigned int *TIMx, unsigned short prescaler, unsigned short autoreload);
void TIM_Start(unsigned int *TIMx);
void TIM_Stop(unsigned int *TIMx);
void TIM_ResetCounter(unsigned int *TIMx);
unsigned int TIM_GetCounter(unsigned int *TIMx);
int  TIM_HasElapsed(unsigned int *TIMx);
void TIM_ClearFlag(unsigned int *TIMx);

#endif /* TIM_TIM_H_ */
