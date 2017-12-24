################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Beeper/gpio_beeper.c 

OBJS += \
./Src/Beeper/gpio_beeper.o 

C_DEPS += \
./Src/Beeper/gpio_beeper.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Beeper/%.o: ../Src/Beeper/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F103xB -I"/home/denis/workspace/STM32_TMonitor/Inc" -I"/home/denis/workspace/STM32_TMonitor/Drivers/STM32F1xx_HAL_Driver/Inc" -I"/home/denis/workspace/STM32_TMonitor/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy" -I"/home/denis/workspace/STM32_TMonitor/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"/home/denis/workspace/STM32_TMonitor/Drivers/CMSIS/Include" -I"/home/denis/workspace/STM32_TMonitor/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


