#ifndef INPUT_H
#define INPUT_H

#include "types.h"
#include "vga.h"
#include "memlib.h"

extern char get_input_keycode();
extern void input(char* string,int len);
extern int input_text(char* string, int len, int deleteTable, int arraySize, int vgaTable);
extern byte arrows();
extern int hidden;
extern int shifted;
extern int ipt_idx;

#endif
