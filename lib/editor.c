#include "editor.h"

void text() {
    cls_vga_buffer(&vga_buffer, stc_fg_col, back_color);
    draw_box(BOX_DOUBLELINE, 0, 0, 78, 1, GREY, back_color);
    gotocoord(34,0);
    print_col("TEXT EDITOR", GREY, back_color);
    gotocoord(0,3);

    int arraySize = 2048;
    int deleteTable = arrcreate(arraySize);
    int vgaTable = arrcreate(arraySize);
    int ret;

    char data[MEMORY_LENGTH];
    data[0] = NULL;
    while(data[0] == NULL){ret = input_text(data, arraySize, deleteTable, arraySize, vgaTable);}
    if(ret == 2) {
        print("There is a Maximum Allowance of ");
        print_int(arraySize);
        print(" Charachters!");
    }
}