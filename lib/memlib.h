#ifndef memlib
#define memlib

#include "types.h"

#define MEMORY_START 0x00007F00
#define MEMORY_LENGTH 1024

extern void init_memlib();
extern uint8 mem_read(int index);
extern void mem_write(uint32 index, uint8 data);
extern uint16* memory_buffer;

#endif