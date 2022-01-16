#ifndef memlib
#define memlib

#include "types.h"
#include "utils.h"
#include "print.h"

#define MEMORY_START 0x00007F00

extern void init_memlib();
extern void mem_write(int index, uint8 data);
extern uint8 mem_read(int index);
extern int mem_chunk_read(uint8 chunk[1024], int start_chunk, int end_chunk);

#endif