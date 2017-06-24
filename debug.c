# include "debug.h"

void print_memory(uint8_t * start, uint32_t length)
{
#ifdef VERBOSE	
	uint8_t i;
	if(start == NULL) 
    {
        printf("\nNothing is assigned to start pointer..exiting\n");
        exit(1);
    }
	printf("The hex output of the bytes are :\n");
	for(i=0;i<length;i++)
	{
		printf("%x   ",*(start+i));
	}
	printf("\n");
	
#else
    return;
#endif
}