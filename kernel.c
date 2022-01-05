#include "lib/types.h"
#include "lib/keyboard.h"
#include "lib/utils.h"
#include "lib/char.h"
#include "lib/vars.h"
#include "lib/sleep.h"
#include "lib/io.h"
#include "lib/vga.h"
#include "lib/print.h"
#include "lib/draw.h"
#include "lib/input.h"

uint8 text_color = RED;
uint8 back_color = BLACK;

void cmd_init(){
  cls_vga_buffer(&vga_buffer, stc_fg_col, back_color);
  static int i = 0; 
  char string[500];
  print_col("Kernel@C:\\> ", text_color, back_color);
  pos_idx = 12;
  while(shutdown == 0){
	sleep(sleep_time1);
	test_input(string,500);
  if(mstrcmp(string, "CLEAR") == 1){
      cls_vga_buffer(&vga_buffer, stc_fg_col, back_color);
  }
	if(pos_idx > 12){
		pos_idx = 0;
		print_nl();
		print_col("Kernel@C:\\> ", text_color, back_color);
  }
  if(nl_idx >= 25){
    cls_vga_buffer(&vga_buffer, stc_fg_col, back_color);
    i = 0; 
    fill_box(0, 0, 0, BOX_MAX_WIDTH - 8, 4, back_color);
    draw_box(BOX_DOUBLELINE, 0, 0, BOX_MAX_WIDTH - 8, 4, text_color, back_color);
    gotocoord(2, 1);
    print_col("Welcome to the Kernel CMD", text_color, back_color);
    gotocoord(2, 3);
    print_col("For a list of commands: ", text_color, back_color);
    gotocoord(28, 3);
    print_col("CMD", YELLOW, back_color);
    for(i = 0; i < 6; i++){
      print_nl();
    }
    print_col("Kernel@C:\\> ", text_color, back_color);
  }
  }
}

void kernel_entry(){
  init_vga(text_color, back_color);

  char string[500];
  int br = 0;
  while(br == 0){
    cls_vga_buffer(&vga_buffer, stc_fg_col, back_color);
    gotocoord(11, 5);
    print("password: ");
    pass_input(string, 500);
    if(mstrcmp(string, "mypass") == 1){
      br = 1;
    }
  }
  while(shutdown == 0){
	  cmd_init();
  }
  cls_vga_buffer(&vga_buffer, stc_fg_col, back_color);
}
