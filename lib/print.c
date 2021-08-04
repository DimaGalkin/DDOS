#include "print.h"

#include "vga.h"
#include "vars.h"
#include "utils.h"

void printc(char ch){
	vga_buffer[vga_idx] = vga_ipt(ch, stc_fg_col, stc_bg_col);
	vga_idx++;
	pos_idx++;
}

void print(char *str){
	uint32 index = 0;
	while(str[index]){
		printc(str[index]);
		index++;
	}	
}

void del_char()
{
  if(pos_idx > 12){
	vga_buffer[vga_idx - 1] = vga_ipt(NULL, stc_fg_col, stc_bg_col);
	vga_idx--;
	pos_idx--;
  }
}

void print_nl()
{
  if(nl_idx >= 25){
    nl_idx = 0;
    cls_vga_buffer(&vga_buffer, stc_fg_col, stc_bg_col);
  }
  vga_idx = 80*nl_idx;
  nl_idx++;
}

void print_col(char* str, uint8 fg_col, uint8 bg_col){
	uint32 index = 0;
	uint8 fc, bc;
	fc = stc_fg_col;
	bc = stc_bg_col;
	stc_fg_col = fg_col;
	stc_bg_col = bg_col;
	while(str[index]){
		printc(str[index]);
		index++;
	}
	stc_fg_col = fc;
	stc_bg_col = bc;
}

void print_int(int num){
	char str_num[digit_count(num)+1];
	itoa(num, str_num);
	print(str_num);
}

void print_int_color(int num, uint8 fc, uint8 bc){
	char str_num[digit_count(num)+1];
	itoa(num, str_num);
	print_col(str_num, fc, bc);
}

void print_coord(char* str, uint16 x, uint16 y, uint8 ff, uint8 bb){
	uint32 old_idx = vga_idx;
	vga_idx = 80*y;
    vga_idx += x;
	print_col(str,ff,bb);
	vga_idx = old_idx;

}
