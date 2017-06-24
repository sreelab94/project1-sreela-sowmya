#ifndef __MEMORY_H__
#define __MEMORY_H__

# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>


uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);
uint8_t * my_memcpy(uint8_t * src, uint8_t * dst, size_t length);
int8_t * my_memset(uint8_t * src, size_t length, uint8_t value);
uint8_t * my_memzero(uint8_t * src, size_t length);
uint8_t * my_reverse(uint8_t * src, size_t length);
uint32_t * reserve_words(size_t length);  /* Changed to unsigned to match with free_words function*/
void free_words(uint32_t * src);
void swap(uint8_t*, uint8_t*);

#endif /* __MEMORY_H__ */