#include "input.h"

#include "keyboard.h"
#include "io.h"
#include "print.h"
#include "char.h"
#include "sleep.h"
#include "vars.h"

char get_input_keycode()
{
  char ch = 0;
  while((ch = inb(KEYBOARD_PORT)) != 0){
    if(ch > 0)
      return ch;
  }
  return ch;
}

void test_input(char* string,int len)
{
  char ch = 0;
  char keycode = 0;
  int numChars = 0;
  do{
    keycode = get_input_keycode();
    if(keycode == KEY_ENTER){
    		//enter = 1;
		break;
     }else if(keycode == KEY_BACKSPACE){
     	del_char();
     	string[numChars--] = NULL;
    }else if(keycode == KEY_UP){
    	arrow = 1;
    	break;
    }else if(keycode == KEY_DOWN){
    	arrow = 2;
    	break;
    }else if(keycode == KEY_LEFT){
    	arrow = 3;
    	break;
    }else if(keycode == KEY_RIGHT){
    	arrow = 4;
    	break;
    }else{
      ch = get_ascii_char(keycode);
      printc(ch);
      string[numChars++] = ch;
    }
    sleep(sleep_time1);
    //sleep(0x25FFFFFF);
  }while(ch > 0 && numChars < len && pos_idx > 10);
  string[numChars] = 0;
}
