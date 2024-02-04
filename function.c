/* 
 * File:   application.c
 * Author: Rahim Mohamed Ali
 *
 * Created on January 31, 2024, 6:23 PM
 */

#include "application.h"


uint_8 process_array_counter=0,display_counter=1,dig=0,calc_counter=0;
uint_32 keypad_value=0xff,display_value[4],num=0,operation[]={0,0,0,0},res=0;
uint_32  process_array[4];
/******************************************************************************************/
static  uint_8 num_digits ( uint_32 number);
/******************************************************************************************/

void intialization( void){
    
     lcd_4bit_intialize(&lcd);
     keypad_intialize(&keypad);
    
    
}

/*******************************************************************************************/


void welcome_message(void){
    
    
    lcd_4bit_send_string_pos(&lcd,2,7,"Welcome");
    __delay_ms(1000);
    lcd_4bit_send_command(&lcd,_LCD_CLEAR);
    
    
}


/************************************************************************************************/

uint_8 git_write_numbers(const keypad_t*keypad,const lcd_4bit_t *lcd){
        
        keypad_get_value(keypad,&keypad_value);
      
        if(keypad_value != (0xff)){
           
      if((keypad_value != '*')&&(keypad_value != '+')&&(keypad_value != '-')&&(keypad_value != '/')&&(keypad_value != '#')&&(keypad_value != '=')){
     
          num=(num*10)+keypad_value;
          convert_int_to_string(num,display_value);
          lcd_4bit_send_string_pos(lcd,1,display_counter,display_value);
      }
   
     
       else if (keypad_value == '#'){
           lcd_4bit_send_command(lcd,_LCD_CLEAR);
           display_counter=1,num=0,process_array_counter=0;
           lcd_4bit_send_data_pos(lcd,1,1,' ');
      }
       else{
           process_array[process_array_counter]=num;
           dig=num_digits(num);
           operation[process_array_counter]=keypad_value;
           process_array_counter++,num=0;
           display_counter+=dig;
           lcd_4bit_send_data_pos(lcd,1,display_counter,keypad_value);
           display_counter++;
          
       }
         __delay_ms(200); 
        if(operation[process_array_counter-1]== '='){
             calc(operation[0],process_array);
           }
      }
}
/************************************************************************************************/
void calc (uint_32 operation,uint_32 array_process[]){
    uint_32  num=array_process[0];             
    switch (operation){
    
        case '+': 
                     while(calc_counter<process_array_counter){
                       res+=process_array[calc_counter];
                       calc_counter++;
                          }
                  break;
        
       
      
        case '-':      res=num,calc_counter=1; 
                       while(calc_counter<process_array_counter){
                            res-=process_array[calc_counter];
                            calc_counter++;
                            }
                  break;
        
        
        
        case '*': res=1;
                       while(calc_counter<process_array_counter){
                        res*=process_array[calc_counter];
                          calc_counter++;
                          }
                  break;
                  
                  
        
       
        case '/':       
                         res=num,calc_counter=1; 
                        while(calc_counter<process_array_counter){
                         res/=process_array[calc_counter];
                         calc_counter++;
        
         }
                   break;
    }
    
     convert_int_to_string(res,display_value);
     dig=num_digits(res);
     switch(dig){
         case 1 :  lcd_4bit_send_string_pos(&lcd,4,20,display_value);break;
         case 2 :  lcd_4bit_send_string_pos(&lcd,4,19,display_value);break;
         case 3 :  lcd_4bit_send_string_pos(&lcd,4,18,display_value);break;
         case 4 :  lcd_4bit_send_string_pos(&lcd,4,17,display_value);break;
     }
    
     calc_counter=0,res=0;
}
/************************************************************************************************/
/************************************************************************************************/
/************************************************************************************************/
static  uint_8 num_digits ( uint_32 number){
    uint_8 l_digit=0;
    while (number != 0 ){
        number/=10;
        l_digit++;
    }
    return l_digit;
}


