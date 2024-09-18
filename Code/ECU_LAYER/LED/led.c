#include "led.h"
STD_RETURN led_initialize(const led_t * ptr){
    STD_RETURN ret=RETURN_NOT_OK;
    
    if((ptr->port_index==MAX_PORTS)||(ptr->pin_index==MAX_PINS)||(NULL==ptr)){ret=RETURN_NOT_OK ;}
    else
    {
       pin_config led={
            .port_index=ptr->port_index,
            .direction=OUTPUT,
            .pin_index=ptr->pin_index,
            .logic=ptr->led_status
        };
       gpio_pin_initialize(&led); 
    
    return ret;
    }
}
STD_RETURN led_turn_on(const led_t * ptr)
{
    STD_RETURN ret=RETURN_NOT_OK;
    
    if((ptr->port_index==MAX_PORTS)||(ptr->pin_index==MAX_PINS)||(NULL==ptr)){ret=RETURN_NOT_OK ;}
    else
    {
       pin_config led={
            .port_index=ptr->port_index,
            .direction=OUTPUT,
            .pin_index=ptr->pin_index,
            .logic=ptr->led_status
        };
       gpio_pin_write(&led,HIGH); 
    
    return ret;
    }
}
STD_RETURN led_turn_off(const led_t * ptr)
{
    STD_RETURN ret=RETURN_NOT_OK;
    
    if((ptr->port_index==MAX_PORTS)||(ptr->pin_index==MAX_PINS)||(NULL==ptr)){ret=RETURN_NOT_OK ;}
    else
    {
       pin_config led={
            .port_index=ptr->port_index,
            .direction=OUTPUT,
            .pin_index=ptr->pin_index,
            .logic=ptr->led_status
        };
       gpio_pin_write(&led,LOW); 
    
    return ret;
    }
}
STD_RETURN led_toggle(const led_t * ptr)
{
    STD_RETURN ret=RETURN_NOT_OK;
    
    if((ptr->port_index==MAX_PORTS)||(ptr->pin_index==MAX_PINS)||(NULL==ptr)){ret=RETURN_NOT_OK ;}
    else
    {
       pin_config led={
            .port_index=ptr->port_index,
            .direction=OUTPUT,
            .pin_index=ptr->pin_index,
            .logic=ptr->led_status
        };
       gpio_pin_toggle(&led); 
    
    return ret;
    }
}