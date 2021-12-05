#ifndef PRINT_H
#define PRINT_H

#include "types.h"

extern void printc(char ch);
extern void printc_no(char ch);
extern void print(char *str);
extern void del_char();
extern void print_nl();
extern void print_col(char* str, uint8 fg_col, uint8 bg_col);
extern void print_int(int num);
extern void print_int_color(int num, uint8 fc, uint8 bc);
extern void print_coord(char* str, uint16 x, uint16 y, uint8 ff, uint8 bb);

#endif
