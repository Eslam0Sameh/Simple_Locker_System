/* 
 * File:   Relay.h
 * Author: IslamSameh2025
 *
 * Created on October 31, 2023, 9:20 PM
 */

#ifndef RELAY_H
#define	RELAY_H
#include "../../MCAL_LAYER/GPIO/gpio.h"
#include "Relay_config.h"
/***********************************/
typedef enum{

RELAY_ON  = HIGH,
RELAY_OFF = LOW
}relay_status;
typedef struct {
   uint8            port_index:4;
   uint8             pin_index:3;
   uint8            relay_status:1;
}relay_t;
STD_RETURN relay_initialize(const relay_t * ptr);
STD_RETURN relay_turn_on(const relay_t * ptr);
STD_RETURN relay_turn_off(const relay_t * ptr);
STD_RETURN relay_toggle(const relay_t * ptr);



#endif	/* RELAY_H */

