#include "memlib.h"

uint16* memory_buffer;
int mem_idx;

// uint16* memory_buffer;
// memory_buffer = (uint16*)MEMORY_START;
// memory_buffer[0] = 12;
// print_int(memory_buffer[0]);

// static const uint32 MY_DATA_SIZE = 256;
// uint32 a1[MY_DATA_SIZE];
// uint32 a2[MY_DATA_SIZE];

// for(uint32 i = 0; i<MY_DATA_SIZE; ++i)
// {
// a1[0] = i;
// }

// uint8* psrc = (uint8*)(a1);
// uint8* pdst = (uint8*)uint16* memory_buffer;
// memory_buffer = (uint16*)MEMORY_START;
// memory_buffer[0] = 12;
// print_int(memory_buffer[0]);

// static const uint32 MY_DATA_SIZE = 256;
// uint32 a1[MY_DATA_SIZE];
// uint32 a2[MY_DATA_SIZE];

// for(uint32 i = 0; i<MY_DATA_SIZE; ++i)
// {
// a1[0] = i;
// }

// uint8* psrc = (uint8*)(a1);
// uint8* pdst = (uint8*)(a2);

// for(uint32 i = 0; i<MY_DATA_SIZE * sizeof(uint32); ++i)
// {
// *pdst = *psrc;
// psrc++;
// pdst++;
// }

// for(uint32 i = 0; i<MY_DATA_SIZE; ++i)
// {
// if(a1[i] != a2[i])
//     print("DATA MISMATCH!");
// }(a2);

//       for(uint32 i = 0; i<MY_DATA_SIZE * sizeof(uint32); ++i)
//       {
//         *pdst = *psrc;
//         psrc++;
//         pdst++;
//       }

//       for(uint32 i = 0; i<MY_DATA_SIZE; ++i)
//       {
//         if(a1[i] != a2[i])
//           print("DATA MISMATCH!");
//       }

void init_memlib() {
    mem_idx = 0;
    memory_buffer = (uint16*)MEMORY_START;
}

void mem_write(int index, uint8 data) {
    memory_buffer[index] = data;
    mem_idx++;
}

uint8 mem_read(int index) {
    return memory_buffer[index];
}

int mem_chunk_read(uint8 chunk[1024], int chunk_start, int chunk_end) {
    if(chunk_start > chunk_end) {
        return 1;
    }

    int x = 0;
    for(int i = chunk_start; i < chunk_end + 1; ++i) {
        chunk[x] = mem_read(i);
        ++x;
    }
    return 0;
}