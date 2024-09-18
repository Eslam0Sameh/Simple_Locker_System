/* 
 * File:   Interrupt_internal.h
 * Author: es-IslamSameh2025
 *
 * Created on February 18, 2024, 9:31 PM
 */

#ifndef INTERRUPT_INTERNAL_H
#define	INTERRUPT_INTERNAL_H
#include "Interrupt_declaration.h"
#if ADC_INTERRUPT_FEATURE_ENABLE==ACTIVATED
#define ADC_INTERRUPT_ENABLE()             (PIE1bits.ADIE=1)
#define ADC_INTERRUPT_DISABLE()            (PIE1bits.ADIE=0)
#define ADC_INTERRUPT_FLAG_CLEAR()         (PIR1bits.ADIF=0)
#if INTERRUPT_PRIORITY_ACTIVATION==ACTIVATED
#define ADC_INTERRUPT_HIGH_PRIORITY()      (IPR1bits.ADIP=1)
#define ADC_INTERRUPT_LOW_PRIORITY()       (IPR1bits.ADIP=0)
#endif
#endif
#endif	/* INTERRUPT_INTERNAL_H */

