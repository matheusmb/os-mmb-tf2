/* 
 * File:   main.c
 * Author: Matheus
 *
 * Created on November 25, 2014, 4:00 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "terminal.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    TerminalInit();
    
    printf("Oiii");
    unsigned long int i = 0;
    while (1) {
        if(i  == 999999999) {
            printf("Working\n");
            i = 0;
        }
        
        i++;
    }

    return (EXIT_SUCCESS);
}

