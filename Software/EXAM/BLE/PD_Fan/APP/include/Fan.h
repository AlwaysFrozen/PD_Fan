#ifndef FAN_H
#define FAN_H

#include "stdbool.h"
#include "stdint.h"
#include "string.h"
#include "math.h"

#ifdef __cplusplus
extern "C"
{
#endif

void PD_Init(void);
void Set_PD_Vol(uint8_t vol);
uint8_t Get_PD_Vol(void);
uint16_t Get_VBUS_Vol(void);

void Fan_Init(void);
void Set_Fan_Duty(uint8_t duty);
uint8_t Get_Fan_Duty(void);
void Cal_Fan_RPM(uint32_t time_ms);
uint16_t Get_Fan_RPM(void);

#ifdef __cplusplus
}
#endif

#endif
