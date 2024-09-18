/* 
 * File:   ADC.c
 * Author: IslamSameh2025
 *
 * Created on July 6, 2024, 4:34 PM
 */
#include "ADC.h"
static InterruptHandler ADC_InterruptHandler =NULL;
static void Channel_Configure_Input(chanel_select_t channel);

STD_RETURN ADC_Init(const ADC_CONF_t *adc){
    STD_RETURN ret =RETURN_OK;
    if(NULL==adc)
        ret=RETURN_NOT_OK;
    else
    {
        ADC_DISABLE();
        ADC_PINS_ANALOG(adc->pins);
        if((adc->result_justifcation)==ADC_RESULT_FORMAT_RIGHT)
            ADC_RESULT_FORMAT_RIGHT_JUSTFIED();
        else 
            ADC_RESULT_FORMAT_left_JUSTFIED();
        if((adc->voltage_reference)==ADC_VDD_VSS_CONFIGURATION)
            ADC_VDD_VSS_CONFIGURE();
        else
            ADC_VREF_CONFIGURE();
        ADC_ACQUISITION_TIME_SET(adc->time_acquisition);
        ADC_CONVERSION_CLOCK_SET(adc->clock_select);
        ADC_SELECT_CHANNEL(adc->adc_channel);
        Channel_Configure_Input(adc->adc_channel);
#if ADC_INTERRUPT_FEATURE_ENABLE==ACTIVATED
        ADC_INTERRUPT_ENABLE();
#if INTERRUPT_PRIORITY_ACTIVATION==ACTIVATED
        INTERRUPT_PRIORITY_FEATURE_ACTIVATE();
        if(adc->priority==INTERRUPT_HIGH_PRIORITY)
        {
        INTERRUPT_HIGH_PRIORITY_ACTIVATE();
        ADC_INTERRUPT_HIGH_PRIORITY();
        }
        else
        {
        INTERRUPT_LOW_PRIORITY_ACTIVATE();
        ADC_INTERRUPT_LOW_PRIORITY();
        }
#else
        INTERRUPT_GLOBAL_ACTIVATE();
        INTERRUPT_PERIPHERAL_ACTIVATE();
        
#endif
#endif
        ADC_ENABLE();
    }




    return ret;
}
STD_RETURN ADC_DeInit(const ADC_CONF_t *adc){
    STD_RETURN ret =RETURN_OK;
    if(NULL==adc)
        ret=RETURN_NOT_OK;
    else
    {
#if ADC_INTERRUPT_FEATURE_ENABLE==ACTIVATED
        ADC_INTERRUPT_DISABLE();
#endif
        ADC_DISABLE();
    }
    return ret;
}
STD_RETURN ADC_GetConversion_Blocking(const ADC_CONF_t *adc,chanel_select_t channel, 
                                 uint16 *conversion_result){
    STD_RETURN ret =RETURN_OK;
    if((NULL==adc)||(NULL==conversion_result))
        ret=RETURN_NOT_OK;
    else
    {
        ADC_SELECT_CHANNEL(channel);
        Channel_Configure_Input(channel);
        ADC_CONVERSTION_START();
        while(ADC_CONVERSTION_STATUS());
        ADC_GET_Result(adc,conversion_result);
    }
    return ret;
}
#if ADC_INTERRUPT_FEATURE_ENABLE==ACTIVATED
STD_RETURN ADC_StartConversion_Interrupt(const ADC_CONF_t *adc, chanel_select_t channel){
    STD_RETURN ret =RETURN_OK;
    if(NULL==adc)
        ret=RETURN_NOT_OK;
    else
    {
        ADC_SELECT_CHANNEL(channel);
        Channel_Configure_Input(channel);
        ADC_InterruptHandler=adc->interrupt_handler;
        ADC_CONVERSTION_START();
    }
    return ret;
}
#endif
STD_RETURN ADC_GET_Result(const ADC_CONF_t *adc,uint16 *conversion_result){
    STD_RETURN ret =RETURN_OK;
    if((NULL==adc)||(NULL==conversion_result))
        ret=RETURN_NOT_OK;
    else
    {
        if((adc->result_justifcation)==ADC_RESULT_FORMAT_RIGHT)
            *conversion_result=(uint16)((ADRESH<<8)+ADRESL);
        else
            *conversion_result=(uint16)(((ADRESH<<8)+ADRESL)>>6);
        
    }
    return ret;
}
static void Channel_Configure_Input(chanel_select_t channel){
    switch(channel)
        {
            case ADC_CHANNE0:
                SET_BIT(TRISA,_TRISA_RA0_POSITION);
                break;
            case ADC_CHANNE1:
                SET_BIT(TRISA,_TRISA_RA1_POSITION);
                break;
            case ADC_CHANNE2:
                SET_BIT(TRISA,_TRISA_RA2_POSITION);
                break;
            case ADC_CHANNE3:
                SET_BIT(TRISA,_TRISA_RA3_POSITION);
                break;
            case ADC_CHANNE4:
                SET_BIT(TRISA,_TRISA_RA5_POSITION);
                break;
            case ADC_CHANNE5:
                SET_BIT(TRISE,_TRISE_RE0_POSITION);
                break;
            case ADC_CHANNE6:
                SET_BIT(TRISE,_TRISE_RE1_POSITION);
                break;
            case ADC_CHANNE7:
                SET_BIT(TRISE,_TRISE_RE2_POSITION);
                break;
            case ADC_CHANNE8:
                SET_BIT(TRISB,_TRISB_RB2_POSITION);
                break;
            case ADC_CHANNE9:
                SET_BIT(TRISB,_TRISB_RB3_POSITION);
                break;
            case ADC_CHANNE10:
                SET_BIT(TRISB,_TRISB_RB1_POSITION);
                break;
            case ADC_CHANNE11:
                SET_BIT(TRISB,_TRISB_RB4_POSITION);
                break;
            case ADC_CHANNE12:
                SET_BIT(TRISB,_TRISB_RB0_POSITION);
                break;
            default:;
        }   
}
#if ADC_INTERRUPT_FEATURE_ENABLE==ACTIVATED
void ADC_INTERRUPT_ISR(void){
    if(ADC_InterruptHandler)ADC_InterruptHandler();
}
#endif