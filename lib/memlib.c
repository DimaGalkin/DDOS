#include "memlib.h"

struct mem_block {
    int ptr;
    int size;
};

struct mem_block mem_table[1024] = {{NULL, NULL}};

void print_mem(int idx){
    print_nl();
    print("ID: ");
    print_int(mem_table[idx].ptr);
    print_nl();
    print("Bytes: ");
    print_int(mem_table[idx].size);
}

int memalloc(int size) {
    for(int a = 1; a < 1024; ++a){
        if(mem_table[a].ptr == NULL){
            mem_table[a].ptr = a;
            mem_table[a].size = size;
            print_mem(mem_table[a].ptr);
            return 1;
        }
    }
    return 0;
}

void free(int idx) {
    mem_table[idx].ptr = NULL;
    mem_table[idx].size = NULL;
}