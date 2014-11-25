/* 
 * File:   terminal.h
 * Author: Matheus
 *
 * Created on November 25, 2014, 4:31 PM
 */

#ifndef TERMINAL_H
#define	TERMINAL_H


#define TOKEN_EXIT "exit"

void TerminalInit();
void LogError(const char * msg);
void * TerminalWorker();


#endif	/* TERMINAL_H */

