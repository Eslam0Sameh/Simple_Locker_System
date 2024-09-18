#include "Interrupt_ISR.h"

#if INTERRUPT_PRIORITY_ACTIVATION == ACTIVATED
void __interrupt() ISR_HIGH(void)
{
    if((INTCONbits.INT0IE==INTERRUPT_ENABLE)&&(INTCONbits.INT0IF ==INTERRUPT_OCCUR))
    {
        INT0_FLAG_CLEAR();
        INT0_ISR();
        INT0_FLAG_CLEAR();
    }
    if((INTCON3bits.INT1IE==INTERRUPT_ENABLE)&&(INTCON3bits.INT1IF==INTERRUPT_OCCUR)&&(INTCON3bits.INT1IP==1))
    {   
        INT1_FLAG_CLEAR();
        INT1_ISR();
        INT1_FLAG_CLEAR();
    }
    if((INTCON3bits.INT2IE==INTERRUPT_ENABLE)&&(INTCON3bits.INT2IF==INTERRUPT_OCCUR)&&(INTCON3bits.INT2IP==1))
    {
        INT2_FLAG_CLEAR();
        INT2_ISR(); 
        INT2_FLAG_CLEAR();
    }
    if((INTCONbits.RBIE==INTERRUPT_ENABLE)&&(INTCONbits.RBIF==INTERRUPT_OCCUR))
    {
        RBX_INTERRUPT_CLEAR_FLAG();
         if((PORTB^portb_prev)&0x10)
         {
        RB4_ISR();
         }
        else if((PORTB^portb_prev)&0x20)
         {
        RB5_ISR();
         }
        else if((PORTB^portb_prev)&0x40)
         {
        RB6_ISR();
         }
        else if((PORTB^portb_prev)&0x80)
         {
        RB7_ISR();
         }
        
        RBX_INTERRUPT_CLEAR_FLAG();
        portb_prev=PORTB&0xF0;
    }
#if ADC_INTERRUPT_FEATURE_ENABLE==ACTIVATED
    if((PIE1bits.ADIE==INTERRUPT_ENABLE)&&(PIR1bits.ADIF ==INTERRUPT_OCCUR)&&(IPR1bits.ADIP==1))
    {
        ADC_INTERRUPT_FLAG_CLEAR();
        ADC_INTERRUPT_ISR();
        ADC_INTERRUPT_FLAG_CLEAR();
    }
#endif
}
void __interrupt(low_priority) ISR_LOW(void)
{
    if((INTCON3bits.INT1IE==INTERRUPT_ENABLE)&&(INTCON3bits.INT1IF==INTERRUPT_OCCUR)&&(INTCON3bits.INT1IP==0))
        INT1_FLAG_CLEAR();
        INT1_ISR();
        INT1_FLAG_CLEAR();
    if((INTCON3bits.INT2IE==INTERRUPT_ENABLE)&&(INTCON3bits.INT2IF==INTERRUPT_OCCUR)&&(INTCON3bits.INT2IP==0))
        INT2_FLAG_CLEAR();
        INT2_ISR();
        INT2_FLAG_CLEAR();
    if((INTCONbits.RBIE==INTERRUPT_ENABLE)&&(INTCONbits.RBIF==INTERRUPT_OCCUR)&&(IPR1bits.ADIP==0))
    {
        RBX_INTERRUPT_CLEAR_FLAG();
         if((PORTB^portb_prev)&&0x10)
         {
        RB4_ISR();
         }
        else if((PORTB^portb_prev)&&0x20)
         {
        RB5_ISR();
         }
        else if((PORTB^portb_prev)&&0x40)
         {
        RB6_ISR();
         }
        else if((PORTB^portb_prev)&&0x80)
         {
        RB7_ISR();
         }
        
        RBX_INTERRUPT_CLEAR_FLAG();
        portb_prev=PORTB;
    }
#if ADC_INTERRUPT_FEATURE_ENABLE==ACTIVATED
    if((PIE1bits.ADIE==INTERRUPT_ENABLE)&&(PIR1bits.ADIF ==INTERRUPT_OCCUR))
    {
        ADC_INTERRUPT_FLAG_CLEAR();
        ADC_INTERRUPT_ISR();
        ADC_INTERRUPT_FLAG_CLEAR();
    }
#endif
}
#else 
void __interrupt() ISR_NO_PRIORITY(void)
{
    
    if((INTCONbits.INT0IE==INTERRUPT_ENABLE)&&(INTCONbits.INT0IF ==INTERRUPT_OCCUR))
        INT0_ISR();
    
    if((INTCON3bits.INT1IE==INTERRUPT_ENABLE)&&(INTCON3bits.INT1IF==INTERRUPT_OCCUR))
        INT1_ISR();

    if((INTCON3bits.INT2IE==INTERRUPT_ENABLE)&&(INTCON3bits.INT2IF==INTERRUPT_OCCUR))
        INT2_ISR();
    if((INTCONbits.RBIE==INTERRUPT_ENABLE)&&(INTCONbits.RBIF==INTERRUPT_OCCUR))
    {
        RBX_INTERRUPT_CLEAR_FLAG();
         if((PORTB^portb_prev)&&0x10)
         {
        RB4_ISR();
         }
        else if((PORTB^portb_prev)&&0x20)
         {
        RB5_ISR();
         }
        else if((PORTB^portb_prev)&&0x40)
         {
        RB6_ISR();
         }
        else if((PORTB^portb_prev)&&0x80)
         {
        RB7_ISR();
         }
        
        RBX_INTERRUPT_CLEAR_FLAG();
        portb_prev=PORTB;
    }
#if ADC_INTERRUPT_FEATURE_ENABLE==ACTIVATED
    if((PIE1bits.ADIE==INTERRUPT_ENABLE)&&(PIR1bits.ADIF ==INTERRUPT_OCCUR))
    {
        ADC_INTERRUPT_FLAG_CLEAR();
        ADC_INTERRUPT_ISR();
        ADC_INTERRUPT_FLAG_CLEAR();
    }
#endif
}
#endif