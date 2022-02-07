#ifndef memlib
#define memlib

#include "types.h"
#include "utils.h"
#include "print.h"
#include "vga.h"
#include "print.h"
#include "acsii.h"

#define MEMORY_START 0x00007F00
#define MEMORY_LENGTH 2048

extern void init_memlib();
extern int mem_write(int index, uint8 data);
extern uint8 mem_read(int index);
extern int mem_idx;
extern uint16* memory_buffer;

#endif