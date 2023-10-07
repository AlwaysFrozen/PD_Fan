################################################################################
# MRS Version: 1.9.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
E:/PD_Fan/PD_Fan/Software/EXAM/BLE/HAL/MCU.c \
E:/PD_Fan/PD_Fan/Software/EXAM/BLE/HAL/RTC.c \
E:/PD_Fan/PD_Fan/Software/EXAM/BLE/HAL/SLEEP.c 

OBJS += \
./HAL/MCU.o \
./HAL/RTC.o \
./HAL/SLEEP.o 

C_DEPS += \
./HAL/MCU.d \
./HAL/RTC.d \
./HAL/SLEEP.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/MCU.o: E:/PD_Fan/PD_Fan/Software/EXAM/BLE/HAL/MCU.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\Startup" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\PD_Fan\APP\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\PD_Fan\Profile\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\StdPeriphDriver\inc" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\HAL\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\Ld" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\LIB" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
HAL/RTC.o: E:/PD_Fan/PD_Fan/Software/EXAM/BLE/HAL/RTC.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\Startup" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\PD_Fan\APP\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\PD_Fan\Profile\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\StdPeriphDriver\inc" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\HAL\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\Ld" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\LIB" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
HAL/SLEEP.o: E:/PD_Fan/PD_Fan/Software/EXAM/BLE/HAL/SLEEP.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\Startup" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\PD_Fan\APP\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\PD_Fan\Profile\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\StdPeriphDriver\inc" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\HAL\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\Ld" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\LIB" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

