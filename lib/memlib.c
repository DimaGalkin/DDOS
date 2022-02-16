#include "memlib.h"

uint16* memory_buffer;
uint16* container_memory;
int mem_idx;
int chunk_idx;
int arr_ptr = 0;

struct memory_table_t {
  int isfree;
  int chunk_id;
  int memory_address;
  int vgaid;
};

struct memory_table_t memory_table[MEMORY_LENGTH];

struct arr_p {
    int length;
    int start_idx;
    int end_idx;
    int size;
};

struct arr_p arr[ARR_LENGTH];

const int mtbl = MEMORY_LENGTH;

void init_memlib() {
    memory_buffer = (uint16*)MEMORY_START;
    container_memory = (uint16*)ARR_START;
    mem_idx = 0;
    chunk_idx = 0;
    for(int i = 0; i < mtbl; ++i) {
        memory_table[i].isfree = 1;
        memory_table[i].memory_address = i;
        memory_table[i].chunk_id = NULL;
    }

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

void memory_write(char* data, int chunkid) {
    for(uint16 i = 0; i < strlen(data); ++i) {
        for(uint16 x = 0; x < sizeof(memory_table); ++x) {
            if(memory_table[x].isfree == 1) {
                memory_table[x].isfree = 0;
                memory_table[x].chunk_id = chunkid;
                mem_write(memory_table[x].memory_address, charToASCII(data[i]));
                break;
            }
        }
    }
}

void memory_read(char* data, int chunkid) {
    int idx = 0;
    for(int i = 0; i < mtbl; ++i) {
        if(memory_table[i].chunk_id == chunkid) {
            data[idx] = charToASCII(mem_read(memory_table[i].memory_address));
            idx++;
        }
    }
}

void memory_del(int idx) {
    memory_table[idx].isfree = 1;
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