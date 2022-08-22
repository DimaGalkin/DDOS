#ifndef IO_H
#define IO_H

#include "types.h"

extern uint8 inb(uint16 port);
extern void outb(uint16 port, uint8 data);

#endif
