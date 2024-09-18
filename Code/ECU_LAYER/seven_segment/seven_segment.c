#include "seven_segment.h"
STD_RETURN  seven_segment_initialize(const seven_segment_t * ptr){
    STD_RETURN ret=RETURN_NOT_OK;
    if(NULL==ptr){ret=RETURN_NOT_OK ;}
    else
    {
        uint8 counter=0;
        for(counter=0;counter<4;counter++)
        {
        
            gpio_pin_initialize(&(ptr->pins[counter]));
        }
        ret=RETURN_OK;
    }
    return ret;
}
STD_RETURN  seven_segment_activate(const seven_segment_activation_pin_t * ptr){
    STD_RETURN ret=RETURN_NOT_OK;
    if(NULL==ptr){ret=RETURN_NOT_OK ;}
    else
    {
            pin_config activate_pin={
            .direction=OUTPUT,
            .logic=LOW,
            .port_index=ptr->port_index,
             .pin_index=ptr->pin_index
            };
            logic_t status =((ptr->type)==COMMON_ANODE)? HIGH :LOW ;
            gpio_pin_write(&activate_pin,status);
        ret=RETURN_OK;
    }
    return ret;

}

STD_RETURN  seven_segment_deactivate(const seven_segment_activation_pin_t * ptr){
    STD_RETURN ret=RETURN_NOT_OK;
    if(NULL==ptr){ret=RETURN_NOT_OK ;}
    else
    {
            pin_config activate_pin={
            .direction=OUTPUT,
            .logic=LOW,
            .port_index=ptr->port_index,
             .pin_index=ptr->pin_index
            };
            logic_t status =((ptr->type)==COMMON_ANODE)? LOW : HIGH ;
            gpio_pin_write(&activate_pin,status);
        ret=RETURN_OK;
    }
    return ret;
}
STD_RETURN  seven_segment_activation_pin_initialize(const seven_segment_activation_pin_t * ptr){
    STD_RETURN ret=RETURN_NOT_OK;
    if(NULL==ptr){ret=RETURN_NOT_OK ;}
    else
    {
            pin_config activate_pin={
            .direction=OUTPUT,
            .logic=((ptr->type) == COMMON_ANODE) ? LOW : HIGH,
            .port_index=ptr->port_index,
             .pin_index=ptr->pin_index
            };
            gpio_pin_initialize(&activate_pin);
  
        ret=RETURN_OK;
    }
    return ret;
}
STD_RETURN  seven_segment_write(const seven_segment_t * ptr,uint8 number){
    STD_RETURN ret=RETURN_NOT_OK;
    if(NULL==ptr){ret=RETURN_NOT_OK ;}
    else
    {
        uint8 counter=0;
        for(counter=0;counter<4;counter++)
        {
            gpio_pin_write(&(ptr->pins[counter]),READ_BIT(number,counter));
        }
        ret=RETURN_OK;
    }
    return ret;

}