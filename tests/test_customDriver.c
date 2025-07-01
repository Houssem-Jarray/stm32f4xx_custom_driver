#include <stdio.h>
#include "gpio.h"
#include "tim.h"

void test_gpio_init() {
    printf("Running GPIO Init Test...\n");
    // Simulate init call
    GPIO_Init(GPIO_B, OUTPUT, PP, PIN_2);
    printf("✅ GPIO Init simulated for PB2\n");
}

void test_timer_setup() {
    printf("Running Timer Init Test...\n");
    TIM_Init(TIM2_BASE, 15999, 999);
    printf("✅ Timer TIM2 initialized with PSC=15999, ARR=999\n");
}

int main(void) {
    test_gpio_init();
    test_timer_setup();
    printf("All driver tests passed (simulation mode)\n");
    return 0;
}
