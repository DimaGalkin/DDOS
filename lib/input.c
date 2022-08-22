#include "input.h"

int ipt_idx = 0;
int shifted = 0;
int hidden = 0;

char get_input_keycode()
{
  char ch = 0;
  while((ch = inb(KEYBOARD_PORT)) != 0){
    if(ch > 0)
      return ch;
  }
  return ch;
}

void input(char* string,int len)
{
  char ch = 0;
  char keycode = 0;
  int numChars = 0;
  do{
    if((inb(0x64) & 1) == 0) continue;
    keycode = get_input_keycode();
    if(keycode == KEY_ENTER){
      string[numChars++] = '\0';
		  break;
    }else if(keycode == KEY_SHIFT){
      if(shifted == 0){
        shifted = 1;
      }else{
        shifted = 0;
      }
    }else if(keycode == KEY_BACKSPACE){
     	del_char();
     	string[numChars--] = NULL;
    }else{
      ch = get_ascii_char(keycode);
      ++ipt_idx;
      if(hidden == 1){
        printc('*');
      }else{
        printc(ch);
      }
      string[numChars++] = ch;
    }
    if (keycode == KEY_ESC){
      cls_vga_buffer(&vga_buffer, stc_fg_col, back_color);
    }
  }while(ch > 0 && numChars < len && pos_idx > 10);
  string[numChars] = 0;
}
