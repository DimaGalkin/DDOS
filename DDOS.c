//include all of the neccsary libraries
#include "lib/vars.h"
#include "lib/vga.h"
#include "lib/print.h"
#include "lib/memlib.h"
#include "lib/kpm.h"
#include "lib/draw.h"
#include "lib/types.h"
#include "lib/utils.h"

// define the CLI
void CLI(){
  // define the variable where the input will be stored
  char string[64];
  // define the position of the cursor
  pos_idx = 12;
  int shutdown = 0;
  
  // clear display and print
  cls_vga_buffer(&vga_buffer, stc_fg_col, back_color);
  draw_box(BOX_DOUBLELINE, 4, 0, 70, 4, WHITE, back_color);
  gotocoord(24,1);
  print_col("This is the DDOS operating system!", text_color, back_color);
  gotocoord(32,3);
  print_col("Version ", text_color, back_color);
  print_col(DDOS_VERSION, text_color, back_color);
  gotocoord(0,6);
  print_col("DDOS@C:\\> ", text_color, back_color);
  
  // make a loop in which the DDOS stay in until we are done 
  while(shutdown == 0){
    //get input to execute command
    string[0] = NULL;
    while(string[0] == NULL) {input(string, 64);}
    
    // call the package execute command and say if it could be found;

    if(packages_call(string) == 0) {
      print_nl();
      print("No Package By The Name `");
      print(string);
      print("` Could Be Found");
      print_nl();
    } else {
      print_nl();
    }

    // check cursor position
    if(pos_idx > 12){
      pos_idx = 0;
      print_col("DDOS@C:\\> ", text_color, back_color);
    }
    // check if we are at the end of the screen
    if(nl_idx >= 25){
      cls_vga_buffer(&vga_buffer, stc_fg_col, back_color);
      print_col("DDOS@C:\\> ", text_color, back_color);
    }
  }
}

// this is our main function which starts everything 
void DDOS(){
  // initialiase display adapter
  init_vga(text_color, back_color);
  // initialize the memory library
  init_memlib();
  // start CLI
	CLI();
}