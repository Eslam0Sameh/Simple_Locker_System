#if 1
#include "Interrupt_external.h"
#include "Interrupt_ISR.h"
#include "Interrupt_conf.h"
#include "Interrupt_declaration.h"
#include "Interrupt_internal.h"
#endif
#if 1
static InterruptHandler INT0_InterruptHandler =NULL;
static InterruptHandler INT1_InterruptHandler =NULL;
static InterruptHandler INT2_InterruptHandler =NULL;
static InterruptHandler RBx4_InterruptHandler_HIGH =NULL;
static InterruptHandler RBx4_InterruptHandler_LOW =NULL;
static InterruptHandler RBx5_InterruptHandler_HIGH =NULL;
static InterruptHandler RBx5_InterruptHandler_LOW =NULL;
static InterruptHandler RBx6_InterruptHandler_HIGH =NULL;
static InterruptHandler RBx6_InterruptHandler_LOW =NULL;
static InterruptHandler RBx7_InterruptHandler_HIGH =NULL;
static InterruptHandler RBx7_InterruptHandler_LOW =NULL;
#endif
#if 1
static STD_RETURN Interrupt_INTx_Enable           (const interrupt_INTx_t *int_obj);
static STD_RETURN Interrupt_INTx_Disable          (const interrupt_INTx_t *int_obj);
static STD_RETURN Interrupt_INTx_Clear_Flag       (const interrupt_INTx_t *int_obj);
static STD_RETURN Interrupt_INTx_Edge_Set         (const interrupt_INTx_t *int_obj);
#if INTERRUPT_PRIORITY_ACTIVATION==ACTIVATED
static STD_RETURN Interrupt_INTx_Priority_Set     (const interrupt_INTx_t *int_obj);
#endif
static STD_RETURN Interrupt_INTx_Pin_Configure    (const interrupt_INTx_t *int_obj);
static STD_RETURN Interrupt_INTx_Handler_Set      (const interrupt_INTx_t *int_obj);
#endif
#if 1
/*ON change interrupt helper functions*/
static STD_RETURN Interrupt_RBx_Pin_Configure    (const interrupt_RBx_t *int_obj);
static STD_RETURN Interrupt_RBx_Handler_Set      (const interrupt_RBx_t *int_obj);
#endif
#if 1
STD_RETURN Interrupt_INTx_Init(const interrupt_INTx_t *int_obj){
    
    Interrupt_INTx_Disable          (int_obj);
    Interrupt_INTx_Clear_Flag       (int_obj);
    Interrupt_INTx_Edge_Set         (int_obj);
    Interrupt_INTx_Pin_Configure    (int_obj);
#if INTERRUPT_PRIORITY_ACTIVATION==ACTIVATED
    INTERRUPT_PRIORITY_FEATURE_ACTIVATE();
    Interrupt_INTx_Priority_Set     (int_obj);
#else
    INTERRUPT_GLOBAL_ACTIVATE() ;
    INTERRUPT_PERIPHERAL_ACTIVATE() ;
#endif
    Interrupt_INTx_Handler_Set      (int_obj);
    Interrupt_INTx_Enable           (int_obj);
}
STD_RETURN Interrupt_INTx_DeInit(const interrupt_INTx_t *int_obj){
    Interrupt_INTx_Clear_Flag       (int_obj);
    Interrupt_INTx_Disable          (int_obj);
}
static STD_RETURN Interrupt_INTx_Enable           (const interrupt_INTx_t *int_obj){
    STD_RETURN ret = RETURN_OK;
    if( NULL == int_obj)
    {ret=RETURN_NOT_OK;}
    else
    {
    switch(int_obj->source)
    {
        case INTERRUPT_EXTERNAL_INT0 :
             INT0_ENABLE();
             break;
        
        case INTERRUPT_EXTERNAL_INT1 :
             INT1_ENABLE();
             break;
             
        case INTERRUPT_EXTERNAL_INT2 :
             INT2_ENABLE();
             break;
    
        default : 
            ret=RETURN_NOT_OK;
    }
    }
    return ret;
}
static STD_RETURN Interrupt_INTx_Disable          (const interrupt_INTx_t *int_obj){
    STD_RETURN ret = RETURN_OK;
    if(NULL == int_obj)
    {ret=RETURN_NOT_OK;}
    else
    {
    switch(int_obj->source)
    {
        case INTERRUPT_EXTERNAL_INT0 :
             INT0_DISABLE();
             break;
        
        case INTERRUPT_EXTERNAL_INT1 :
             INT1_DISABLE();
             break;
             
        case INTERRUPT_EXTERNAL_INT2 :
             INT2_DISABLE();
             break;
    
        default : 
            ret=RETURN_NOT_OK;
    }
    }
    return ret;
}
static STD_RETURN Interrupt_INTx_Clear_Flag       (const interrupt_INTx_t *int_obj){
    STD_RETURN ret = RETURN_OK;
    if(NULL == int_obj)
    {ret=RETURN_NOT_OK;}
    else
    {
    switch(int_obj->source)
    {
        case INTERRUPT_EXTERNAL_INT0 :
             INT0_FLAG_CLEAR();
             break;
        
        case INTERRUPT_EXTERNAL_INT1 :
             INT1_FLAG_CLEAR();
             break;
             
        case INTERRUPT_EXTERNAL_INT2 :
             INT2_FLAG_CLEAR();
             break;
    
        default : 
            ret=RETURN_NOT_OK;
    }
    }
    return ret;
}
static STD_RETURN Interrupt_INTx_Edge_Set         (const interrupt_INTx_t *int_obj){
    STD_RETURN ret = RETURN_OK;
    if(NULL == int_obj)
    {ret=RETURN_NOT_OK;}
    else
    {
    switch(int_obj->source)
    {
        case INTERRUPT_EXTERNAL_INT0 :
            if(int_obj->edge==INTERRUPT_RISING_EDGE)
            {INT0_RISING_EDGE_SET();}
            else
                INT0_FALLING_EDGE_SET();
             break;
        
        case INTERRUPT_EXTERNAL_INT1 :

            if(int_obj->edge==INTERRUPT_RISING_EDGE)
            {INT1_RISING_EDGE_SET();}
            else
                INT1_FALLING_EDGE_SET();
             break;
             
        case INTERRUPT_EXTERNAL_INT2 :
            
             if(int_obj->edge==INTERRUPT_RISING_EDGE)
             {INT2_RISING_EDGE_SET();}
            else
                INT2_FALLING_EDGE_SET();
             break;
    
        default : 
            ret=RETURN_NOT_OK;
    }
    }
    return ret;
}
#if INTERRUPT_PRIORITY_ACTIVATION==ACTIVATED
static STD_RETURN Interrupt_INTx_Priority_Set     (const interrupt_INTx_t *int_obj){
    STD_RETURN ret = RETURN_OK;
    if(NULL == int_obj)
    {ret=RETURN_NOT_OK;}
    else
    {
    switch(int_obj->source)
    {
        case INTERRUPT_EXTERNAL_INT0 :
            INTERRUPT_HIGH_PRIORITY_ACTIVATE();
            INT1_HIGH_PRIORITY_SET();
            break;
            
        case INTERRUPT_EXTERNAL_INT1 :
            if(int_obj->priority==INTERRUPT_HIGH_PRIORITY)
            {INTERRUPT_HIGH_PRIORITY_ACTIVATE();
            INT1_HIGH_PRIORITY_SET();}
            else
            {
                /*
                 * in case of low priority interrupt we also 
                 * set GIEH because irrespective to the value
                 * of IPEN if GIEH equals to zero , it disables 
                 * all interrupt even low priority
                 */
                INTERRUPT_HIGH_PRIORITY_ACTIVATE();
                INTERRUPT_LOW_PRIORITY_ACTIVATE();
                INT1_LOW_PRIORITY_SET();
            }
             break;
             
        case INTERRUPT_EXTERNAL_INT2 :
            
             if(int_obj->priority==INTERRUPT_HIGH_PRIORITY)
             {INTERRUPT_HIGH_PRIORITY_ACTIVATE();
             INT2_HIGH_PRIORITY_SET();}
            else
            {   INTERRUPT_HIGH_PRIORITY_ACTIVATE();
                 INTERRUPT_LOW_PRIORITY_ACTIVATE();
                INT2_LOW_PRIORITY_SET();
            }
             break;
    
        default : 
            ret=RETURN_NOT_OK;
    }
    }
    return ret;
}
#else
        INTERRUPT_GLOBAL_ACTIVATE    ();
        INTERRUPT_PERIPHERAL_ACTIVATE();
#endif

static STD_RETURN Interrupt_INTx_Pin_Configure    (const interrupt_INTx_t *int_obj){
    STD_RETURN ret = RETURN_OK;
    if(NULL == int_obj)
    {ret=RETURN_NOT_OK;}
    else
    {
        pin_config pin;
    switch(int_obj->source)
    {
        case INTERRUPT_EXTERNAL_INT0 :
            pin.direction=INPUT;
            pin.port_index=PORT_B;
            pin.pin_index=PIN0;
            gpio_pin_initialize(&pin);
            
             break;
        
        case INTERRUPT_EXTERNAL_INT1 :
                pin.direction=INPUT;
                pin.port_index=PORT_B;
                pin.pin_index=PIN1;
                gpio_pin_initialize(&pin);
             break;
             
        case INTERRUPT_EXTERNAL_INT2 :
            
                   pin.direction=INPUT;
                   pin.port_index=PORT_B;
                   pin.pin_index=PIN2;
                   gpio_pin_initialize(&pin);
             break;
    
        default : 
            ret=RETURN_NOT_OK;
    }
    }
    return ret;
}
static STD_RETURN Interrupt_INTx_Handler_Set      (const interrupt_INTx_t *int_obj){
    STD_RETURN ret = RETURN_OK;
    if(NULL == int_obj)
    {ret=RETURN_NOT_OK;}
    else
    {
    switch(int_obj->source)
    {
        case INTERRUPT_EXTERNAL_INT0 :
            INT0_InterruptHandler=int_obj->EXT_InterruptHandler;
             break;
        
        case INTERRUPT_EXTERNAL_INT1 :
            INT1_InterruptHandler=int_obj->EXT_InterruptHandler;
             break;
             
        case INTERRUPT_EXTERNAL_INT2 :
            INT2_InterruptHandler=int_obj->EXT_InterruptHandler;
             break;
    
        default : 
            ret=RETURN_NOT_OK;
    }
    }
    return ret;
}
#endif
#if 1
STD_RETURN Interrupt_RBx_Init(const interrupt_RBx_t *int_obj){

STD_RETURN ret = RETURN_OK;
    if( NULL == int_obj)
    {ret=RETURN_NOT_OK;}
    else
    {
        RBX_INTERRUPT_DISABLE(); 
        RBX_INTERRUPT_CLEAR_FLAG();
#if INTERRUPT_PRIORITY_ACTIVATION==ACTIVATED
        (RCONbits.IPEN=1);
        if(int_obj->priority==INTERRUPT_HIGH_PRIORITY)
        {
            INTERRUPT_HIGH_PRIORITY_ACTIVATE() ;
            RBX_INTERRUPT_HIGH_PRIORITY_SET()  ;
        }
        else
        { 
            INTERRUPT_HIGH_PRIORITY_ACTIVATE() ;
            INTERRUPT_LOW_PRIORITY_ACTIVATE();
            RBX_INTERRUPT_LOW_PRIORITY_SET()  ;
        }
#else
        INTERRUPT_GLOBAL_ACTIVATE    ();
        INTERRUPT_PERIPHERAL_ACTIVATE();
#endif
        Interrupt_RBx_Pin_Configure(int_obj);
        Interrupt_RBx_Handler_Set(int_obj);
        
        RBX_INTERRUPT_ENABLE();         
        portb_prev=PORTB&0xF0;
    }
    return ret;

}
STD_RETURN Interrupt_RBx_DeInit(const interrupt_RBx_t *int_obj){

STD_RETURN ret = RETURN_OK;
    if( NULL == int_obj)
    {ret=RETURN_NOT_OK;}
    else
    {
        RBX_INTERRUPT_CLEAR_FLAG();
        RBX_INTERRUPT_DISABLE();         
    }
    return ret;
}

static STD_RETURN Interrupt_RBx_Pin_Configure    (const interrupt_RBx_t *int_obj)
{
STD_RETURN ret = RETURN_OK;
    if(NULL == int_obj)
    {ret=RETURN_NOT_OK;}
    else
    {
    pin_config pin;
    switch(int_obj->source)
    {
        case INTERRUPT_EXTERNAL_RBx4 :
            pin.direction=INPUT;
            pin.port_index=PORT_B;
            pin.pin_index=PIN4;
            gpio_pin_initialize(&pin);
            
             break;
        
        case INTERRUPT_EXTERNAL_RBx5 :
                pin.direction=INPUT;
                pin.port_index=PORT_B;
                pin.pin_index=PIN5;
                gpio_pin_initialize(&pin);
             break;
             
        case INTERRUPT_EXTERNAL_RBx6 :
            
                   pin.direction=INPUT;
                   pin.port_index=PORT_B;
                   pin.pin_index=PIN6;
                   gpio_pin_initialize(&pin);
             break;
        case INTERRUPT_EXTERNAL_RBx7 :
            
                   pin.direction=INPUT;
                   pin.port_index=PORT_B;
                   pin.pin_index=PIN7;
                   gpio_pin_initialize(&pin);
             break;
    
        default : 
            ret=RETURN_NOT_OK;
    }
    }
    return ret;

}
static STD_RETURN Interrupt_RBx_Handler_Set      (const interrupt_RBx_t *int_obj)
{
STD_RETURN ret = RETURN_OK;
    if(NULL == int_obj)
    {ret=RETURN_NOT_OK;}
    else
    {
    switch(int_obj->source)
    {
        case INTERRUPT_EXTERNAL_RBx4 :
            
                RBx4_InterruptHandler_HIGH=int_obj->EXT_InterruptHandler_HIGH;    
                RBx4_InterruptHandler_LOW=int_obj->EXT_InterruptHandler_LOW;
            
        break;
        case INTERRUPT_EXTERNAL_RBx5 :
        
                RBx5_InterruptHandler_HIGH=int_obj->EXT_InterruptHandler_HIGH;
                RBx5_InterruptHandler_LOW=int_obj->EXT_InterruptHandler_LOW; 
        break;
        case INTERRUPT_EXTERNAL_RBx6 :

                RBx6_InterruptHandler_HIGH=int_obj->EXT_InterruptHandler_HIGH;
                RBx6_InterruptHandler_LOW=int_obj->EXT_InterruptHandler_LOW;

        break;
        case INTERRUPT_EXTERNAL_RBx7 :
            
                RBx7_InterruptHandler_HIGH=int_obj->EXT_InterruptHandler_HIGH;
                RBx7_InterruptHandler_LOW=int_obj->EXT_InterruptHandler_LOW;

        break;

        default : 
            ret=RETURN_NOT_OK;
    }
    }
    return ret;

}
#endif
#if 1
void INT0_ISR(void)
{
    if(INT0_InterruptHandler)INT0_InterruptHandler();
}
void INT1_ISR(void)
{
    if(INT1_InterruptHandler)INT1_InterruptHandler();
}
void INT2_ISR(void)
{
    if(INT2_InterruptHandler)INT2_InterruptHandler();
}
void RB4_ISR(void)
{
    if(READ_BIT(PORTB,4)&&RBx4_InterruptHandler_HIGH)
    {
        RBx4_InterruptHandler_HIGH();
    }
    else if(!(READ_BIT(PORTB,4)&&RBx4_InterruptHandler_LOW))
    {
        RBx4_InterruptHandler_LOW();
    }
       
}
void RB5_ISR(void)
{
    if(READ_BIT(PORTB,5)&&RBx5_InterruptHandler_HIGH)
    {
        RBx5_InterruptHandler_HIGH();
    }
    else if(!(READ_BIT(PORTB,5)&&RBx5_InterruptHandler_LOW))
    {
        RBx5_InterruptHandler_LOW();
    }
}
void RB6_ISR(void)
{
    if(READ_BIT(PORTB,6)&&RBx6_InterruptHandler_HIGH)
    {
        RBx6_InterruptHandler_HIGH();
    }
    else if(!(READ_BIT(PORTB,6)&&RBx6_InterruptHandler_LOW))
    {
        RBx6_InterruptHandler_LOW();
    }
}
void RB7_ISR(void)
{
    if(READ_BIT(PORTB,7)&&RBx7_InterruptHandler_HIGH)
    {
        RBx7_InterruptHandler_HIGH();
    }
    else if(!(READ_BIT(PORTB,7)&&RBx7_InterruptHandler_LOW))
    {
        RBx7_InterruptHandler_LOW();
    }
}
#endif