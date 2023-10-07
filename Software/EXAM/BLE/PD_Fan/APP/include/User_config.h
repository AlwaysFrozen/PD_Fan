#ifndef USER_CONFIG_H
#define CONUSER_CONFIG_HFIG_H

#include "stdbool.h"
#include "stdint.h"
#include "string.h"
#include "math.h"
#include "CONFIG.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define CONFIG_ADDR (0x00077000 - FLASH_ROM_MAX_SIZE)

#define CONFIG_VERIFY_VALUE 0x1abcdef0

typedef struct
{
    uint32_t verify;
    uint8_t target_vol;
    uint8_t target_duty;
} Config_t;

extern Config_t SYS_Config;

void Record_Config(Config_t *cfg);
void Read_Config(Config_t *cfg);
void Init_Config(void);

#ifdef __cplusplus
}
#endif

#endif
