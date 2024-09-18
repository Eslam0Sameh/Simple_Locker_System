#include "ECU_layer_initialisation.h"

 void ECU_layer_initialize(void)
{
     led_initialize(&led_red);
     led_initialize(&led_green);
     lcd_4bit_initialize(&lcd) ;
     keypad_initialize(&keyPad);
     
}
