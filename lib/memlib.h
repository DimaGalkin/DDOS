#ifndef MEM_H
#define MEMH

#include "types.h"
#include "print.h"

extern int memalloc(int size);
extern void free(int ptr) ;
extern void print_mem(int ptr);

#endif