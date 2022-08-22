#include "memlib.h"

uint16* memory_buffer;

void init_memlib() {
    memory_buffer = (uint16*)MEMORY_START;
}

uint8 mem_read(int index) {
  return memory_buffer[index];
}

void mem_write(uint32 index, uint8 data) {
  memory_buffer[index] = data;
}