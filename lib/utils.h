#ifndef UTILS_H
#define UTILS_H

#include "types.h"
#include "input.h"
#include "memlib.h"

extern uint32 strlen(const char*);
extern uint32 digit_count(int);
extern void itoa(int, char *);
extern int in(char* what, char* where[], int size);
extern int mstrcmp(const char* s1, const char* s2);
extern uint32 pow(uint32 num1, uint32 num2);

#endif

