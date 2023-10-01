################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LD_SRCS += \
../src/lscript.ld 

C_SRCS += \
../src/dht11.c \
../src/led.c \
../src/ledfont.c \
../src/main.c \
../src/max30102.c 

OBJS += \
./src/dht11.o \
./src/led.o \
./src/ledfont.o \
./src/main.o \
./src/max30102.o 

C_DEPS += \
./src/dht11.d \
./src/led.d \
./src/ledfont.d \
./src/main.d \
./src/max30102.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../ebaz_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


