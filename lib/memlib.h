#ifndef memlib
#define memlib

#include "types.h"
#include "utils.h"
#include "print.h"
#include "vga.h"
#include "print.h"
#include "acsii.h"

#define MEMORY_START 0x00007F00
#define SYSTEM_MEMORY_START 0x00100000
#define MEMORY_LENGTH 1024

extern void init_memlib();
extern void mem_write(char data, char* prog_name);
extern char mem_read(char* p_name);
extern int sys_mem_write(int index, uint8 data);
extern uint8 sys_mem_read(int index);
extern int mem_chunk_read(uint8 chunk[1024], int start_chunk, int end_chunk);
extern int mem_idx;
extern int sys_mem_idx;
extern uint16* memory_buffer;
extern uint16* system_memory_buffer;

#endif