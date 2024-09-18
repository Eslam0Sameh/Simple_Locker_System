/* 
 * File:   push_button.h
 * Author: es-IslamSameh2025
 *
 * Created on October 21, 2023, 11:50 PM
 */

#ifndef PUSH_BUTTON_H
#define	PUSH_BUTTON_H
#include "push_button_config.h"
#include "../../MCAL_LAYER/GPIO/gpio.h"
/*            data type declaration                     */
typedef enum{
    PULL_DOWN=0,
    PULL_UP
}connection_t;
typedef enum{
    released=0,
    pressed
}button_status_t;
typedef struct {
    uint8                port_index:4;
    uint8                 pin_index:3;
    uint8                connection:1;
}button_t;

/*            PUSH_BUTTON_INTERFACES                    */
STD_RETURN button_initialize(const button_t * ptr);
STD_RETURN button_read (const button_t * ptr,button_status_t *ptr1);
#endif	/* PUSH_BUTTON_H */

