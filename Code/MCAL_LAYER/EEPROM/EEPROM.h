/* 
 * File:   EEPROM.h
 * Author: IslamSameh2025
 *
 * Created on July 2, 2024, 7:14 PM
 */

#ifndef EEPROM_H
#define	EEPROM_H
/*                    INCLUDES                               */
#include "../GPIO/gpio.h"
#include "../Interrupt/Interrupt_external.h"
/*               Software INterfaces                        */
STD_RETURN EEPROM_MEMORY_WRITE(uint16 address,uint8 data);
STD_RETURN EEPROM_MEMORY_READ(uint16 address,uint8 *data);
#endif	/* EEPROM_H */

