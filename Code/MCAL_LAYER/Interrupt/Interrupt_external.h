/* 
 * File:   Interrupt_external.h
 * Author: IslamSameh2025
 *
 * Created on February 18, 2024, 9:30 PM
 */

#ifndef INTERRUPT_EXTERNAL_H
#define	INTERRUPT_EXTERNAL_H
#include "Interrupt_declaration.h"
/*Macro Function Declarations */
#if EXTERNAL_INTERRUPT_INTx_FEATURE_ENABLE  ==    ACTIVATED
/*INT0 CONFIGURE*/
#define INT0_ENABLE()                     (INTCONbits.INT0IE=1)
#define INT0_DISABLE()                    (INTCONbits.INT0IE=0)
#define INT0_FLAG_CLEAR()                 (INTCONbits.INT0IF=0)
#define INT0_RISING_EDGE_SET()            (INTCON2bits.INTEDG0=1)  
#define INT0_FALLING_EDGE_SET()           (INTCON2bits.INTEDG0=0) 

volatile uint8 portb_prev;

/*INT1 CONFIGURE*/
#define INT1_ENABLE()                    (INTCON3bits.INT1IE=1)
#define INT1_DISABLE()                   (INTCON3bits.INT1IE=0)
#define INT1_FLAG_CLEAR()                (INTCON3bits.INT1IF=0)
#define INT1_RISING_EDGE_SET()           (INTCON2bits.INTEDG1=1)  
#define INT1_FALLING_EDGE_SET()          (INTCON2bits.INTEDG1=0) 


/*INT2 CONFIGURE*/
#define INT2_ENABLE()                   (INTCON3bits.INT2IE=1)
#define INT2_DISABLE()                  (INTCON3bits.INT2IE=0)
#define INT2_FLAG_CLEAR()               (INTCON3bits.INT2IF=0)
#define INT2_RISING_EDGE_SET()          (INTCON2bits.INTEDG2=1)  
#define INT2_FALLING_EDGE_SET()         (INTCON2bits.INTEDG2=0)


#if INTERRUPT_PRIORITY_ACTIVATION   ==   ACTIVATED

/*No need to configure priority
  to INT0 such INT0 
  is high priority and 
  CANNOT change*/

#define INT1_HIGH_PRIORITY_SET()          (INTCON3bits.INT1IP=1)
#define INT1_LOW_PRIORITY_SET()           (INTCON3bits.INT1IP=0)
#define INT2_HIGH_PRIORITY_SET()          (INTCON3bits.INT2IP=1)
#define INT2_LOW_PRIORITY_SET()           (INTCON3bits.INT2IP=0)
#endif
#endif
#if EXTERNAL_INTERRUPT_OnChange_FEATURE_ENABLE  ==  ACTIVATED
#define RBX_INTERRUPT_ENABLE()          (INTCONbits.RBIE=1)
#define RBX_INTERRUPT_DISABLE()         (INTCONbits.RBIE=0)
#define RBX_INTERRUPT_CLEAR_FLAG()      (INTCONbits.RBIF=0)

#if INTERRUPT_PRIORITY_ACTIVATION   ==   ACTIVATED


#define RBX_INTERRUPT_HIGH_PRIORITY_SET()        (INTCON2bits.RBIP=1)
#define RBX_INTERRUPT_LOW_PRIORITY_SET()         (INTCON2bits.RBIP=0)

#endif
#endif

/* ----------------- Data Type Declarations -----------------*/
typedef void (*InterruptHandler)(void);

typedef enum{
    INTERRUPT_FALLING_EDGE = 0,
    INTERRUPT_RISING_EDGE
}interrupt_INTx_edge;

typedef enum{
    INTERRUPT_EXTERNAL_INT0 =  0,
    INTERRUPT_EXTERNAL_INT1,
    INTERRUPT_EXTERNAL_INT2        
}interrupt_INTx_src;

typedef enum{
    INTERRUPT_EXTERNAL_RBx4 =  0,
    INTERRUPT_EXTERNAL_RBx5,
    INTERRUPT_EXTERNAL_RBx6,       
    INTERRUPT_EXTERNAL_RBx7       
}interrupt_RBx_src;

typedef enum{
    INTERRUPT_LOW_PRIORITY = 0,
    INTERRUPT_HIGH_PRIORITY        
}interrupt_priority_cfg;

typedef struct{
    InterruptHandler EXT_InterruptHandler;
    interrupt_INTx_edge edge;
    interrupt_INTx_src source;
    interrupt_priority_cfg priority;
}interrupt_INTx_t;

typedef struct{
    void (* EXT_InterruptHandler_HIGH)(void);
    void (* EXT_InterruptHandler_LOW)(void);
    interrupt_RBx_src source;
    interrupt_priority_cfg priority;
}interrupt_RBx_t;

/* ----------------- Software Interfaces Declarations -----------------*/

STD_RETURN Interrupt_INTx_Init(const interrupt_INTx_t *int_obj);


STD_RETURN Interrupt_INTx_DeInit(const interrupt_INTx_t *int_obj);


STD_RETURN Interrupt_RBx_Init(const interrupt_RBx_t *int_obj);


STD_RETURN Interrupt_RBx_DeInit(const interrupt_RBx_t *int_obj);

#endif	/* INTERRUPT_EXTERNAL_H */

