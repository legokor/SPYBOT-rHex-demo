#include "main.h"
#include "stm32f4xx_hal.h"

void togglepins() {
	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
	  HAL_Delay(1000);
}
