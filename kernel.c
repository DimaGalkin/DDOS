//include all of the neccsary libraries
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
#include "lib/memlib.h"
#include "lib/acsii.h"
#include "lib/kpm.h"
#include "lib/editor.h"

// define the CLI
void CLI(){
  // define the variable where the input will be stored
  char string[64];
  // define the position of the cursor
  pos_idx = 12;
  int shutdown = 0;
  
  // clear display and print
  cls_vga_buffer(&vga_buffer, stc_fg_col, back_color);
  print_col("Kernel@C:\\> ", text_color, back_color);
  
  // make a loop in which the kernel stay in until we are done 
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
      print_col("Kernel@C:\\> ", text_color, back_color);
    }
    // check if we are at the end of the screen
    if(nl_idx >= 25){
      cls_vga_buffer(&vga_buffer, stc_fg_col, back_color);
      print_col("Kernel@C:\\> ", text_color, back_color);
    }
  }
}

// this is our main function which starts everything 
void kernel_entry(){
  // initialiase display adapter
  init_vga(text_color, back_color);
  // initialize the memory library
  init_memlib();
  // start CLI
	CLI();
}