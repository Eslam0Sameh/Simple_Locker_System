/* 
 * File:   gpio.h
 * Author: IslamSameh
 *
 * Created on October 21, 2023, 11:48 PM
 */

#ifndef GPIO_H
#define	GPIO_H
/*       HEADER_FILES_INCLUDED         */
#include "gpio_config.h"
#include "../proc/pic18f4620.h"
#include "../std_types.h"
#include "../../MCAL_LAYER/std_libs.h"
#include "../compiler.h"
#include "../../MCAL_LAYER/configuration.h"
/*           MACRO_FUNCTIONS           */
#define MAX_PORTS  5
#define MAX_PINS   8
#define BIT_MASK  0X01
#define PORT_MASK 0XFF
#define SET_BIT(REG,POSITION)          (REG|=(BIT_MASK<<POSITION))
#define TOGGLE_BIT(REG,POSITION)       (REG^=(BIT_MASK<<POSITION))
#define CLEAR_BIT(REG,POSITION)       (REG&=~(BIT_MASK<<POSITION))
#define READ_BIT(REG, POSITION)     ((REG >> POSITION) & BIT_MASK)
#define _XTAL_FREQ 8000000

/*                  VARIABLES PROTOTYPE                  */


typedef enum{
    LOW=0,
    HIGH
}logic_t;
typedef enum{
    OUTPUT=0,
    INPUT
}direction_t;
typedef enum{
    PIN0=0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
}pin_index_t;

typedef enum{
    PORT_A=0,
    PORT_B,
    PORT_C,
    PORT_D,
    PORT_E
}port_index_t;



typedef struct {
   uint8                 logic:1;
   uint8             direction:1;
   uint8             pin_index:3;
   uint8            port_index:3;
}pin_config;

#endif	/* GPIO_H */
/*             PORT_INTERFACES              */
STD_RETURN gpio_port_direction_initialize(port_index_t port,uint8 direction);
STD_RETURN gpio_port_write(port_index_t port,uint8 logic);
STD_RETURN gpio_port_read(port_index_t port,uint8 *ptr);
STD_RETURN gpio_port_direction_read(port_index_t port,uint8 *ptr);
STD_RETURN gpio_port_toggle(port_index_t port);
/*             PIN_INTERFACES              */
STD_RETURN gpio_pin_direction_initialize(const pin_config * ptr);
STD_RETURN gpio_pin_direction_read(const pin_config * ptr,direction_t * ptr1);
STD_RETURN gpio_pin_write(const pin_config * ptr,logic_t logic);
STD_RETURN gpio_pin_toggle(const pin_config * ptr);
STD_RETURN gpio_pin_read(const pin_config * ptr,logic_t * ptr1);
STD_RETURN gpio_pin_initialize(const pin_config * ptr);
