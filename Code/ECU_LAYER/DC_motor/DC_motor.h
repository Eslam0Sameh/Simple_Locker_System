/* 
 * File:   DC_motor.h
 * Author: IslamSameh2025
 *
 * Created on October 30, 2023, 11:14 AM
 */

#ifndef DC_MOTOR_H
#define	DC_MOTOR_H
#include "../../MCAL_LAYER/GPIO/gpio.h"
#include "DC_motor_config.h"
/*        data prototype        */
typedef enum {
    motor_off =LOW,
    motor_on  =HIGH
}motor_status;
typedef struct {
    uint8             port_index:4;
    uint8              pin_index:4;
}motor_structt;
typedef struct {
    motor_structt dcMotor[2];
    uint8            status ;
}motor_t;
/*           functions prototype                 */
STD_RETURN motor_initialize(const motor_t *ptr);
STD_RETURN motor_rotate_right(const motor_t *ptr);
STD_RETURN motor_rotate_left(const motor_t *ptr);
STD_RETURN motor_stop(const motor_t *ptr);





#endif	/* DC_MOTOR_H */

