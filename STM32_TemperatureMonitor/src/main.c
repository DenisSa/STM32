/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "stm32f1xx.h"
#include "SSD1306/ssd1306.h"
#include "SSD1306/ssd1306_font.h"

I2C_HandleTypeDef hi2c1;

static void MX_I2C1_Init(void);

int main(void) {
	SystemInit();
	SystemCoreClockUpdate();
	HAL_Init();
	MX_I2C1_Init();

	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;

	ssd1306_Init();
	HAL_Delay(1000);
	ssd1306_Fill(White);
	ssd1306_UpdateScreen();
	HAL_Delay(1000);
	ssd1306_SetCursor(23, 23);
	ssd1306_WriteString("Test 123", Font_11x18, Black);
	ssd1306_UpdateScreen();

	GPIOC->CRH = 0x33333333;

	while (1) {
		HAL_Delay(500);
		GPIOC->ODR ^= (1 << 13);
	}
}

/* I2C1 init function */
void MX_I2C1_Init(void)
{

  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  HAL_I2C_Init(&hi2c1);
}
