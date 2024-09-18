/* 
 * File:   ADC.h
 * Author: IslamSameh2025
 *
 * Created on July 6, 2024, 4:34 PM
 */

#ifndef ADC_H
#define	ADC_H
#include "../GPIO/gpio.h"
#include "ADC_CONF.h"
#include "../Interrupt/Interrupt_internal.h"
#include "../Interrupt/Interrupt_external.h"
#include "../proc/pic18f4620.h"
/*********************MACRO DECLARATIONS****************/
#define ADC_RESULT_FORMAT_RIGHT 1
#define ADC_RESULT_FORMAT_LEFT  0
#define ADC_CONVERSION_COMPLETED     0
#define ADC_CONVERSION_NOT_COMPLETED 1
/*********************MACRO FUNCTIONS DECLARATION*******/
#define ADC_SELECT_CHANNEL(x)        (ADCON0bits.CHS=x)
#define ADC_ENABLE()                 (ADCON0bits.ADON=1)
#define ADC_DISABLE()                (ADCON0bits.ADON=0)
#define ADC_CONVERSTION_START()      (ADCON0bits.GODONE=1)
#define ADC_CONVERSTION_STATUS()     (ADCON0bits.GODONE)
#define ADC_VREF_CONFIGURE()             do { \
                                        (ADCON1bits.VCFG1=1); \
                                        (ADCON1bits.VCFG0=1); \
                                        }while(0)

#define ADC_VDD_VSS_CONFIGURE()         do { \
                                        (ADCON1bits.VCFG1=0); \
                                        (ADCON1bits.VCFG0=0); \
                                        }while(0)
#define ADC_PINS_ANALOG(x)          (ADCON1bits.PCFG=x)
#define ADC_RESULT_FORMAT_RIGHT_JUSTFIED() (ADCON2bits.ADFM=1)
#define ADC_RESULT_FORMAT_left_JUSTFIED() (ADCON2bits.ADFM=0)
#define ADC_ACQUISITION_TIME_SET(x)         (ADCON2bits.ACQT=x)
#define ADC_CONVERSION_CLOCK_SET(x)         (ADCON2bits.ADCS=x)
/*********************DATA TYPE DECLARATION*************/
typedef enum{
    ADC_CHANNE0=0,
    ADC_CHANNE1,
    ADC_CHANNE2,
    ADC_CHANNE3,
    ADC_CHANNE4,
    ADC_CHANNE5,
    ADC_CHANNE6,
    ADC_CHANNE7,
    ADC_CHANNE8,
    ADC_CHANNE9,
    ADC_CHANNE10,
    ADC_CHANNE11,
    ADC_CHANNE12,
}chanel_select_t;
typedef enum{
    ADC_VDD_VSS_CONFIGURATION=0,
    ADC_VREF_CONFIGURATION        
}ADC_VOLTAGE_REFERENCE_SELECT_t;
/*for AN_n it means that the channels from AN_0 to AN_n is analog channels*/
typedef enum{
    ALL_ANALOG=2,
    AN_12=2,
    AN_11,
    AN_10,
    AN_9,
    AN_8,
    AN_7,
    AN_6,
    AN_5,
    AN_4,
    AN_3,
    AN_2,
    AN_1,
    AN_0,
    ALL_DIGITAL
}ANALOG_DIGITAL_SELECT_PINS_t;

typedef enum{
    TAD_0=0,
    TAD_2,
    TAD_4,
    TAD_6,
    TAD_8,
    TAD_12,
    TAD_16,
    TAD_20
}ADC_ACQUISITION_TIME_t;
typedef enum{
    FOSC_DIV_2=0,
    FOSC_DIV_8,
    FOSC_DIV_32,
    FRC,
    FOSC_DIV_4,
    FOSC_DIV_16,
    FOSC_DIV_64
}ADC_SELECT_CLOCK_t;
typedef struct {
#if ADC_INTERRUPT_FEATURE_ENABLE==ACTIVATED
    InterruptHandler interrupt_handler;
#if INTERRUPT_PRIORITY_ACTIVATION==ACTIVATED
    interrupt_priority_cfg priority;
#endif
#endif
    ADC_SELECT_CLOCK_t clock_select;
    ADC_ACQUISITION_TIME_t time_acquisition;
    chanel_select_t adc_channel;
    ADC_VOLTAGE_REFERENCE_SELECT_t voltage_reference;
    ANALOG_DIGITAL_SELECT_PINS_t   pins;
    uint8 result_justifcation ; //ADC_RESULT_FORMAT_RIGHT&ADC_RESULT_FORMAT_LEFT
}ADC_CONF_t;
/********************SOFTWARE INTERFACES DECLARATION****/

STD_RETURN ADC_Init(const ADC_CONF_t *adc);
STD_RETURN ADC_DeInit(const ADC_CONF_t *adc);
STD_RETURN ADC_GetConversion_Blocking(const ADC_CONF_t *adc, chanel_select_t channel, 
                                 uint16 *conversion_result);
STD_RETURN ADC_GET_Result(const ADC_CONF_t *adc,uint16 *conversion_result);
#if ADC_INTERRUPT_FEATURE_ENABLE==ACTIVATED
STD_RETURN ADC_StartConversion_Interrupt(const ADC_CONF_t *adc, chanel_select_t channel);
void ADC_INTERRUPT_ISR(void);

#endif

#endif	/* ADC_H */