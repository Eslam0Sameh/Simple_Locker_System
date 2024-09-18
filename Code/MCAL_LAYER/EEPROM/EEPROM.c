/* 
 * File:   EEPROM.h
 * Author: IslamSameh2025
 *
 * Created on July 2, 2024, 7:14 PM
 */
#include "EEPROM.h"
STD_RETURN EEPROM_MEMORY_WRITE(uint16 address,uint8 data)
{
    STD_RETURN ret=RETURN_OK;
    uint8 x,y;
    if((address<0)||(address>1023))
    {
        ret=RETURN_NOT_OK;
    }
    else
    {
        EEADRH=(uint8)((address>>8)&0x03);
        EEADR=(uint8)(address&0xFF);
        EEDATA=data;
        x=INTCONbits.GIEL;
        y=INTCONbits.GIEH;
        EECON1bits.EEPGD=0;
        EECON1bits.CFGS=0 ;
        EECON1bits.WREN=1 ;
        INTCONbits.GIEH=INTERRUPT_DISABLE;
        INTCONbits.GIEL=INTERRUPT_DISABLE;
        EECON2=0x55;
        EECON2=0xAA;
        EECON1bits.WR=1;
        while(EECON1bits.WR);
        EECON1bits.WREN=0 ;
        INTCONbits.GIEL=x;
        INTCONbits.GIEH=y;
        
            
  
        
        
    }
    
    return ret;



}
STD_RETURN EEPROM_MEMORY_READ(uint16 address,uint8 *data)
{
    STD_RETURN ret=RETURN_OK;

    if((address<0)||(address>1023)||(data==NULL))
    {
        ret=RETURN_NOT_OK;
    }
    else
    {
        EEADRH=(uint8)((address>>8)&0x03);
        EEADR=(uint8)(address&0xFF);
        EECON1bits.EEPGD=0;
        EECON1bits.CFGS=0 ;
        EECON1bits.RD=1;
        NOP();
        NOP();
        *data=EEDATA;   
    }
    return ret;   
}