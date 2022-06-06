#include "memlib.h"

uint16* memory_buffer;
uint16* container_memory;
int mem_idx;
int chunk_idx;
int arr_ptr = 0;

struct arr_p {
    int length;
    int start_idx;
    int end_idx;
    int size;
};

struct arr_p arr[ARR_LENGTH];

void init_memlib() {
    memory_buffer = (uint16*)MEMORY_START;
    container_memory = (uint16*)ARR_START;
    mem_idx = 0;
    chunk_idx = 0;

    for(int x = 0; x < ARR_LENGTH; ++x) {
        arr[x].length = -1;
    }
}

int mem_write(int index, uint8 data) {
    memory_buffer[index] = data;
    mem_idx++;
    return mem_idx;
}

uint8 mem_read(int index) {
    return memory_buffer[index];
}

int arrcreate(int len) {
    for(int idef = 0; idef < ARR_LENGTH; ++idef) {
        if(arr[idef].length == -1) {
            arr[idef].length = len;
            arr[idef].start_idx = arr_ptr;
            arr[idef].end_idx = arr_ptr + len;
            arr_ptr += len;
            return idef;
        }
    }
    return ARR_LENGTH + 1;
}

void arrdestroy(int idef) {
    arr[idef].length = -1;
    arr[idef].size = 0;
} 

int arrwrite(int idef, char data, int idx) {
    int index = arr[idef].start_idx + idx;
    if ((index - 1) < arr[idef].end_idx) { 
        container_memory[index] = charToASCII(data);
        arr[idef].size++;
        return 1;
    } else {
        return 0;
    }
}

char arrget(int idef, int idx) {
    int index = arr[idef].start_idx + idx;
    return ASCIItoChar(container_memory[index]);
}

void arrdel(int idef) {
    arr[idef].size--;
}

int arrsize(int idef) {
    return arr[idef].size;
}