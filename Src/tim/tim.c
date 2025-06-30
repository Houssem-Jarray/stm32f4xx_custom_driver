#include "tim.h"

/* RCC Register for APB1 peripheral clock */
#define RCC_BASE           0x40023800UL
#define RCC_APB1ENR        (*(volatile unsigned int *)(RCC_BASE + 0x40))
#define RCC_APB1RSTR       (*(volatile unsigned int *)(RCC_BASE + 0x20))

/**
 * @brief Enable the clock for a given TIMx peripheral.
 */
void TIM_ClockEnable(unsigned int *TIMx) {
    if (TIMx == TIM2_BASE) RCC_APB1ENR |= (1 << 0);
    else if (TIMx == TIM3_BASE) RCC_APB1ENR |= (1 << 1);
    else if (TIMx == TIM4_BASE) RCC_APB1ENR |= (1 << 2);
    else if (TIMx == TIM5_BASE) RCC_APB1ENR |= (1 << 3);
}

/**
 * @brief Disable the clock for a given TIMx peripheral.
 */
void TIM_ClockDisable(unsigned int *TIMx) {
    if (TIMx == TIM2_BASE) RCC_APB1ENR &= ~(1 << 0);
    else if (TIMx == TIM3_BASE) RCC_APB1ENR &= ~(1 << 1);
    else if (TIMx == TIM4_BASE) RCC_APB1ENR &= ~(1 << 2);
    else if (TIMx == TIM5_BASE) RCC_APB1ENR &= ~(1 << 3);
}

/**
 * @brief Reset the TIMx peripheral registers.
 */
void TIM_Reset(unsigned int *TIMx) {
    if (TIMx == TIM2_BASE) { RCC_APB1RSTR |= (1 << 0); RCC_APB1RSTR &= ~(1 << 0); }
    else if (TIMx == TIM3_BASE) { RCC_APB1RSTR |= (1 << 1); RCC_APB1RSTR &= ~(1 << 1); }
    else if (TIMx == TIM4_BASE) { RCC_APB1RSTR |= (1 << 2); RCC_APB1RSTR &= ~(1 << 2); }
    else if (TIMx == TIM5_BASE) { RCC_APB1RSTR |= (1 << 3); RCC_APB1RSTR &= ~(1 << 3); }
}

/**
 * @brief Initialize timer with prescaler and autoreload (period).
 */
void TIM_Init(unsigned int *TIMx, unsigned short prescaler, unsigned short autoreload) {
    TIM_ClockEnable(TIMx);
    *((volatile unsigned int *)(TIMx + TIM_PSC / 4)) = prescaler;
    *((volatile unsigned int *)(TIMx + TIM_ARR / 4)) = autoreload;
    *((volatile unsigned int *)(TIMx + TIM_EGR / 4)) = TIM_EGR_UG; // update
}

/**
 * @brief Start the timer.
 */
void TIM_Start(unsigned int *TIMx) {
    *((volatile unsigned int *)(TIMx + TIM_CR1 / 4)) |= TIM_CR1_CEN;
}

/**
 * @brief Stop the timer.
 */
void TIM_Stop(unsigned int *TIMx) {
    *((volatile unsigned int *)(TIMx + TIM_CR1 / 4)) &= ~TIM_CR1_CEN;
}

/**
 * @brief Reset the counter value to 0.
 */
void TIM_ResetCounter(unsigned int *TIMx) {
    *((volatile unsigned int *)(TIMx + TIM_CNT / 4)) = 0;
}

/**
 * @brief Read the current counter value.
 */
unsigned int TIM_GetCounter(unsigned int *TIMx) {
    return *((volatile unsigned int *)(TIMx + TIM_CNT / 4));
}

/**
 * @brief Check if the update event occurred (overflow).
 */
int TIM_HasElapsed(unsigned int *TIMx) {
    return (*((volatile unsigned int *)(TIMx + TIM_SR / 4)) & TIM_SR_UIF) != 0;
}

/**
 * @brief Clear the update event flag.
 */
void TIM_ClearFlag(unsigned int *TIMx) {
    *((volatile unsigned int *)(TIMx + TIM_SR / 4)) &= ~TIM_SR_UIF;
}
