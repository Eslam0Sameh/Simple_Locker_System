/* 
 * File:   Relay.c
 * Author: IslamSameh2025
 *
 * Created on October 31, 2023, 9:20 PM
 */
#include "Relay.h"
STD_RETURN relay_initialize(const relay_t * ptr){
    STD_RETURN ret=RETURN_NOT_OK;
    
    if((ptr->port_index==MAX_PORTS)||(ptr->pin_index==MAX_PINS)||(NULL==ptr)){ret=RETURN_NOT_OK ;}
    else
    {
       pin_config relay={
            .port_index=ptr->port_index,
            .direction=OUTPUT,
            .pin_index=ptr->pin_index,
            .logic=ptr->relay_status
        };
       gpio_pin_initialize(&relay); 
    
    return ret;
    }
}
STD_RETURN relay_turn_on(const relay_t * ptr)
{
    STD_RETURN ret=RETURN_NOT_OK;
    
    if((ptr->port_index==MAX_PORTS)||(ptr->pin_index==MAX_PINS)||(NULL==ptr)){ret=RETURN_NOT_OK ;}
    else
    {
       pin_config relay={
            .port_index=ptr->port_index,
            .direction=OUTPUT,
            .pin_index=ptr->pin_index,
            .logic=ptr->relay_status
        };
       gpio_pin_write(&relay,HIGH); 
    
    return ret;
    }
}
STD_RETURN relay_turn_off(const relay_t * ptr)
{
    STD_RETURN ret=RETURN_NOT_OK;
    
    if((ptr->port_index==MAX_PORTS)||(ptr->pin_index==MAX_PINS)||(NULL==ptr)){ret=RETURN_NOT_OK ;}
    else
    {
       pin_config relay={
            .port_index=ptr->port_index,
            .direction=OUTPUT,
            .pin_index=ptr->pin_index,
            .logic=ptr->relay_status
        };
       gpio_pin_write(&relay,LOW); 
    
    return ret;
    }
}
STD_RETURN relay_toggle(const relay_t * ptr)
{
    STD_RETURN ret=RETURN_NOT_OK;
    
    if((ptr->port_index==MAX_PORTS)||(ptr->pin_index==MAX_PINS)||(NULL==ptr)){ret=RETURN_NOT_OK ;}
    else
    {
       pin_config relay={
            .port_index=ptr->port_index,
            .direction=OUTPUT,
            .pin_index=ptr->pin_index,
            .logic=ptr->relay_status
        };
       gpio_pin_toggle(&relay); 
    
    return ret;
    }
}
