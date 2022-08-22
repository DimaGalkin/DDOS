#ifndef VGA_H
#define VGA_H

#include "types.h"
#include "io.h"

extern uint16 box_draw_char(uint8 chn, uint8 fg_col, uint8 bg_col);
extern void gotocoord(uint16 x, uint16 y);
extern void draw_generic_box(uint16 x, uint16 y, 
                      uint16 width, uint16 height,
                      uint8 fg_col, uint8 bg_col,
                      uint8 topleft_ch,
                      uint8 topbottom_ch,
                      uint8 topright_ch,
                      uint8 leftrightside_ch,
                      uint8 bottomleft_ch,
                      uint8 bottomright_ch);
                      
extern void draw_box(uint8 boxtype, 
              uint16 x, uint16 y, 
              uint16 width, uint16 height,
              uint8 fg_col, uint8 bg_col);
              
extern void fill_box(uint8 ch, uint16 x, uint16 y, uint16 width, uint16 height, uint8 color);

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
