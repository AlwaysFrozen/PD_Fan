################################################################################
# MRS Version: 1.9.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
E:/PD_Fan/PD_Fan/Software/EXAM/SRC/RVMSIS/core_riscv.c 

OBJS += \
./RVMSIS/core_riscv.o 

C_DEPS += \
./RVMSIS/core_riscv.d 


# Each subdirectory must supply rules for building sources it contributes
RVMSIS/core_riscv.o: E:/PD_Fan/PD_Fan/Software/EXAM/SRC/RVMSIS/core_riscv.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\Startup" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\PD_Fan\APP\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\PD_Fan\Profile\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\StdPeriphDriver\inc" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\HAL\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\Ld" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\LIB" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

