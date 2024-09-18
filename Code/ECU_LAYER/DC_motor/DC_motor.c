#include "DC_motor.h"
STD_RETURN motor_initialize(const motor_t *ptr){
    STD_RETURN ret=RETURN_NOT_OK;
    
    if(((ptr->dcMotor[0].port_index)>=MAX_PORTS)||((ptr->dcMotor[1].port_index)>=MAX_PORTS)||((ptr->dcMotor[0].pin_index)>=MAX_PINS)||((ptr->dcMotor[1].pin_index)>=MAX_PINS)||(NULL==ptr)){ret=RETURN_NOT_OK ;}
    else
    {
        pin_config motor_pin1={
            .port_index=ptr->dcMotor[0].port_index,
            .direction=OUTPUT,
            .pin_index=ptr->dcMotor[0].pin_index,
            .logic=ptr->status
        };
        pin_config motor_pin2={
        .port_index=ptr->dcMotor[1].port_index,
        .direction=OUTPUT,
        .pin_index=ptr->dcMotor[1].pin_index,
        .logic=ptr->status
        };
        gpio_pin_direction_initialize(&motor_pin1); 
        gpio_pin_direction_initialize(&motor_pin2); 
        ret=RETURN_OK;
    }
    return ret;
}
STD_RETURN motor_rotate_right(const motor_t *ptr){
STD_RETURN ret=RETURN_NOT_OK;
    
    if(((ptr->dcMotor[0].port_index)>=MAX_PORTS)||((ptr->dcMotor[1].port_index)>=MAX_PORTS)||((ptr->dcMotor[0].pin_index)>=MAX_PINS)||((ptr->dcMotor[1].pin_index)>=MAX_PINS)||(NULL==ptr)){ret=RETURN_NOT_OK ;}
    else
    {
        pin_config motor_pin1={
            .port_index=ptr->dcMotor[0].port_index,
            .direction=OUTPUT,
            .pin_index=ptr->dcMotor[0].pin_index,
            .logic=ptr->status
        };
        pin_config motor_pin2={
        .port_index=ptr->dcMotor[1].port_index,
        .direction=OUTPUT,
        .pin_index=ptr->dcMotor[1].pin_index,
        .logic=ptr->status
        };
        gpio_pin_write(&motor_pin1,HIGH);
        gpio_pin_write(&motor_pin2,LOW) ;
        ret=RETURN_OK;
    }
    return ret;






}
STD_RETURN motor_rotate_left(const motor_t *ptr){
STD_RETURN ret=RETURN_NOT_OK;
    
    if(((ptr->dcMotor[0].port_index)>=MAX_PORTS)||((ptr->dcMotor[1].port_index)>=MAX_PORTS)||((ptr->dcMotor[0].pin_index)>=MAX_PINS)||((ptr->dcMotor[1].pin_index)>=MAX_PINS)||(NULL==ptr)){ret=RETURN_NOT_OK ;}
    else
    {
        pin_config motor_pin1={
            .port_index=ptr->dcMotor[0].port_index,
            .direction=OUTPUT,
            .pin_index=ptr->dcMotor[0].pin_index,
            .logic=ptr->status
        };
        pin_config motor_pin2={
        .port_index=ptr->dcMotor[1].port_index,
        .direction=OUTPUT,
        .pin_index=ptr->dcMotor[1].pin_index,
        .logic=ptr->status
        };
        gpio_pin_write(&motor_pin1,LOW);
        gpio_pin_write(&motor_pin2,HIGH); 
        ret=RETURN_OK;
    }
    return ret;






}
STD_RETURN motor_stop(const motor_t *ptr){
STD_RETURN ret=RETURN_NOT_OK;
    
    if(((ptr->dcMotor[0].port_index)>=MAX_PORTS)||((ptr->dcMotor[1].port_index)>=MAX_PORTS)||((ptr->dcMotor[0].pin_index)>=MAX_PINS)||((ptr->dcMotor[1].pin_index)>=MAX_PINS)||(NULL==ptr)){ret=RETURN_NOT_OK ;}
    else
    {
        pin_config motor_pin1={
            .port_index=ptr->dcMotor[0].port_index,
            .direction=OUTPUT,
            .pin_index=ptr->dcMotor[0].pin_index,
            .logic=ptr->status
        };
        pin_config motor_pin2={
        .port_index=ptr->dcMotor[1].port_index,
        .direction=OUTPUT,
        .pin_index=ptr->dcMotor[1].pin_index,
        .logic=ptr->status
        };
        gpio_pin_write(&motor_pin1,LOW);
        gpio_pin_write(&motor_pin2,LOW) ; 
        ret=RETURN_OK;
    }
    return ret;






}