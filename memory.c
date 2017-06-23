
# include "memory.h"

void main()
{
	uint8_t i,s[20] = "MynameisSowmya",b[20] = "MynameisSowmya";  // = "My name is Sowmya";

	uint8_t d[10],str_len;
	//uint32_t * p;
    uint8_t * p;                          // Pointer for some functions

	printf("\nbefore copy :%s\n",d);
    //p = my_memmove(s,d,sizeof(s));
    str_len = sizeof(s)/sizeof(uint8_t);
    p = my_memcpy(s,(s+3),str_len);
    printf("\n memcpy o/p is %s\n",p);
    p = my_memmove(b,(b+3),str_len);
    printf("\n memmove o/p is %s\n",p);
    //p = my_memset(s,7,'&');
    //p = my_memzero(s,8);
    //p = my_reverse(s,18);
    //p = reserve_words(10);
    //printf("\n p address is %p\n",p);
    //free_words(p);
	return;
}
/* 
This function copies byte by byte from source to destination
NOTE : my_memmove() checks the lengths of source and destination hence no memory is corrupted
Inputs - pointer to source, pointer to destination, length of the bytes to be copied
Returns - pointer to destination byte
*/
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{
    printf("\n  src is %s\n",src);
    uint8_t i,temp[DEST_SIZE];                       /*Temp variable to store source contents*/
    if(src == NULL)
    {
        printf("\nNothing is assigned to source..exiting\n");
        exit(1);
    }

    else 
    {
        for(i = 0;i<length;i++)
        {
            *(temp+i) = *(src+i);

        }     

        printf("\n temp is %s\n",temp);
        for(i = 0;i<length;i++)
        {
            *(dst+i) = *(temp+i);

        }
    }
    return dst;
}
/* 
This function copies byte by byte from source to destination
NOTE : my_memcpy() doesn't check the lengths of source and destination hence some memory locations could get corrupted with unwanted data
Inputs - pointer to source, pointer to destination, length of the bytes to be copied
Returns - pointer to destination byte
*/
uint8_t * my_memcpy(uint8_t * src, uint8_t * dst, size_t length)
{
	uint8_t i;
	if(src == NULL)
 	{
 		printf("\nNothing is assigned to source..exiting\n");
 		exit(1);
 	}
 	else 
 	{
    	for(i = 0;i<length;i++)
 		{
 			*(dst+i) = *(src+i);
 		}
 	}
 	return dst; 
}
/* 
This function sets the source with value till a specified length
Inputs - Pointer to source, length of bytes to be changed, Value to be placed in the source
Returns - Pointer to the source
*/
int8_t * my_memset(uint8_t * src, size_t length, uint8_t value)
{ 
	uint8_t i;
	if(src == NULL)
 	{
 		printf("src pointer doesn't point to anything..exiting\n");
 		exit(1);
 	}
 	for(i = 0;i<length;i++)
 	{
 		*(src+i) = value;
 	}
    return src;
}
/*
This function zero out all of the memory that a source pointer points to upto a given length 
Inputs - pointer to source, length
Returns - Pointer to source
*/
uint8_t * my_memzero(uint8_t * src, size_t length)
{
    uint8_t i;
	if(src == NULL)
 	{
 		printf("src pointer doesn't point to anything..exiting\n");
 		exit(1);
 	}
 	for(i = 0;i<length;i++)
 	{
 		*(src+i) = '0';
 	}
    return src;
}
/*
This function reverses the contents of a memory location upto a given length
Input - Source pointer , length of bytes to be reversed
Output - Pointer to the source
*/
uint8_t * my_reverse(uint8_t * src, size_t length)
{
	uint8_t i;
    for(i = 0;i<(length/2);i++)  
    { 
  		swap((src+i),(src+(length-i)-1));
    }
    return src;
}
/*
Generic swap function to swap two bytes
Inputs - Two byte pointers a and b pointing to two bytes that need to be swapped
Outputs - None
*/
void swap(uint8_t*a, uint8_t*b) 
{
	uint8_t temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
/*
Reserves a given length of memory dynamically 
Input - Length of the dynamic memory needed
Returns - A pointer pointing to the allocated memory
*/
uint32_t * reserve_words(size_t length)
{
	int32_t *ptr = (int32_t*) malloc(length * sizeof(int32_t));  //memory allocated using malloc
    if(ptr == NULL)                     
    {
        printf("Error! memory not allocated.");
        return NULL;
    }
    else
    	return ptr;
}
/*
Frees the dynamically allocated memory 
Input - Pointer to the source
Returns - None
*/
void free_words(uint32_t * src)
{
	free(src);
}


