################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/VL53L0X/Implementation/TOF_Units.c 

C_DEPS += \
./Drivers/VL53L0X/Implementation/TOF_Units.d 

OBJS += \
./Drivers/VL53L0X/Implementation/TOF_Units.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/VL53L0X/Implementation/%.o Drivers/VL53L0X/Implementation/%.su: ../Drivers/VL53L0X/Implementation/%.c Drivers/VL53L0X/Implementation/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L432xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-VL53L0X-2f-Implementation

clean-Drivers-2f-VL53L0X-2f-Implementation:
	-$(RM) ./Drivers/VL53L0X/Implementation/TOF_Units.d ./Drivers/VL53L0X/Implementation/TOF_Units.o ./Drivers/VL53L0X/Implementation/TOF_Units.su

.PHONY: clean-Drivers-2f-VL53L0X-2f-Implementation

