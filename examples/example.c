#include "gpio.h"
#include "tim.h"

/**
 * @brief Blink LED on PB2 every 1 second using TIM2.
 */
int main(void) {
    // Initialize system clock (in real setup, call HAL_Init and SystemClock_Config if needed)

    // Enable GPIOB clock and initialize PB2 as output
    GPIO_ClockEnable(GPIO_B);
    GPIO_Init(GPIO_B, OUTPUT, PP, PIN_2);

    // Initialize TIM2 to generate 1s interval (assuming 16 MHz clock)
    TIM_Init(TIM2_BASE, 16000 - 1, 1000 - 1);  // 1s = (PSC+1)*(ARR+1)/F_CPU
    TIM_Start(TIM2_BASE);

    while (1) {
        if (TIM_HasElapsed(TIM2_BASE)) {
            TIM_ClearFlag(TIM2_BASE);
            GPIO_ToggleBits(GPIO_B, GPIO_Pin_2);
        }
    }
}
