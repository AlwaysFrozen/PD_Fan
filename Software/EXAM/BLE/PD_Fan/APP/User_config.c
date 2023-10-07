#include "CONFIG.h"
#include "User_config.h"

static uint8_t dataflash_block_buf[EEPROM_PAGE_SIZE] = {0};

Config_t SYS_Config =
{
    .verify = CONFIG_VERIFY_VALUE,
    .target_vol = 12,
    .target_duty = 50,
};

void Record_Config(Config_t *cfg)
{
    tmos_memcpy(dataflash_block_buf, cfg, sizeof(Config_t));
    EEPROM_ERASE(CONFIG_ADDR, EEPROM_PAGE_SIZE);
    EEPROM_WRITE(CONFIG_ADDR, (uint32 *)dataflash_block_buf, EEPROM_PAGE_SIZE);
}

void Read_Config(Config_t *cfg)
{
    EEPROM_READ(CONFIG_ADDR, (uint32 *)dataflash_block_buf, EEPROM_PAGE_SIZE);
    tmos_memcpy(cfg, dataflash_block_buf, sizeof(Config_t));
}

void Init_Config(void)
{
    PRINT("Init_Config\n");

    Config_t temp;
    Read_Config(&temp);
    if (temp.verify != CONFIG_VERIFY_VALUE)
    {
        PRINT("Config Verify Err\n");
        Record_Config(&SYS_Config);
    }
    else
    {
        PRINT("Config Verify Success\n");
        tmos_memcpy(&SYS_Config, &temp, sizeof(Config_t));
    }
}