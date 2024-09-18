/* 
 * File:   led.h
 * Author: es-IslamSameh2025
 *
 * Created on October 21, 2023, 11:51 PM
 */

#ifndef LED_H
#define	LED_H
#include "led_config.h"
#include "../../MCAL_LAYER/GPIO/gpio.h"
/*                  VARIABLES PROTOTYPE                  */
typedef enum{
    LED_OFF=0,
    LED_ON
}led_status_t;
typedef struct {
   uint8            port_index:4;
   uint8             pin_index:3;
   uint8            led_status:1;
}led_t;
/*             Interfaces              */
STD_RETURN led_initialize(const led_t * ptr);
STD_RETURN led_turn_on(const led_t * ptr);
STD_RETURN led_turn_off(const led_t * ptr);
STD_RETURN led_toggle(const led_t * ptr);
#endif	/* LED_H */

