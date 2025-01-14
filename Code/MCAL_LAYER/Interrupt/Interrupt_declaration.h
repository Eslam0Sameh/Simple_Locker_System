/* 
 * File:   Interrupt_declaration.h
 * Author: IslamSameh2025
 *
 * Created on February 18, 2024, 9:29 PM
 */

#ifndef INTERRUPT_DECLARATION_H
#define	INTERRUPT_DECLARATION_H
#include "Interrupt_conf.h"
/* ----------------- Macro Declarations -----------------*/
#define INTERRUPT_ENABLE    1
#define INTERRUPT_DISABLE   0
#define INTERRUPT_OCCUR     1
#define INTERRUPT_NOT_OCCUR 0
#define INTERRUPT_PRIORITY_ENABLE    1
#define INTERRUPT_PRIORITY_DISABLE   0
/*              Macro Functions Declarations                 */
#if INTERRUPT_PRIORITY_ACTIVATION==ACTIVATED
#define INTERRUPT_PRIORITY_FEATURE_ACTIVATE()   (RCONbits.IPEN=1)
#define INTERRUPT_PRIORITY_FEATURE_DEACTIVATE() (RCONbits.IPEN=0)
#define INTERRUPT_HIGH_PRIORITY_ACTIVATE()      (INTCONbits.GIEH=1)
#define INTERRUPT_HIGH_PRIORITY_DEACTIVATE()    (INTCONbits.GIEH=0)
#define INTERRUPT_LOW_PRIORITY_ACTIVATE()       (INTCONbits.GIEL=1)
#define INTERRUPT_LOW_PRIORITY_DEACTIVATE()     (INTCONbits.GIEL=0)
#else
/*SAME BITS BUT NOT SAME FUNCTIONS THAT PERFORMED ,ITS FUNCTIONALITY CHANGES 
 Such INTERRUPT FEAUTURE ACTIVATED OR NOT*/
#define INTERRUPT_GLOBAL_ACTIVATE() (INTCONbits.GIEH=1)
#define INTERRUPT_GLOBAL_DEACTIVATE() (INTCONbits.GIEH=0)
#define INTERRUPT_PERIPHERAL_ACTIVATE() (INTCONbits.GIEL=1)
#define INTERRUPT_PERIPHERAL_DEACTIVATE() (INTCONbits.GIEL=0)
#endif
#endif	/* INTERRUPT_DECLARATION_H */

