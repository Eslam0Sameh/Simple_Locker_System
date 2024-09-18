/* 
 * File:   LCD.h
 * Author: IslamSameh2025
 *
 * Created on December 1, 2023, 3:40 PM
 */

#ifndef LCD_H
#define	LCD_H

/*includes*/
#include "LCD_conf.h"
#include "../../MCAL_LAYER/GPIO/gpio.h"
/*data initialization*/
typedef struct {
pin_config RS;
pin_config En;
pin_config pins[4];
}lcd_4bit_t;
typedef struct {
pin_config RS;
pin_config En;
pin_config pins[8];
}lcd_8bit_t;
/*macro declaration*/
#define _LCD_CLEAR                      0X01
#define _LCD_RETURN_HOME                0x02
#define _LCD_ENTRY_MODE_DEC_SHIFT_OFF   0x04
#define _LCD_ENTRY_MODE_DEC_SHIFT_ON    0x05
#define _LCD_ENTRY_MODE_INC_SHIFT_OFF   0x06
#define _LCD_ENTRY_MODE_INC_SHIFT_ON    0x07
#define _LCD_CURSOR_MOVE_SHIFT_LEFT     0x10
#define _LCD_CURSOR_MOVE_SHIFT_RIGHT    0x14
#define _LCD_DISPLAY_SHIFT_LEFT         0x18
#define _LCD_DISPLAY_SHIFT_RIGHT        0x1C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF 0x0C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON  0x0D
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF  0x0E
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON   0x0F
#define _LCD_DISPLAY_OFF_CURSOR_OFF              0x08
#define _LCD_8BIT_MODE_2_LINE           0x38
#define _LCD_4BIT_MODE_2_LINE           0x28

#define _LCD_CGRAM_START                0x40
#define _LCD_DDRAM_START                0x80

#define ROW1 1
#define ROW2 2
#define ROW3 3
#define ROW4 4


/*software interfaces*/
/*8_bit_lcd*/
STD_RETURN lcd_8bit_initialize(const lcd_8bit_t *lcd);
STD_RETURN lcd_8bit_send_command(const lcd_8bit_t *lcd,uint8 command);
STD_RETURN lcd_8bit_send_data(const lcd_8bit_t *lcd,uint8 data);
STD_RETURN lcd_8bit_send_data_at_position(const lcd_8bit_t *lcd,uint8 data,
                                                uint8 row,uint8 col);
STD_RETURN lcd_8bit_send_string(const lcd_8bit_t *lcd,const uint8 *str);
STD_RETURN lcd_8bit_send_string_at_position(const lcd_8bit_t *lcd,const uint8 *str,
                 uint8 row,uint8 col);
STD_RETURN lcd_8bit_send_custom_character_at_position(const lcd_8bit_t *lcd
                ,const uint8 *arr,uint8 cgRam_position,uint8 row,uint8 col);

/*4_bit_lcd*/
STD_RETURN lcd_4bit_initialize(const lcd_4bit_t *lcd);
STD_RETURN lcd_4bit_send_command(const lcd_4bit_t *lcd,uint8 command);
STD_RETURN lcd_4bit_send_data(const lcd_4bit_t *lcd,uint8 data);
STD_RETURN lcd_4bit_send_data_at_position(const lcd_4bit_t *lcd,uint8 data,
                                                uint8 row,uint8 col);
STD_RETURN lcd_4bit_send_string(const lcd_4bit_t *lcd,const uint8 *str);
STD_RETURN lcd_4bit_send_string_at_position(const lcd_4bit_t *lcd,const uint8 *str,
                 uint8 row,uint8 col);
STD_RETURN lcd_4bit_send_custom_character_at_position(const lcd_4bit_t *lcd
                ,const uint8 *arr,uint8 cgRam_position,uint8 row,uint8 col);
/*helper functions*/
STD_RETURN  convert_8_bit_to_string (uint8 number,uint8 *str);
STD_RETURN convert_16_bit_to_string(uint16 number,uint8 *str);
STD_RETURN convert_32_bit_to_string(uint32 number,uint8 *str);
#endif	/* LCD_H */

