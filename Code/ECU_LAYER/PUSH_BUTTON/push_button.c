#include "push_button.h"
STD_RETURN button_initialize(const button_t * ptr){
    STD_RETURN ret=RETURN_NOT_OK;
    
    if((ptr->port_index>=MAX_PORTS)||(ptr->pin_index>=MAX_PINS)||(NULL==ptr)){ret=RETURN_NOT_OK ;}
    else
    {
        pin_config button={
            .port_index=ptr->port_index,
            .direction=INPUT,
            .pin_index=ptr->pin_index,
            .logic=LOW
        };
        gpio_pin_direction_initialize(&button); 
    
        ret=RETURN_OK;
    }
    return ret;
}
STD_RETURN button_read(const button_t * ptr, button_status_t *ptr1){
    STD_RETURN ret=RETURN_NOT_OK;
    if((ptr->port_index>=MAX_PORTS)||(ptr->pin_index>=MAX_PINS)||(NULL==ptr)||(NULL==ptr1))
    {
        ret=RETURN_NOT_OK ;
    }
    else
    {
        pin_config button={
            .port_index=ptr->port_index,
            .direction=INPUT,
            .pin_index=ptr->pin_index,
            .logic=LOW};
        gpio_pin_read(&button,ptr1);
        if((ptr->connection)==PULL_UP){
            if((*ptr1==1))
            {*ptr1=pressed;}
            else {*ptr1=released;}
        
        } 
        else {
            if((*ptr1==0))
            {*ptr1=pressed;}
            else {*ptr1=released;}
            }
    
        ret=RETURN_OK;
    }
    return ret;  
}
