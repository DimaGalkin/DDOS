#ifndef INPUT_H
#define INPUT_H

#include "types.h"
#include "vga.h"

extern char get_input_keycode();
extern void input(char* string,int len);
extern void pass_input(char* string,int len);
extern byte arrows();
extern int hidden;
extern int shifted;
extern int ipt_idx;

#endif
