/* 
 * File:   keypad.h
 * Author: es-IslamSameh2025
 *
 * Created on November 4, 2023, 1:08 AM
 */

#ifndef KEYPAD_H
#define	KEYPAD_H

#include "keypad_config.h"
#include "../../MCAL_LAYER/GPIO/gpio.h"
#define     KEYPAD_ROWS      4
#define     KEYPAD_COLS      4
typedef struct {
pin_config ROWS[KEYPAD_ROWS];
pin_config COLS[KEYPAD_COLS];
}keypad_t;
/*                  keypad_interfaces                                */
STD_RETURN keypad_initialize(const keypad_t *ptr);
STD_RETURN keypad_get_value(const keypad_t *ptr,uint8 *value);
#endif	/* KEYPAD_H */

