################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/gpio.c \
../Src/lptim.c \
../Src/main.c \
../Src/matrixData.c \
../Src/matrixDriver.c \
../Src/stm32l0xx_hal_msp.c \
../Src/stm32l0xx_it.c \
../Src/syscalls.c \
../Src/system_stm32l0xx.c \
../Src/tim.c 

OBJS += \
./Src/gpio.o \
./Src/lptim.o \
./Src/main.o \
./Src/matrixData.o \
./Src/matrixDriver.o \
./Src/stm32l0xx_hal_msp.o \
./Src/stm32l0xx_it.o \
./Src/syscalls.o \
./Src/system_stm32l0xx.o \
./Src/tim.o 

C_DEPS += \
./Src/gpio.d \
./Src/lptim.d \
./Src/main.d \
./Src/matrixData.d \
./Src/matrixDriver.d \
./Src/stm32l0xx_hal_msp.d \
./Src/stm32l0xx_it.d \
./Src/syscalls.d \
./Src/system_stm32l0xx.d \
./Src/tim.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' -DARM_MATH_CM0 '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L011xx -I"C:/Users/Sean/Documents/Hardware Projects/MATCARD2/Firmware/Inc" -I"C:/Users/Sean/Documents/Hardware Projects/MATCARD2/Firmware/Drivers/STM32L0xx_HAL_Driver/Inc" -I"C:/Users/Sean/Documents/Hardware Projects/MATCARD2/Firmware/Drivers/STM32L0xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Sean/Documents/Hardware Projects/MATCARD2/Firmware/Drivers/CMSIS/Device/ST/STM32L0xx/Include" -I"C:/Users/Sean/Documents/Hardware Projects/MATCARD2/Firmware/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


