#include "utils.h"

char DDOS_VERSION[6] = "v1.0.0";

uint32 strlen(const char* str)
{
  uint32 length = 0;
  while(str[length])
    length++;
  return length;
}

uint32 digit_count(int num)
{
  uint32 count = 0;
  if(num == 0)
    return 1;
  while(num > 0){
    count++;
    num = num/10;
  }
  return count;
}

uint32 pow(uint32 num1, uint32 num2) {
  for(uint32 i = 0; i < num2; ++i) {
    num1 = num1 * num2;
  }

  return num1;
}

void itoa(int num, char *number)
{
  int dgcount = digit_count(num);
  int index = dgcount - 1;
  char x;
  if(num == 0 && dgcount == 1){
    number[0] = '0';
    number[1] = '\0';
  }else{
    while(num != 0){
      x = num % 10;
      number[index] = x + '0';
      index--;
      num = num / 10;
    }
    number[dgcount] = '\0';
  }
}

int mstrcmp(const char* s1, const char* s2){
	const char* p1 = s1;
	const char* p2 = s2;
	while(*p1 != 0 && *p2 != 0){
		if(*p1 == *p2){
			++p1;
			++p2;
		}else{
			return 0;
		}
	}
	if (*p1 == *p2) return 1;
	return 0;
}
int in(char* what, char* where[], int size){
	for(int idx = 0; idx < size; ++idx){
		if(mstrcmp(what, where[idx]) == 1){
			return 1;
		}
	}
	return 0;
}