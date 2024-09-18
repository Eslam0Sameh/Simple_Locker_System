/* 
 * File:   seven_segment.h
 * Author: es-IslamSameh2025
 *
 * Created on October 31, 2023, 10:25 PM
 */

#ifndef SEVEN_SEGMENT_H
#define	SEVEN_SEGMENT_H
#include "../../MCAL_LAYER/GPIO/gpio.h"
#include "seven_segment_config.h"
/************************************/
typedef enum {
    COMMON_ANODE=0,
    COMMON_CATHODE
}seven_segment_type;

typedef struct {
    uint8             port_index:4;
    uint8              pin_index:3;
    uint8               type    :1; //@ref to seven_segment_type
    
}seven_segment_activation_pin_t;
typedef struct {
    pin_config            pins[4];
}seven_segment_t;
STD_RETURN  seven_segment_initialize(const seven_segment_t * ptr);
STD_RETURN  seven_segment_write(const seven_segment_t * ptr,uint8 number);
STD_RETURN  seven_segment_activate(const seven_segment_activation_pin_t * ptr);
STD_RETURN  seven_segment_deactivate(const seven_segment_activation_pin_t * ptr);
STD_RETURN  seven_segment_activation_pin_initialize(const seven_segment_activation_pin_t * ptr);

#endif	/* SEVEN_SEGMENT_H */