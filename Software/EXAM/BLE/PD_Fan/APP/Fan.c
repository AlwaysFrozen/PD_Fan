#include "CONFIG.h"
#include "Fan.h"

/*
    CH224 voltage set
    CFG1    CFG2    CFG3
    1       -       -       5v
    0       0       0       9v
    0       0       1       12v
    0       1       1       15v
    0       1       0       20v
*/

#define CFG1_PIN    GPIO_Pin_14
#define CFG2_PIN    GPIO_Pin_13
#define CFG3_PIN    GPIO_Pin_12

#define CFG1_H      GPIOA_SetBits(CFG1_PIN)
#define CFG1_L      GPIOA_ResetBits(CFG1_PIN)
#define CFG2_H      GPIOA_SetBits(CFG2_PIN)
#define CFG2_L      GPIOA_ResetBits(CFG2_PIN)
#define CFG3_H      GPIOA_SetBits(CFG3_PIN)
#define CFG3_L      GPIOA_ResetBits(CFG3_PIN)

#define PWM_FREQ    (25000)
#define PWM_CYCLE   (60000000 / PWM_FREQ)

static uint8_t pd_target_vol = 5;
static uint8_t fan_target_duty = 0;
static uint16_t RPM = 0;

void PD_Init(void)
{
    GPIOA_ModeCfg(GPIO_Pin_0,GPIO_ModeIN_Floating);
    ADC_ExtSingleChSampInit( SampleFreq_3_2, ADC_PGA_0 );

    CFG1_H;
    CFG2_L;
    CFG3_L;
    GPIOA_ModeCfg(CFG1_PIN | CFG2_PIN | CFG3_PIN,GPIO_ModeOut_PP_5mA);
}

void Set_PD_Vol(uint8_t vol)
{
    pd_target_vol = vol;

    switch(vol)
    {
        case 5:
            CFG1_H;
            CFG2_L;
            CFG3_L;
            break;

        case 9:
            CFG1_L;
            CFG2_L;
            CFG3_L;
            break;

        case 12:
            CFG1_L;
            CFG2_L;
            CFG3_H;
            break;

        case 15:
            CFG1_L;
            CFG2_H;
            CFG3_H;
            break;

        case 20:
            CFG1_L;
            CFG2_H;
            CFG3_L;
            break;

        default:
            break;
    }
}

uint8_t Get_PD_Vol(void)
{
    return pd_target_vol;
}

uint16_t Get_VBUS_Vol(void)
{
    uint16_t adc[2];
    uint16_t vol;

    ADC_ChannelCfg(0);
    ADC_ExcutSingleConver();
    adc[0] = ADC_ExcutSingleConver();
    adc[1] = ADC_ExcutSingleConver();
    // vol = (adc[0] + adc[1]) / 2 / 4095 * 2100 * ((100 + 10) / 10) ;
    vol = (adc[0] + adc[1]) * 2.8205128f;

    return vol;
}

void Fan_Init(void)
{
    GPIOPinRemap(ENABLE, RB_PIN_TMR1);
    GPIOPinRemap(ENABLE, RB_PIN_TMR2);
    GPIOB_ModeCfg(GPIO_Pin_10, GPIO_ModeOut_PP_20mA);
    GPIOB_ModeCfg(GPIO_Pin_11, GPIO_ModeIN_Floating);

    TMR1_PWMInit(High_Level, PWM_Times_1);
    TMR1_PWMCycleCfg(PWM_CYCLE);
    TMR1_Disable();
    TMR1_PWMActDataWidth(0);
    TMR1_Enable();

    TMR2_EXTSingleCounterInit(FallEdge_To_FallEdge);
    TMR2_CountOverflowCfg(0xfffffd);
}

void Set_Fan_Duty(uint8_t duty)
{
    fan_target_duty = duty;

    TMR1_PWMActDataWidth(PWM_CYCLE * duty / 100);
}

uint8_t Get_Fan_Duty(void)
{
    return fan_target_duty;
}

void Cal_Fan_RPM(uint32_t time_ms)
{
    uint16_t pulse_cnt = 0;

    pulse_cnt = TMR2_GetCurrentCount();
    //  clear count register
    TMR2_CountOverflowCfg(0xfffffd);

    RPM = pulse_cnt * 60000 / time_ms / 2;

    // PRINT("Cal_Fan_RPM %d %d\n",RPM,pulse_cnt);
}

uint16_t Get_Fan_RPM(void)
{
    return RPM;
}