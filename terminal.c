#include "definitions.h"
#include "terminal.h"

#include "string.h"

#include <pthread.h>

pthread_t threadTerminal;

void ProcessInput(const char * cmd) {
    

     
    if( strcmpi(cmd, TOKEN_EXIT) == 0) {
        printf("Exiting.. \n");
        exit(EXIT_SUCCESS);
    } else {
        LogError("Unknown Command");
    }
    
    
}

void LogError(const char * msg) {
    char log[DEFAULT_STR_SIZE] = "\n[ERROR] ";
    
    strcat(log, msg);
    
    printf(log);
}

void * TerminalWorker() {
    char input[MAX_TERMINAL_INPUT];
    
    while(1) {
        printf("\n>> ");
        fflush(stdin); gets(input);
        
        ProcessInput(input);
    }
}

void TerminalInit() {
    pthread_attr_t attr;
    
    //pthread_attr_init(&attr);
    
    pthread_create(&threadTerminal, NULL, TerminalWorker, NULL );
   
    

}
