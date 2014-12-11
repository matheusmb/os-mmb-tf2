#include "definitions.h"
#include "kernel.h"
#include "terminal.h"
#include <sys/types.h>
#include <sys/stat.h>


int chDM, chMM, chPM, chKer;

typedef struct s_message {
    int FROM;
    int TO;
    char msg[200];
} Message;

void KernelInit() {
    CreateChannels();
}

void CreateChannels() {
    CreateChannel(COM_CH_DM, &chDM, O_WRONLY);
    CreateChannel(COM_CH_MM, &chMM, O_WRONLY);
    CreateChannel(COM_CH_PM, &chPM, O_WRONLY);
    CreateChannel(COM_CH_KER, &chKer, O_RDONLY);
}

void CreateChannel(const char * cName, const int * dstCh, const int mode) {
    char msg[200];
    
    unlink(cName);
    
    if(mkfifo(cName, 0777) < 0) {
        sprintf(msg, "Failed creating channel %s", cName);
        LogError(msg);
    }
    
    *dstCh = open(cName, mode);
}

int GetChanByModule(const Module mod) {
    switch(mod) {
        case KER:
            return chKer;
        case MM:
            return chMM;
        case PM:
            return chPM;
        case DM:
            return chDM;
    }
}

void Send(const Module to, Message * m) {
    int chan = GetChanByModule(to);
    
    write(chan, m);
}


void Receive() {
    Message msg;
    
    read(chKer, &msg, sizeof(Message));
    
    ProcessMessage(&msg);
}


void ProcessMessage(const Message * msg) {
    
}