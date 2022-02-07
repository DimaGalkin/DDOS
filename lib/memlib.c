#include "memlib.h"

uint16* memory_buffer;
int mem_idx;
int chunk_idx;

struct memory_table_t {
  int isfree;
  int chunk_id;
  int memory_address;
};

void init_memlib() {
    memory_buffer = (uint16*)MEMORY_START;
    mem_idx = 0;
    chunk_idx = 0;
}

int mem_write(int index, uint8 data) {
    memory_buffer[index] = data;
    mem_idx++;
    return mem_idx;
}

uint8 mem_read(int index) {
    return memory_buffer[index];
}