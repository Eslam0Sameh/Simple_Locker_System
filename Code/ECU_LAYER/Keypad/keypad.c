#include "keypad.h"
uint8 matrix[KEYPAD_ROWS][KEYPAD_COLS]={
                                                {'7','8','9','/'},
                                                {'4','5','6','*'},
                                                {'1','2','3','-'},
                                                {'#','0','=','+'}                            
                                       };
STD_RETURN keypad_initialize(const keypad_t *ptr){
    STD_RETURN ret=RETURN_NOT_OK;
    uint8 rows_counter=0;
    uint8 cols_counter=0;
    
    if(NULL==ptr){ret=RETURN_NOT_OK;}
    else
    {
        for(rows_counter=0;rows_counter<KEYPAD_ROWS;rows_counter++)
        {
            gpio_pin_initialize(&(ptr->ROWS[rows_counter]));
        }
        for(cols_counter=0;cols_counter<KEYPAD_COLS;cols_counter++)
        {
            gpio_pin_initialize(&(ptr->ROWS[cols_counter]));
        }
        
        ret=RETURN_OK;
    }
    return ret;
}
STD_RETURN keypad_get_value(const keypad_t *ptr,uint8 *value){
    STD_RETURN ret=RETURN_NOT_OK;
    uint8 rows_counter0=0;
    uint8 rows_counter1=0;
    uint8 cols_counter=0;
    logic_t status=LOW;
    
    if(NULL==ptr){ret=RETURN_NOT_OK;}
    else
    {
        for(rows_counter0=0;rows_counter0<KEYPAD_ROWS;rows_counter0++)
        {
            __delay_ms(10);
            for(rows_counter1=0;rows_counter1<KEYPAD_ROWS;rows_counter1++)
            {
                gpio_pin_write(&(ptr->ROWS[rows_counter1]),LOW);
            }
            gpio_pin_write(&(ptr->ROWS[rows_counter0]),HIGH);
            for(cols_counter=0;cols_counter<KEYPAD_COLS;cols_counter++)
            {
                gpio_pin_read(&(ptr->COLS[cols_counter]),&status);
                if(HIGH==status)
                {
                    *value=matrix[rows_counter0][cols_counter];
                    break;
                }
                
            }
 
        }
        
        ret=RETURN_OK;
    }
    return ret;
}
