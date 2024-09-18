#include "LCD.h"
static STD_RETURN lcd_send_4bits_data_command(const lcd_4bit_t *lcd,uint8 data_command);
static STD_RETURN lcd_set_cursor_4bit(const lcd_4bit_t *lcd,uint8 row,uint8 col);
static STD_RETURN lcd_send_enable_4bit(const lcd_4bit_t *lcd);
static STD_RETURN lcd_send_8bits_data_command(const lcd_8bit_t *lcd,uint8 data_command);
static STD_RETURN lcd_set_cursor_8bit(const lcd_8bit_t *lcd,uint8 row,uint8 col);
static STD_RETURN lcd_send_enable_8bit(const lcd_8bit_t *lcd);

STD_RETURN lcd_8bit_initialize(const lcd_8bit_t *lcd){ 
    STD_RETURN ret=RETURN_NOT_OK;
    if(NULL==lcd){ret=RETURN_NOT_OK;}
    else
    {
        gpio_pin_initialize(&(lcd->En));
        gpio_pin_initialize(&(lcd->RS));
        uint8 l_counter=0;
        for(l_counter=0;l_counter<8;l_counter++)
        {
            gpio_pin_initialize(&(lcd->pins[l_counter]));
        }
        lcd_8bit_send_command(lcd,_LCD_8BIT_MODE_2_LINE);
        __delay_ms(20);
        lcd_8bit_send_command(lcd,_LCD_8BIT_MODE_2_LINE);
        __delay_ms(5);
        lcd_8bit_send_command(lcd,_LCD_8BIT_MODE_2_LINE);
        __delay_us(150);
    
        lcd_8bit_send_command(lcd,_LCD_CLEAR);
        lcd_8bit_send_command(lcd,_LCD_RETURN_HOME);
        lcd_8bit_send_command(lcd,_LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
        lcd_8bit_send_command(lcd,_LCD_ENTRY_MODE_INC_SHIFT_OFF);
        lcd_8bit_send_command(lcd,_LCD_8BIT_MODE_2_LINE);
        lcd_8bit_send_command(lcd,_LCD_DDRAM_START);
        
        ret=RETURN_OK;
    }
    return ret;
}
STD_RETURN lcd_8bit_send_command(const lcd_8bit_t *lcd,uint8 command){ 
    STD_RETURN ret=RETURN_NOT_OK;
    if(NULL==lcd){ret=RETURN_NOT_OK;}
    else
    {
        gpio_pin_write(&(lcd->RS),LOW);
        lcd_send_8bits_data_command(lcd,command);
        lcd_send_enable_8bit(lcd);

        ret=RETURN_OK;
    }
    return ret;
}
STD_RETURN lcd_8bit_send_data(const lcd_8bit_t *lcd,uint8 data){ 
    STD_RETURN ret=RETURN_NOT_OK;
    if(NULL==lcd){ret=RETURN_NOT_OK;}
    else
    {
        gpio_pin_write(&(lcd->RS),HIGH);
        lcd_send_8bits_data_command(lcd,data);
        lcd_send_enable_8bit(lcd);
        
        
        ret=RETURN_OK;
    }
    return ret;
}
STD_RETURN lcd_8bit_send_data_at_position(const lcd_8bit_t *lcd,uint8 data,
                                                uint8 row,uint8 col){ 
    STD_RETURN ret=RETURN_NOT_OK;
    if(NULL==lcd){ret=RETURN_NOT_OK;}
    else
    {
        lcd_set_cursor_8bit(lcd,row,col);
        lcd_8bit_send_data(lcd,data);
        
        ret=RETURN_OK;
    }
    return ret;
}
STD_RETURN lcd_8bit_send_string(const lcd_8bit_t *lcd,const uint8 *str){ 
    STD_RETURN ret=RETURN_NOT_OK;
    if(NULL==lcd||NULL==str){ret=RETURN_NOT_OK;}
    else
    {
        while(*str){
            lcd_8bit_send_data(lcd,*str++);
        }
        
        ret=RETURN_OK;
    }
    return ret;
}
STD_RETURN lcd_8bit_send_string_at_position(const lcd_8bit_t *lcd,const uint8 *str,
                 uint8 row,uint8 col){ 
    STD_RETURN ret=RETURN_NOT_OK;
    if(NULL==lcd||NULL==str){ret=RETURN_NOT_OK;}
    else
    {
        lcd_set_cursor_8bit(lcd,row,col);
        lcd_8bit_send_string(lcd,str);
        ret=RETURN_OK;
    }
    return ret;
}
STD_RETURN lcd_8bit_send_custom_character_at_position(const lcd_8bit_t *lcd
                ,const uint8 *arr,uint8 cgRam_position,uint8 row,uint8 col){ 
    STD_RETURN ret=RETURN_NOT_OK;
    if(NULL==lcd||NULL==arr){ret=RETURN_NOT_OK;}
    else
    {
        uint8 l_counter=0;
        lcd_8bit_send_command(lcd,_LCD_CGRAM_START+cgRam_position*8);
        for(l_counter=0;l_counter<8;l_counter++)
        {
            lcd_8bit_send_data(lcd,arr[l_counter]);
        }
        lcd_8bit_send_data_at_position(lcd,cgRam_position,row,col);
        ret=RETURN_OK;
    }
    return ret;
}
/**************************************************************/
STD_RETURN lcd_4bit_initialize(const lcd_4bit_t *lcd){ 
    STD_RETURN ret=RETURN_NOT_OK;
    if(NULL==lcd){ret=RETURN_NOT_OK;}
    else
    {
        gpio_pin_initialize(&(lcd->En));
        gpio_pin_initialize(&(lcd->RS));
        uint8 l_counter=0;
        for(l_counter=0;l_counter<4;l_counter++)
        {
            gpio_pin_initialize(&(lcd->pins[l_counter]));
        }
        lcd_4bit_send_command(lcd,_LCD_8BIT_MODE_2_LINE);
        __delay_ms(20);
        lcd_4bit_send_command(lcd,_LCD_8BIT_MODE_2_LINE);
        __delay_ms(5);
        lcd_4bit_send_command(lcd,_LCD_8BIT_MODE_2_LINE);
        __delay_us(150);
        lcd_4bit_send_command(lcd,_LCD_CLEAR);
        lcd_4bit_send_command(lcd,_LCD_RETURN_HOME);
        lcd_4bit_send_command(lcd,_LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
        lcd_4bit_send_command(lcd,_LCD_ENTRY_MODE_INC_SHIFT_OFF);
        lcd_4bit_send_command(lcd,_LCD_4BIT_MODE_2_LINE);
        lcd_4bit_send_command(lcd,_LCD_DDRAM_START);
        
        ret=RETURN_OK;
    }
    return ret;
}
STD_RETURN lcd_4bit_send_command(const lcd_4bit_t *lcd,uint8 command){ 
    STD_RETURN ret=RETURN_NOT_OK;
    if(NULL==lcd){ret=RETURN_NOT_OK;}
    else
    {
        gpio_pin_write(&(lcd->RS),LOW);
        lcd_send_4bits_data_command(lcd,command>>4);
        lcd_send_enable_4bit(lcd);
        lcd_send_4bits_data_command(lcd,command);
        lcd_send_enable_4bit(lcd);
        ret=RETURN_OK;
        __delay_ms(10);
    }
    return ret;
}
STD_RETURN lcd_4bit_send_data(const lcd_4bit_t *lcd,uint8 data){ 
    STD_RETURN ret=RETURN_NOT_OK;
    if(NULL==lcd){ret=RETURN_NOT_OK;}
    else
    {
        gpio_pin_write(&(lcd->RS),HIGH);
        lcd_send_4bits_data_command(lcd,data>>4);
        lcd_send_enable_4bit(lcd);
        lcd_send_4bits_data_command(lcd,data);
        lcd_send_enable_4bit(lcd);
        ret=RETURN_OK;
    }
    return ret;
}
STD_RETURN lcd_4bit_send_data_at_position(const lcd_4bit_t *lcd,uint8 data,
                                                uint8 row,uint8 col){ 
    STD_RETURN ret=RETURN_NOT_OK;
    if(NULL==lcd){ret=RETURN_NOT_OK;}
    else
    {
        lcd_set_cursor_4bit(lcd,row,col);
        lcd_4bit_send_data(lcd,data);
        
        ret=RETURN_OK;
    }
    return ret;
}
STD_RETURN lcd_4bit_send_string(const lcd_4bit_t *lcd,const uint8 *str){ 
    STD_RETURN ret=RETURN_NOT_OK;
    if(NULL==lcd||NULL==str){ret=RETURN_NOT_OK;}
    else
    {
        while(*str){
            lcd_4bit_send_data(lcd,*str++);
        }
        ret=RETURN_OK;
    }
    return ret;
}
STD_RETURN lcd_4bit_send_string_at_position(const lcd_4bit_t *lcd,const uint8 *str,
                 uint8 row,uint8 col){ 
    STD_RETURN ret=RETURN_NOT_OK;
    if(NULL==lcd||NULL==str){ret=RETURN_NOT_OK;}
    else
    {
        lcd_set_cursor_4bit(lcd,row,col);
        lcd_4bit_send_string(lcd,str);
        ret=RETURN_OK;
    }
    return ret;
}
STD_RETURN lcd_4bit_send_custom_character_at_position(const lcd_4bit_t *lcd
                ,const uint8 *arr,uint8 cgRam_position,uint8 row,uint8 col){ 
    STD_RETURN ret=RETURN_NOT_OK;
    if(NULL==lcd||NULL==arr){ret=RETURN_NOT_OK;}
    else
    {
        uint8 l_counter=0;
        lcd_4bit_send_command(lcd,_LCD_CGRAM_START+cgRam_position*8);
        for(l_counter=0;l_counter<8;l_counter++)
        {
            lcd_4bit_send_data(lcd,arr[l_counter]);
        }
        lcd_4bit_send_data_at_position(lcd,cgRam_position,row,col);
        ret=RETURN_OK;
    }
    return ret;
}
static STD_RETURN lcd_send_4bits_data_command(const lcd_4bit_t *lcd,uint8 data_command){ 
    STD_RETURN ret=RETURN_NOT_OK;
    if(NULL==lcd){ret=RETURN_NOT_OK;}
    else
    {
        uint8 l_counter=0;
        for(l_counter=0;l_counter<4;++l_counter)
        {
            gpio_pin_write(&(lcd->pins[l_counter]),READ_BIT(data_command,l_counter));
        }
        ret=RETURN_OK;
    }
    return ret;
}
static STD_RETURN lcd_set_cursor_4bit(const lcd_4bit_t *lcd,uint8 row,uint8 col){ 
    STD_RETURN ret=RETURN_NOT_OK;
    if(NULL==lcd){ret=RETURN_NOT_OK;}
    else
    {
        
        col--;
        switch(row){
                case 1 :lcd_4bit_send_command(lcd,0x80+col);break;
                case 2 :lcd_4bit_send_command(lcd,0xc0+col);break;
                case 3 :lcd_4bit_send_command(lcd,0x94+col);break;
                case 4 :lcd_4bit_send_command(lcd,0xd4+col);break;
                default: ;
        }        
        ret=RETURN_OK;
    }
    return ret;
}
static STD_RETURN lcd_send_enable_4bit(const lcd_4bit_t *lcd){ 
    STD_RETURN ret=RETURN_NOT_OK;
    if(NULL==lcd){ret=RETURN_NOT_OK;}
    else
    {
         gpio_pin_write(&(lcd->En),HIGH);
        __delay_us(5);
        gpio_pin_write(&(lcd->En),LOW);
        
        ret=RETURN_OK;
    }
    return ret;
}
static STD_RETURN lcd_send_8bits_data_command(const lcd_8bit_t *lcd,uint8 data_command){ 
    STD_RETURN ret=RETURN_NOT_OK;
    if(NULL==lcd){ret=RETURN_NOT_OK;}
    else
    {
        uint8 l_counter=0;
        for(l_counter=0;l_counter<8;++l_counter)
        {
            gpio_pin_write(&(lcd->pins[l_counter]),READ_BIT(data_command,l_counter));
        }
        ret=RETURN_OK;
    }
    return ret;
}
static STD_RETURN lcd_set_cursor_8bit(const lcd_8bit_t *lcd,uint8 row,uint8 col){ 
    STD_RETURN ret=RETURN_NOT_OK;
    if(NULL==lcd){ret=RETURN_NOT_OK;}
    else
    {
        col--;
        switch(row){
                case 1 :lcd_8bit_send_command(lcd,0x80+col);break;
                case 2 :lcd_8bit_send_command(lcd,0xc0+col);break;
                case 3 :lcd_8bit_send_command(lcd,0x94+col);break;
                case 4 :lcd_8bit_send_command(lcd,0xd4+col);break;
                default: ;
        }   
        
        ret=RETURN_OK;
    }
    return ret;
}
static STD_RETURN lcd_send_enable_8bit(const lcd_8bit_t *lcd){ 
    STD_RETURN ret=RETURN_NOT_OK;
    if(NULL==lcd){ret=RETURN_NOT_OK;}
    else
    {
        gpio_pin_write(&(lcd->En),HIGH);
        __delay_us(5);
        gpio_pin_write(&(lcd->En),LOW);
        
        ret=RETURN_OK;
    }
    return ret;
}
STD_RETURN  convert_8_bit_to_string (uint8 number,uint8 *str){ 
    STD_RETURN ret=RETURN_NOT_OK;
    if(NULL==str){ret=RETURN_NOT_OK;}
    else
    {
        /* you should take a look at      convert_16_bit_to_string
         * documentation below */
        uint8 Temp_String[4] = {0};
        uint8 DataCounter = 0;
 
        memset((char *)str, ' ', 4);
        str[4]='\0';
        sprintf((char *)Temp_String, "%i", number); 
        
        while(Temp_String[DataCounter] != '\0'){
            str[DataCounter] = Temp_String[DataCounter]; 
            DataCounter++;
        }
    }
    return ret;
}
STD_RETURN convert_16_bit_to_string(uint16 number,uint8 *str){ 
    STD_RETURN ret=RETURN_NOT_OK;
    if(NULL==str){ret=RETURN_NOT_OK;}
    else
    {
        uint8 Temp_String[6] = {0};
        uint8 DataCounter = 0;
        /*memset((char *)str, '\0', 6);
        sprintf(str, "%i", number);
        ret=RETURN_OK; "this previous code is run properly but 
         in displaying the data for example 1023 and then display the data  
         200 the 3 at the end of 1023 will appear 2003 the solution is inserting 
         * spaces not null space to the rest of the array and of course last element
         * should be null to terminate the sentence , in other words we will
         * make the string  nearly have some spaces in last of sentence to overcome
         *  this problem such every time it displaying the data will cover 
         * the 6 characters neglecting the last sentence such if 1023 then 200
         * it will display firstly "1023  " and secondly "200   "   "*/
        memset((char *)str, ' ', 6);
        str[6]='\0';
        sprintf((char *)Temp_String, "%i", number); 
        
        while(Temp_String[DataCounter] != '\0'){
            str[DataCounter] = Temp_String[DataCounter]; 
            DataCounter++;
        }
        /*suppose the number is equal to 1234
         * in this code we create temp_string={000000} and then 
         * we create str={     \0}"5spaces and null at the end" and changing the value
         * temp_string (in function sprintf) to {123\0  } and get into 
         * while loop that terminated when temp_string[DataCounter]
         * equal to null ,in other words it copy the actual value (1234)
         * to str array and the rest of the str array is what we initialize
         * before so str at the end is equal to {1234 /0} "4 numbers and 1 space
         * and null space at the end"
         * 
         
         */
    }
    return ret;
}
STD_RETURN convert_32_bit_to_string(uint32 number,uint8 *str){ 
    STD_RETURN ret=RETURN_NOT_OK;
    if(NULL==str){ret=RETURN_NOT_OK;}
    else
    {
        /* you should take a look at      convert_16_bit_to_string
         * documentation below */
        uint8 Temp_String[11] = {0};
        uint8 DataCounter = 0;
 
        memset((char *)str, ' ', 11);
        str[11]='\0';
        sprintf((char *)Temp_String, "%i", number); 
        
        while(Temp_String[DataCounter] != '\0'){
            str[DataCounter] = Temp_String[DataCounter]; 
            DataCounter++;
        }
        
    }
    return ret;
}
