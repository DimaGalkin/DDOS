#include "vga.h"

#include "io.h"

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

void init_vga(uint8 fg_col, uint8 bg_col){
	vga_buffer = (uint16*)VGA_ADDRESS;
	cls_vga_buffer(&vga_buffer, fg_col, bg_col);
	stc_fg_col = fg_col;
	stc_bg_col = bg_col;
	outb(0x3D4, 0x0A);
	outb(0x3D5, 0x20);
}
