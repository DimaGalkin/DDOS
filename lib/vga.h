#ifndef VGA_H
#define VGA_H

#include "types.h"

extern uint32 vga_idx;
extern uint32 nl_idx;
extern uint8 stc_fg_col, stc_bg_col;
extern int dgt_codes[10];

extern uint16 vga_ipt(unsigned char ch, uint8 fg_col, uint8 bg_col);
extern void cls_vga_buffer(uint16 **buffer, uint8 fg_col, uint8 bg_col);
extern void init_vga(uint8 fg_col, uint8 bg_col);

extern uint16* vga_buffer;
extern uint16* backup_vga_buffer;

extern uint8 text_color;
extern uint8 back_color;

#endif
