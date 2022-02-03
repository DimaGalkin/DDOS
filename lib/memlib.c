#include "memlib.h"

uint16* memory_buffer;
uint16* system_memory_buffer;
int mem_idx;
int sys_mem_idx;

struct memory_address_table {
  int memory_idx;
  char process_name[64];
};

struct free_memory_locator {
  int isfree;
  int address;
  int proccess_code;
};

struct memory_address_table memory_lookup_table[MEMORY_LENGTH];
struct free_memory_locator memory_ownership_table[MEMORY_LENGTH];

char mem_read(char* p_name){
    int mem_dx = 0;
    for(int i = 0; i < MEMORY_LENGTH; ++i) {
      if(mstrcmp(memory_lookup_table[i].process_name, p_name) == 1) {
        mem_dx = memory_lookup_table[i].memory_idx; 
        break;
      }
    }

    uint8 data_t = memory_buffer[mem_dx];
    char data = ASCIItoChar(data_t);
    return data;
}

void mem_write(char data_char, char* prog_name){

  uint8 data = charToASCII(data_char);

  for (uint32 i = 0; i < strlen(prog_name); ++i) {
    memory_lookup_table[mem_idx].process_name[i] = prog_name[i];
  }
  memory_lookup_table[mem_idx].memory_idx = mem_idx;

  memory_buffer[mem_idx] = data;
  mem_idx++;
}

void init_memlib() {
    memory_buffer = (uint16*)MEMORY_START;
    system_memory_buffer = (uint16*)SYSTEM_MEMORY_START;
    for(int i = 0; i < MEMORY_LENGTH + 1; ++i) {
        memory_buffer[i] = NULL;
        system_memory_buffer[i] = NULL;
        memory_ownership_table[i].isfree = 1;
        memory_ownership_table[i].address = i;      
    }
    mem_idx = 0;
}

int sys_mem_write(int index, uint8 data) {
    system_memory_buffer[index] = data;
    sys_mem_idx++;
    return sys_mem_idx;
}

uint8 sys_mem_read(int index) {
    return system_memory_buffer[index];
}