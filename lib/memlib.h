#ifndef memlib
#define memlib

#include "types.h"
#include "utils.h"
#include "print.h"
#include "vga.h"
#include "print.h"
#include "acsii.h"

#define MEMORY_START 0x00007F00
#define MEMORY_LENGTH 256

#define ARR_START 0x01000000
#define ARR_LENGTH 128 

extern void init_memlib();
extern int mem_write(int index, uint8 data);
extern uint8 mem_read(int index);
extern void memory_write(char* data, int chunkid);
extern void memory_read(char* data, int chunkid);
extern char arrget(int idef, int idx);
extern int arrwrite(int idef, char data, int idx);
extern int arrcreate(int len);
extern void aredel(int idef);
extern int arrsize(int idef);
extern int mem_idx;
extern uint16* memory_buffer;
extern const int mtbl;

#endif