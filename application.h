/* 
 * File:   application.h
 * Author: Rahim Mohamed Ali
 *
 * Created on January 31, 2024, 7:57 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

/*section : Includes  */

#include "ECU_LAYER/KEYPAD/ecu_keypad.h"
#include "ECU_LAYER/LCD/ecu_lcd.h"

/*section : Macro Declaration  */


/*section : Macro Functions Declaration  */


/*section : Data Type Declaration  */



keypad_t keypad ={
    .rows_pins[0].direction=GPIO_OUTPUT,
    .rows_pins[0].logic=LOW,
    .rows_pins[0].port=PORTC_INDEX,
    .rows_pins[0].pin=GPIO_PIN0,
    .rows_pins[1].direction=GPIO_OUTPUT,
    .rows_pins[1].logic=LOW,
    .rows_pins[1].port=PORTC_INDEX,
    .rows_pins[1].pin=GPIO_PIN1,
    .rows_pins[2].direction=GPIO_OUTPUT,
    .rows_pins[2].logic=LOW,
    .rows_pins[2].port=PORTC_INDEX,
    .rows_pins[2].pin=GPIO_PIN2,
    .rows_pins[3].direction=GPIO_OUTPUT,
    .rows_pins[3].logic=LOW,
    .rows_pins[3].port=PORTC_INDEX,
    .rows_pins[3].pin=GPIO_PIN3,
    .columns_pins[0].direction=GPIO_INPUT,
    .columns_pins[0].logic=LOW,
    .columns_pins[0].port=PORTC_INDEX,
    .columns_pins[0].pin=GPIO_PIN4,
    .columns_pins[1].direction=GPIO_INPUT,
    .columns_pins[1].logic=LOW,
    .columns_pins[1].port=PORTC_INDEX,
    .columns_pins[1].pin=GPIO_PIN5,
    .columns_pins[2].direction=GPIO_INPUT,
    .columns_pins[2].logic=LOW,
    .columns_pins[2].port=PORTC_INDEX,
    .columns_pins[2].pin=GPIO_PIN6,
    .columns_pins[3].direction=GPIO_INPUT,
    .columns_pins[3].logic=LOW,
    .columns_pins[3].port=PORTC_INDEX,
    .columns_pins[3].pin=GPIO_PIN7,    
};

lcd_4bit_t lcd={
.lcd_rs.direction=GPIO_OUTPUT,
.lcd_rs.logic=LOW,
.lcd_rs.port=PORTD_INDEX,
.lcd_rs.pin=GPIO_PIN0,
.lcd_en.direction=GPIO_OUTPUT,
.lcd_en.logic=LOW,
.lcd_en.port=PORTD_INDEX,
.lcd_en.pin=GPIO_PIN1,
.lcd_data[0].direction=GPIO_OUTPUT,
.lcd_data[0].logic=LOW,
.lcd_data[0].port=PORTD_INDEX,
.lcd_data[0].pin=GPIO_PIN2,
.lcd_data[1].direction=GPIO_OUTPUT,
.lcd_data[1].logic=LOW,
.lcd_data[1].port=PORTD_INDEX,
.lcd_data[1].pin=GPIO_PIN3,
.lcd_data[2].direction=GPIO_OUTPUT,
.lcd_data[2].logic=LOW,
.lcd_data[2].port=PORTD_INDEX,
.lcd_data[2].pin=GPIO_PIN4,
.lcd_data[3].direction=GPIO_OUTPUT,
.lcd_data[3].logic=LOW,
.lcd_data[3].port=PORTD_INDEX,
.lcd_data[3].pin=GPIO_PIN5,

};
/*section : Macro Declaration  */


/*section :  Functions Declaration  */


void intialization( void);
void welcome_message(void);
uint_8 git_write_numbers(const keypad_t*keypad,const lcd_4bit_t *lcd);
void calc (uint_32 operation,uint_32  array_process[]);
#endif	/* APPLICATION_H */

