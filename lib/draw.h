#ifndef DRAW_H
#define DRAW_H

#include "types.h"

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

#endif
