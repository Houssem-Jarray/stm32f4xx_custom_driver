

# STM32 Custom Driver Library

This project provides low-level peripheral drivers for STM32 microcontrollers, specifically targeting:

## ✅ Supported MCU Series

- STM32F405 / STM32F415  
- STM32F407 / STM32F417  
- STM32F427 / STM32F437  
- STM32F429 / STM32F439  

These are advanced Arm® Cortex®-M4 32-bit microcontrollers from STMicroelectronics, ideal for real-time embedded systems.


## 📁 Project Structure

| Path                   | Description                                  |
|------------------------|----------------------------------------------|
| `Drivers/gpio/`        | GPIO driver source and header (`gpio.c/h`)   |
| `Drivers/tim/`         | Timer and PWM driver (`tim.c/h`, `tim_pwm.c/h`) |
| `Inc/`                 | Public headers |
| `Src/customDriver.c`   | Main integration test / example runner       |
| `Src/syscalls.c`       | Newlib syscalls for minimal libc support     |
| `Src/sysmem.c`         | Heap allocator setup for embedded system     |
| `examples/example.c`   | LED blink example using custom drivers       |
| `tests/test_customDriver.c` | Unit/integration test for your drivers |



## 🚀 Getting Started

You can integrate this library into an STM32CubeIDE or Makefile-based project. It’s written in pure C and directly accesses peripheral registers.

---

## 💡 Example: Blink an LED using GPIO and Timer

Here is a minimal example demonstrating how to toggle an LED connected to pin **PB2** every second using **TIM2**:

```c
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
````

🛠️ This shows how easy it is to toggle a GPIO pin using your own register-level drivers, without relying on HAL or LL libraries.

---

## 🔧 Drivers Implemented

* **GPIO (General Purpose I/O)**

  * Clock control
  * Pin configuration (mode, output type, speed, pull-up/down)
  * Read/Write/Toggle APIs
* **TIM (Basic Timer)**

  * Initialization with prescaler and auto-reload
  * Start/stop control
  * Polling-based elapsed check
  * Interrupt support (coming soon)

---

## 📜 License

MIT License

---

## 🤝 Contributions

Feel free to fork the repository, report issues, or submit PRs to enhance functionality and support more peripherals!