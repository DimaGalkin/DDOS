#ifndef ACSII
#define ASCII

#include "types.h"
#include "utils.h"

extern uint8 charToASCII(char charachter);
extern char ASCIItoChar(uint8 charachter);
extern uint32 charsToInt(char* charachters); 
extern uint8 charToInt(char charachter);
extern void lower(char* name);

#endif