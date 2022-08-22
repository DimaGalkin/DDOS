#include "vga.h"

uint32 vga_idx;
uint32 nl_idx = 1;
uint8 stc_fg_col = WHITE, stc_bg_col = BLACK;
int dgt_codes[10] = {0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39};

uint16* vga_buffer;

uint8 text_color = RED;
uint8 back_color = BLACK;

uint16 vga_ipt(unsigned char ch, uint8 fg_col, uint8 bg_col){
	uint16 ax = 0;
	uint8 ah = 0, al = 0;
	ah = bg_col;
	ah <<= 4;
	ah |= fg_col;
	ax = ah;
	ax <<= 8;
	al = ch;
	ax |= al;
	return ax;
}

void cls_vga_buffer(uint16 **buffer, uint8 fg_col, uint8 bg_col){
	uint32 i;
	for(i = 0; i < BUFSIZE; i++){
		(*buffer)[i] = vga_ipt(NULL, fg_col, bg_col);
	}
	nl_idx = 1;
	vga_idx = 0;
}

uint16 box_draw_char(uint8 chn, uint8 fg_col, uint8 bg_col){
	uint16 ax = 0;
	uint8 ah = 0;
	ah = bg_col;
	ah <<= 4;
	ah |= fg_col;
	ax = ah;
	ax <<= 8;
	ax |= chn;
	return ax;
}

void gotocoord(uint16 x, uint16 y){
	vga_idx = 80*y;
	vga_idx += x;
}

void draw_generic_box(uint16 x, uint16 y, 
                      uint16 width, uint16 height,
                      uint8 fg_col, uint8 bg_col,
                      uint8 topleft_ch,
                      uint8 topbottom_ch,
                      uint8 topright_ch,
                      uint8 leftrightside_ch,
                      uint8 bottomleft_ch,
                      uint8 bottomright_ch){
	uint32 i;
	vga_idx = 80*y;
	vga_idx += x;
	vga_buffer[vga_idx] = box_draw_char(topleft_ch, fg_col, bg_col);
	vga_idx++;
	for(i = 0; i < width; i++){
		vga_buffer[vga_idx] = box_draw_char(topbottom_ch, fg_col, bg_col);
		vga_idx++;
	}
	vga_buffer[vga_idx] = box_draw_char(topright_ch, fg_col, bg_col);
	y++;
	vga_idx = 80*y;
	vga_idx += x;
	for(i = 0; i < height; i++){
    		vga_buffer[vga_idx] = box_draw_char(leftrightside_ch, fg_col, bg_col);
    		vga_idx++;
    		vga_idx += width;
    		vga_buffer[vga_idx] = box_draw_char(leftrightside_ch, fg_col, bg_col);
    		y++;
    		vga_idx = 80*y;
    		vga_idx += x;
  	}
  	vga_buffer[vga_idx] = box_draw_char(bottomleft_ch, fg_col, bg_col);
  	vga_idx++;
  	for(i = 0; i < width; i++){
    		vga_buffer[vga_idx] = box_draw_char(topbottom_ch, fg_col, bg_col);
    		vga_idx++;
  	}
  	vga_buffer[vga_idx] = box_draw_char(bottomright_ch, fg_col, bg_col);
  	vga_idx = 0;
}

void draw_box(uint8 boxtype, 
              uint16 x, uint16 y, 
              uint16 width, uint16 height,
              uint8 fg_col, uint8 bg_col)
{
  switch(boxtype){
    case BOX_SINGLELINE : 
      draw_generic_box(x, y, width, height, 
                      fg_col, bg_col, 
                      218, 196, 191, 179, 192, 217);
      break;

    case BOX_DOUBLELINE : 
      draw_generic_box(x, y, width, height, 
                      fg_col, bg_col, 
                      201, 205, 187, 186, 200, 188);
      break;
  }
}

void fill_box(uint8 ch, uint16 x, uint16 y, uint16 width, uint16 height, uint8 color){
  uint32 i,j;

  for(i = 0; i < height; i++){
    vga_idx = 80*y;
    vga_idx += x;

    for(j = 0; j < width; j++){
      vga_buffer[vga_idx] = box_draw_char(ch, 0, color);
      vga_idx++;
    }
    y++;
  }
}

void init_vga(uint8 fg_col, uint8 bg_col){
	vga_buffer = (uint16*)VGA_ADDRESS;
	cls_vga_buffer(&vga_buffer, fg_col, bg_col);
	stc_fg_col = fg_col;
	stc_bg_col = bg_col;
	outb(0x3D4, 0x0A);
	outb(0x3D5, 0x20);
}