#include "kpm.h"

char string[64];
char string2[64];

uint8 call_package(char* name) {
    if (mstrcmp(name, "create") == 1) {
        print_int(NULL);
    } else if(mstrcmp(name, "clear") == 1){
        cls_vga_buffer(&vga_buffer, stc_fg_col, back_color);
    }

    return 0;
}