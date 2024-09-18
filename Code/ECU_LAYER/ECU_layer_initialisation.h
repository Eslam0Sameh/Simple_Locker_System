/* 
 * File:   ECU_layer_initialisation.h
 * Author: es-IslamSameh2025
 *
 * Created on November 4, 2023, 12:50 AM
 */
#ifndef ECU_LAYER_INITIALISATION_H
#define	ECU_LAYER_INITIALISATION_H
#include "../MCAL_LAYER/GPIO/gpio.h"
#include "LED/led.h"
#include "PUSH_BUTTON/push_button.h"
#include "DC_motor/DC_motor.h"
#include "Relay/Relay.h"
#include "seven_segment/seven_segment.h"
#include "Keypad/keypad.h"
#include "Character_Lcd/LCD.h"
lcd_4bit_t lcd=
{   .En.direction=OUTPUT,
    .En.logic=HIGH,
    .En.port_index=PORT_D,
    .En.pin_index=PIN1,
    .RS.direction=OUTPUT,
    .RS.logic=HIGH,
    .RS.port_index=PORT_D,
    .RS.pin_index=PIN0,
    
    .pins[0].direction=OUTPUT,
    .pins[0].logic=HIGH,
    .pins[0].port_index=PORT_D,
    .pins[0].pin_index=PIN2,

    .pins[1].direction=OUTPUT,
    .pins[1].logic=HIGH,
    .pins[1].port_index=PORT_D,
    .pins[1].pin_index=PIN3,


    .pins[2].direction=OUTPUT,
    .pins[2].logic=HIGH,
    .pins[2].port_index=PORT_D,
    .pins[2].pin_index=PIN4,

    .pins[3].direction=OUTPUT,
    .pins[3].logic=HIGH,
    .pins[3].port_index=PORT_D,
    .pins[3].pin_index=PIN5,
};
keypad_t keyPad=
{
    .ROWS[0].direction=OUTPUT,
    .ROWS[0].logic=LOW,
    .ROWS[0].port_index=PORT_C,
    .ROWS[0].pin_index=PIN0,
    
    .ROWS[1].direction=OUTPUT,
    .ROWS[1].logic=LOW,
    .ROWS[1].port_index=PORT_C,
    .ROWS[1].pin_index=PIN1,
    
    
    .ROWS[2].direction=OUTPUT,
    .ROWS[2].logic=LOW,
    .ROWS[2].port_index=PORT_C,
    .ROWS[2].pin_index=PIN2,
    
    .ROWS[3].direction=OUTPUT,
    .ROWS[3].logic=LOW,
    .ROWS[3].port_index=PORT_C,
    .ROWS[3].pin_index=PIN3,
    
    
    
    
    .COLS[0].direction=INPUT,
    .COLS[0].logic=LOW,
    .COLS[0].port_index=PORT_C,
    .COLS[0].pin_index=PIN4,
    
    .COLS[1].direction=INPUT,
    .COLS[1].logic=LOW,
    .COLS[1].port_index=PORT_C,
    .COLS[1].pin_index=PIN5,
    
    
    .COLS[2].direction=INPUT,
    .COLS[2].logic=LOW,
    .COLS[2].port_index=PORT_C,
    .COLS[2].pin_index=PIN6,
    
    .COLS[3].direction=INPUT,
    .COLS[3].logic=LOW,
    .COLS[3].port_index=PORT_C,
    .COLS[3].pin_index=PIN7,
    
};
led_t led_red=
{
    .led_status=LED_ON,
    .port_index=PORT_D,
    .pin_index=PIN7

};
led_t led_green=
{
    .led_status=LED_OFF,
    .port_index=PORT_D,
    .pin_index=PIN6

};

void ECU_layer_initialize(void);

#endif	/* ECU_LAYER_INITIALISATION_H */

