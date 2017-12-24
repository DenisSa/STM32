#include "gpio_beeper.h"
#include "stm32f1xx_hal.h"

void gpio_beeper_Init(){
	gpio_beeper_beep();
	HAL_Delay(100);
	gpio_beeper_stop();
}

void gpio_beeper_beep(){
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
}

void gpio_beeper_stop(){
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
}
