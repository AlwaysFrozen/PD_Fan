################################################################################
# MRS Version: 1.9.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
E:/PD_Fan/PD_Fan/Software/EXAM/SRC/StdPeriphDriver/CH57x_adc.c \
E:/PD_Fan/PD_Fan/Software/EXAM/SRC/StdPeriphDriver/CH57x_clk.c \
E:/PD_Fan/PD_Fan/Software/EXAM/SRC/StdPeriphDriver/CH57x_flash.c \
E:/PD_Fan/PD_Fan/Software/EXAM/SRC/StdPeriphDriver/CH57x_gpio.c \
E:/PD_Fan/PD_Fan/Software/EXAM/SRC/StdPeriphDriver/CH57x_pwr.c \
E:/PD_Fan/PD_Fan/Software/EXAM/SRC/StdPeriphDriver/CH57x_sys.c \
E:/PD_Fan/PD_Fan/Software/EXAM/SRC/StdPeriphDriver/CH57x_timer0.c \
E:/PD_Fan/PD_Fan/Software/EXAM/SRC/StdPeriphDriver/CH57x_timer1.c \
E:/PD_Fan/PD_Fan/Software/EXAM/SRC/StdPeriphDriver/CH57x_timer2.c \
E:/PD_Fan/PD_Fan/Software/EXAM/SRC/StdPeriphDriver/CH57x_uart1.c 

OBJS += \
./StdPeriphDriver/CH57x_adc.o \
./StdPeriphDriver/CH57x_clk.o \
./StdPeriphDriver/CH57x_flash.o \
./StdPeriphDriver/CH57x_gpio.o \
./StdPeriphDriver/CH57x_pwr.o \
./StdPeriphDriver/CH57x_sys.o \
./StdPeriphDriver/CH57x_timer0.o \
./StdPeriphDriver/CH57x_timer1.o \
./StdPeriphDriver/CH57x_timer2.o \
./StdPeriphDriver/CH57x_uart1.o 

C_DEPS += \
./StdPeriphDriver/CH57x_adc.d \
./StdPeriphDriver/CH57x_clk.d \
./StdPeriphDriver/CH57x_flash.d \
./StdPeriphDriver/CH57x_gpio.d \
./StdPeriphDriver/CH57x_pwr.d \
./StdPeriphDriver/CH57x_sys.d \
./StdPeriphDriver/CH57x_timer0.d \
./StdPeriphDriver/CH57x_timer1.d \
./StdPeriphDriver/CH57x_timer2.d \
./StdPeriphDriver/CH57x_uart1.d 


# Each subdirectory must supply rules for building sources it contributes
StdPeriphDriver/CH57x_adc.o: E:/PD_Fan/PD_Fan/Software/EXAM/SRC/StdPeriphDriver/CH57x_adc.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\Startup" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\PD_Fan\APP\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\PD_Fan\Profile\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\StdPeriphDriver\inc" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\HAL\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\Ld" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\LIB" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_clk.o: E:/PD_Fan/PD_Fan/Software/EXAM/SRC/StdPeriphDriver/CH57x_clk.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\Startup" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\PD_Fan\APP\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\PD_Fan\Profile\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\StdPeriphDriver\inc" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\HAL\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\Ld" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\LIB" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_flash.o: E:/PD_Fan/PD_Fan/Software/EXAM/SRC/StdPeriphDriver/CH57x_flash.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\Startup" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\PD_Fan\APP\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\PD_Fan\Profile\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\StdPeriphDriver\inc" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\HAL\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\Ld" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\LIB" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_gpio.o: E:/PD_Fan/PD_Fan/Software/EXAM/SRC/StdPeriphDriver/CH57x_gpio.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\Startup" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\PD_Fan\APP\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\PD_Fan\Profile\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\StdPeriphDriver\inc" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\HAL\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\Ld" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\LIB" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_pwr.o: E:/PD_Fan/PD_Fan/Software/EXAM/SRC/StdPeriphDriver/CH57x_pwr.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\Startup" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\PD_Fan\APP\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\PD_Fan\Profile\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\StdPeriphDriver\inc" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\HAL\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\Ld" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\LIB" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_sys.o: E:/PD_Fan/PD_Fan/Software/EXAM/SRC/StdPeriphDriver/CH57x_sys.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\Startup" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\PD_Fan\APP\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\PD_Fan\Profile\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\StdPeriphDriver\inc" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\HAL\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\Ld" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\LIB" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_timer0.o: E:/PD_Fan/PD_Fan/Software/EXAM/SRC/StdPeriphDriver/CH57x_timer0.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\Startup" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\PD_Fan\APP\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\PD_Fan\Profile\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\StdPeriphDriver\inc" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\HAL\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\Ld" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\LIB" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_timer1.o: E:/PD_Fan/PD_Fan/Software/EXAM/SRC/StdPeriphDriver/CH57x_timer1.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\Startup" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\PD_Fan\APP\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\PD_Fan\Profile\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\StdPeriphDriver\inc" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\HAL\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\Ld" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\LIB" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_timer2.o: E:/PD_Fan/PD_Fan/Software/EXAM/SRC/StdPeriphDriver/CH57x_timer2.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\Startup" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\PD_Fan\APP\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\PD_Fan\Profile\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\StdPeriphDriver\inc" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\HAL\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\Ld" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\LIB" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_uart1.o: E:/PD_Fan/PD_Fan/Software/EXAM/SRC/StdPeriphDriver/CH57x_uart1.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\Startup" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\PD_Fan\APP\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\PD_Fan\Profile\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\StdPeriphDriver\inc" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\HAL\include" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\Ld" -I"E:\PD_Fan\PD_Fan\Software\EXAM\BLE\LIB" -I"E:\PD_Fan\PD_Fan\Software\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

