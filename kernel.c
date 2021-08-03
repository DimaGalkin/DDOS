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

void cmd_init(){
  cls_vga_buffer(&vga_buffer, stc_fg_col, stc_bg_col);
  static int i = 0; 
  char string[500];
  stc_bg_col = BLACK;
  fill_box(0, 0, 0, BOX_MAX_WIDTH - 8, 4, BLACK);
  draw_box(BOX_DOUBLELINE, 0, 0, BOX_MAX_WIDTH - 8, 4, WHITE, BLACK);
  gotocoord(2, 1);
  print_col("Welcome to the Kernel CMD", WHITE, BLACK);
  gotocoord(2, 3);
  print_col("For a list of commands: ", WHITE, BLACK);
  gotocoord(28, 3);
  print_col("CMD", YELLOW, BLACK);
  for(i = 0; i < 6; i++){
	print_nl();
  } 
  print_col("Kernel@C:\\> ", WHITE, BLACK);
  pos_idx = 10;
  while(shutdown == 0){
	sleep(sleep_time1);
	test_input(string,500);
	if(in(string,blocked,sfblocked)==0){
		find_pkg_by_name(string)->f();
		if(mstrcmp(string, "SHUTDOWN") == 1){
			break;
		}else if(mstrcmp(string, "EXIT") == 1){
			exit_cmd();
			break;
		}else if(mstrcmp(string, "GU") == 1){
			gui_init();
		}
	}
	if(pos_idx > 10){
		pos_idx = 0;
		print_nl();
		print_col("Kernel@C:\\> ", WHITE, BLACK);
	}
  }
}

void kernel_entry(){
  init_vga(WHITE, BLUE);
  while(shutdown == 0){
  	while(gui == 0){
	  cmd_init();
	  gui = 1;
  	}
	while(gui == 1){
		gui_init();
	}
  }
  cls_vga_buffer(&vga_buffer, stc_fg_col, BLACK);
  while(1){print("sh");}
}