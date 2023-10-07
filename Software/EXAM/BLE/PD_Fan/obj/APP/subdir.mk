################################################################################
# MRS Version: 1.9.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/Fan.c \
../APP/User_config.c \
../APP/peripheral.c \
../APP/peripheral_main.c 

OBJS += \
./APP/Fan.o \
./APP/User_config.o \
./APP/peripheral.o \
./APP/peripheral_main.o 

C_DEPS += \
./APP/Fan.d \
./APP/User_config.d \
./APP/peripheral.d \
./APP/peripheral_main.d 


# Each subdirectory must supply rules for building sources it contributes
APP/%.o: ../APP/%.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\Startup" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\PD_Fan\APP\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\PD_Fan\Profile\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\StdPeriphDriver\inc" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\HAL\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\Ld" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\LIB" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

