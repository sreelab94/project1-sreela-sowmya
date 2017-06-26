/**
 * @file conversion.h 
 * @brief This file contains function declarations of conversion.c.
 *
 * @author Sreela Pavani Bhogaraju
 * @date June 25 , 2017
 *
 */

#ifndef __CONVERSION_H__
#define __CONVERSION_H__



#include <stdint.h>
#include <stdlib.h>
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);
int8_t big_to_little32(uint32_t * data, uint32_t length);
int8_t little_to_big32(uint32_t * data, uint32_t length);




#endif /* __CONVERSION_H__ */
