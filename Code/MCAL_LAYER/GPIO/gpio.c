#include "gpio.h" 
/*we create an array of pointers such if we use the values directly it will act
  incorrectly for example if we write 
PORT_REG[]={PORTA,PORTB,PORTC,PORTD,PORTE};
 * 
 * this is wrong such the values in the array is instantenous for example
 * 3 4 5 6 7 
 * but when using pointer we get the address and get the value in instant 
 * we want
 */
volatile uint8 *PORT_REG[]={&PORTA,&PORTB,&PORTC,&PORTD,&PORTE};
volatile uint8 *LAT_REG[]={&LATA,&LATB,&LATC,&LATD,&LATE};
volatile uint8 *TRIS_REG[]={&TRISA,&TRISB,&TRISC,&TRISD,&TRISE};
#include "gpio.h"
STD_RETURN gpio_port_direction_initialize(port_index_t port,uint8 direction){
    STD_RETURN ret=RETURN_NOT_OK;
    if(port>=MAX_PORTS){ret=RETURN_NOT_OK;}
    else
    {
        *TRIS_REG[port]=direction;
        ret=RETURN_OK;
    }
    return ret;
}
STD_RETURN gpio_port_write(port_index_t port,uint8 logic)
{
    STD_RETURN ret=RETURN_NOT_OK; 
    if(port>=MAX_PORTS){ret=RETURN_NOT_OK;}
    else
    {
        *LAT_REG[port]=logic;
        ret=RETURN_OK;
    }
    return ret;
}

STD_RETURN gpio_port_read(port_index_t port,uint8 *ptr){

    STD_RETURN ret=RETURN_NOT_OK;
    if((port>=MAX_PORTS)||(NULL==ptr)){ret=RETURN_NOT_OK;}
    else
    {
        *ptr=*PORT_REG[port];
        ret=RETURN_OK;
    }
    return ret;
}
STD_RETURN gpio_port_toggle(port_index_t port){
    STD_RETURN ret=RETURN_NOT_OK;
    if(port>=MAX_PORTS){ret=RETURN_NOT_OK;}
    else
    {
        *LAT_REG[port]^=PORT_MASK;
        ret=RETURN_OK;
    } 
    return ret;

}
STD_RETURN gpio_port_direction_read(port_index_t port,uint8 *ptr){


    STD_RETURN ret=RETURN_NOT_OK;
    if((port>=MAX_PORTS)||(NULL==ptr)){ret=RETURN_NOT_OK;}
    else
    {
        *ptr=*TRIS_REG[port];
        ret=RETURN_OK;
    }
    return ret;



}
/*            PIN INTERFACES            */
STD_RETURN gpio_pin_direction_initialize(const pin_config * ptr){

    STD_RETURN ret=RETURN_NOT_OK;
    if((ptr->port_index>=MAX_PORTS)||(ptr->pin_index>=MAX_PINS)||(NULL==ptr))
    {
        ret=RETURN_NOT_OK;
    }
    else
    {
        if((ptr->direction)==INPUT){
            SET_BIT(*TRIS_REG[ptr->port_index],ptr->pin_index);
        }
        else{
            CLEAR_BIT(*TRIS_REG[ptr->port_index],ptr->pin_index);
        }
        ret=RETURN_OK;
    }
    return ret;
}
STD_RETURN gpio_pin_direction_read(const pin_config * ptr,direction_t * ptr1){

    STD_RETURN ret= RETURN_NOT_OK ;
    if((ptr->port_index>=MAX_PORTS)||(ptr->pin_index>=MAX_PINS)||(NULL==ptr)||(NULL==ptr1)){ret=RETURN_NOT_OK ;}
    else
    {
        
        *ptr1=READ_BIT(*LAT_REG[ptr->port_index],ptr->pin_index);
        ret=RETURN_OK;
    }
    return ret;
}
STD_RETURN gpio_pin_write(const pin_config * ptr,logic_t logic){

STD_RETURN ret=RETURN_NOT_OK;
    if(NULL==ptr){ret=RETURN_NOT_OK ;}
    else
    {
        if(logic==HIGH){SET_BIT(*LAT_REG[ptr->port_index],ptr->pin_index);}
        else{CLEAR_BIT(*LAT_REG[ptr->port_index],ptr->pin_index);}
        ret=RETURN_OK;
    }
    return ret;
}
    STD_RETURN gpio_pin_toggle(const pin_config * ptr){
    STD_RETURN ret=RETURN_NOT_OK;
    if((ptr->port_index>=MAX_PORTS)||(ptr->pin_index>=MAX_PINS)||(NULL==ptr)){ret=RETURN_NOT_OK ;}
    else
    {
        TOGGLE_BIT(*LAT_REG[ptr->port_index],ptr->pin_index);
        ret=RETURN_OK;
        
    }
    return ret;
    }
    STD_RETURN gpio_pin_read(const pin_config * ptr,logic_t * ptr1){
    
    STD_RETURN ret=RETURN_NOT_OK;
    if((ptr->port_index>=MAX_PORTS)||(ptr->pin_index>=MAX_PINS)||(NULL==ptr)||(NULL==ptr1)){ret=RETURN_NOT_OK ;}
    else
    {
        
        *ptr1=READ_BIT(*PORT_REG[ptr->port_index],ptr->pin_index);
        ret=RETURN_OK;
    }
    return ret;
    }
    STD_RETURN gpio_pin_initialize(const pin_config * ptr){
    
    STD_RETURN ret=RETURN_NOT_OK;
    if((ptr->port_index>=MAX_PORTS)||(ptr->pin_index>=MAX_PINS)||(NULL==ptr)){ret=RETURN_NOT_OK ;}
    else
    {
        gpio_pin_direction_initialize(ptr);
        gpio_pin_write(ptr,ptr->logic);
        ret=RETURN_OK;  
    }
    return ret;
    
    
    
    
    
    
    }