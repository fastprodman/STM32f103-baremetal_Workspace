################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/i2c.c \
../Src/main.c \
../Src/ssd1306.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/systick.c \
../Src/uart.c 

OBJS += \
./Src/i2c.o \
./Src/main.o \
./Src/ssd1306.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/systick.o \
./Src/uart.o 

C_DEPS += \
./Src/i2c.d \
./Src/main.d \
./Src/ssd1306.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/systick.d \
./Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DSTM32F103x6 -c -I../Inc -I"D:/Stas/Documents/GitHub/STM32f103-baremetal_Workspace/chip_header/CMSIS/Device/ST/STM32F1xx/Include" -I"D:/Stas/Documents/GitHub/STM32f103-baremetal_Workspace/chip_header/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/i2c.d ./Src/i2c.o ./Src/i2c.su ./Src/main.d ./Src/main.o ./Src/main.su ./Src/ssd1306.d ./Src/ssd1306.o ./Src/ssd1306.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/systick.d ./Src/systick.o ./Src/systick.su ./Src/uart.d ./Src/uart.o ./Src/uart.su

.PHONY: clean-Src

