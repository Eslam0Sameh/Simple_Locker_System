/* 
 * File:   Interrupt_ISR.h
 * Author: es-IslamSameh2025
 *
 * Created on February 18, 2024, 9:30 PM
 */

#ifndef INTERRUPT_ISR_H
#define	INTERRUPT_ISR_H
#include "Interrupt_external.h"
#include "Interrupt_internal.h"
#include "../ADC/ADC.h"
/* ----------------- Software Interfaces Declarations -----------------*/
void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);
void RB4_ISR(void);
void RB5_ISR(void);
void RB6_ISR(void);
void RB7_ISR(void);
#endif	/* INTERRUPT_ISR_H */

