#include <stdint.h>
#include "clock.h"
#include "gpio.h"
#include "uart.h"
#include "stm32f4xx.h"

static void delay(volatile uint32_t count)
{
    while (count--) {
        __asm volatile ("nop");
    }
}

int main(void)
{
    clock_init();

    /* If you have not set PLL, and you are at reset defaults:
       SYSCLK = 16 MHz (HSI)
       APB1 prescaler default is /1 => PCLK1 = 16 MHz.
       If you later change clocks, update this value accordingly. */
    uart2_init(16000000UL, 115200UL);

    gpio_enable_port_a();
    gpio_set_output_a(5);

    uart2_write("UART2 up. Blinking PA5.\n");

    while (1)
    {
        gpio_toggle_a(5);
        uart2_write("tick\n");
        delay(500000);
    }
}
