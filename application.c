/* 
 * File:   application.c
 * Author: Rahim Mohamed Ali
 *
 * Created on January 31, 2024, 6:23 PM
 */

#include "application.h"


int main() {
    
    intialization();
    welcome_message();
   
    
    while(1){
        
        git_write_numbers(&keypad,&lcd);
       
    }

    return (EXIT_SUCCESS);
}




















