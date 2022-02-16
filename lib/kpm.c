#include "kpm.h"

int packages_call(char* name) {
    
    if(mstrcmp(name, "clear") == 1) {
        cls_vga_buffer(&vga_buffer, stc_fg_col, back_color);
        return 1;
    }
    else if(mstrcmp(name, "edit") == 1) {
        text();
        return 1;
    }
    return 0;
}