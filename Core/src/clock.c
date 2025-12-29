#include "clock.h"
#include "stm32f4xx.h"   // optional here, but fine if you call SystemCoreClockUpdate()

void clock_init(void)
{
    /* Default after reset: HSI @ 16 MHz on STM32F411 */
    /* Ensure CMSIS variable reflects current clock configuration */
    SystemCoreClockUpdate();
}
