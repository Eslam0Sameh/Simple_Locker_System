/* 
 * File:   application.c
 * Author: IslamSameh2025
 *
 * Created on October 21, 2023, 11:46 PM
 */
#include "application.h"
#include "MCAL_LAYER/Interrupt/Interrupt_external.h"
void app_isr (void);
volatile uint8 password[4]="1234";
volatile uint8 array[4]= "@@@@";
volatile uint8 x;
volatile uint8 y;
volatile uint8 counter=0;
interrupt_INTx_t Interrupt =
{
    .EXT_InterruptHandler=app_isr,
    .edge=INTERRUPT_RISING_EDGE,
    .priority=INTERRUPT_LOW_PRIORITY,
    .source=INTERRUPT_EXTERNAL_INT1
};
int main() {
    
    application_initialize();
    lcd_4bit_send_command(&lcd,_LCD_CLEAR);
    lcd_4bit_send_string_at_position(&lcd,"ENTER_PASSWORD:",2,1);
    PORTC|=0x0F;

    __delay_ms(500);
while(1)
{
    
}
return (0);
}
void application_initialize(void)
{
    Interrupt_INTx_Init(&Interrupt);
    ECU_layer_initialize();
}
void app_isr (void)
{
    keypad_get_value(&keyPad,&x);
    if((counter>=0)&&(counter<=3))
    {
        array[counter]=x;
        counter++;
        lcd_4bit_send_data_at_position(&lcd,array[counter-1],2,counter+16);
        __delay_ms(500);
        lcd_4bit_send_string_at_position(&lcd,"*",2,counter+16);
    }
    if(counter==4)
    {
        for(counter=0;counter<=3;counter++)
            y+=password[counter]==array[counter];
        if(y==4)
        {
            counter=0;
            lcd_4bit_send_command(&lcd,_LCD_CLEAR);
            lcd_4bit_send_string_at_position(&lcd,"PASSWORD_IS_CORRECT",2,2);
            Interrupt_INTx_DeInit(&Interrupt);
            led_turn_on(&led_green);
            led_turn_off(&led_red);
            while(1);
            
        
        }
        else
        {
            counter=0;
            lcd_4bit_send_command(&lcd,_LCD_CLEAR);
            lcd_4bit_send_string_at_position(&lcd,"PASSWORD_IS_WRONG",2,2);
            __delay_ms(3000);
            lcd_4bit_send_command(&lcd,_LCD_CLEAR);
            lcd_4bit_send_string_at_position(&lcd,"ENTER_PASSWORD:",2,1);
        
        }
        y=0;
            
            
            
    }
    PORTC|=0x0F;
    while(PORTBbits.RB1);
}

/* this is the latest update 
 * when pressing the number for while 
 * it may be considered twice press for
 * example if i press number 2 for one second it will write
 *  22 and if i press for 2 seconds it will write 2222
 * this problem solved by change writing 0x0f to port c in infinite 
 * while loop to be written in ISR by this we can  make the ISR not 
 * finished as HIGH voltage in interrupt be cleared ,this  make 
 * one press as time as we want is just one number written 
 * we had to make "PORTC|=0x0F;" in ISR not while to check INT1 status
 * after finishing the interrupt , in other words if we make the 
 * "PORTC|=0x0F;" in while as it was and check in ISR it will not 
 * response such the input of the keypad in this instant
 * is low voltage so the output is low also but if we exit from
 * ISR and while pressing it will go to ISR again by the first
 * press (the press that takes more time)
 
 
 
 */
/* THE OLD CODE */
/* 
 * File:   application.c
 * Author: IslamSameh2025
 *
 * Created on October 21, 2023, 11:46 PM
 */
/*
#include "application.h"
#include "MCAL_LAYER/Interrupt/Interrupt_external.h"
void app_isr (void);
volatile uint8 password[4]="1234";
volatile uint8 array[4]= "@@@@";
volatile uint8 x;
volatile uint8 y;
volatile uint8 counter=0;
interrupt_INTx_t Interrupt =
{
    .EXT_InterruptHandler=app_isr,
    .edge=INTERRUPT_RISING_EDGE,
    .priority=INTERRUPT_LOW_PRIORITY,
    .source=INTERRUPT_EXTERNAL_INT1
};
int main() {
    
    application_initialize();
    lcd_4bit_send_command(&lcd,_LCD_CLEAR);
    lcd_4bit_send_string_at_position(&lcd,"ENTER_PASSWORD:",2,1);

    __delay_ms(500);
while(1)
{
    PORTC|=0x0F;
}
return (0);
}
void application_initialize(void)
{
    Interrupt_INTx_Init(&Interrupt);
    ECU_layer_initialize();
}
void app_isr (void)
{
    keypad_get_value(&keyPad,&x);
    if((counter>=0)&&(counter<=3))
    {
        array[counter]=x;
        counter++;
        lcd_4bit_send_data_at_position(&lcd,array[counter-1],2,counter+16);
        __delay_ms(500);
        lcd_4bit_send_string_at_position(&lcd,"*",2,counter+16);
    }
    if(counter==4)
    {
        for(counter=0;counter<=3;counter++)
            y+=password[counter]==array[counter];
        if(y==4)
        {
            counter=0;
            lcd_4bit_send_command(&lcd,_LCD_CLEAR);
            lcd_4bit_send_string_at_position(&lcd,"PASSWORD_IS_CORRECT",2,2);
            Interrupt_INTx_DeInit(&Interrupt);
            led_turn_on(&led_green);
            led_turn_off(&led_red);
            while(1);
            
        
        }
        else
        {
            counter=0;
            lcd_4bit_send_command(&lcd,_LCD_CLEAR);
            lcd_4bit_send_string_at_position(&lcd,"PASSWORD_IS_WRONG",2,2);
            __delay_ms(3000);
            lcd_4bit_send_command(&lcd,_LCD_CLEAR);
            lcd_4bit_send_string_at_position(&lcd,"ENTER_PASSWORD:",2,1);
        
        }
        y=0;
            
            
            
    }
        






}
*/