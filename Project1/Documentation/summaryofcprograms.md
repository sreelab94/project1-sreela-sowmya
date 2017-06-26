/* list of all c programs */

 /************************************************************
 *
 *conversion.c
 *
 ***************************************************************/



 uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
 {
 /*
  * @brief - itoa converts integer to a string of ASCII characters and returns the size of the string including the minus and the null          *  terminator 
       Long : Signed integer is converted into the given base and this data is again converted into ASCII and is stored in a string .Then the   *size of the string is returned  
  * @param - 1st argument :the integer which needs to be converted to ASCII , 
  *          2nd argument :the pointer to the ASCII string,
  *          3rd argument :base , the number system into which the given signed integer should be converted into and then converted to ASCII 
  * @return - length of the string including the minus and null terminator
  *
  */
  } 



 int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
 {
 /*
  * @brief - atoi converts an ASCII string into a signed integer and returns it  
    Long :   A pointer to an ASCII string is given along with the base and length of the string , the set of ASCII characters are converted     *  back into the signed integer using the base given   
  * @param - 1st argument :the pointer to the ASCII string , 
  *          2nd argument :length of the string,
  *          3rd argument :base , the number system into which the given ASCII string should be converted to a signed integer
  * @return - the signed integer
  *
  */
	
  }



  int8_t big_to_little32(uint32_t * data, uint32_t length)
  {
	/*
  * @brief - big_to_little converts array of data from big endian to little endian representation and returns a non zero value if the           *  conversion fails  
  * @param - 1st argument :pointer to array of data in big endian representation , 
  *          2nd argument :length of the data array,
  * @return - 0 for successful conversion , 1 for NULL pointer and 2 for an empty array 
  */
  }

  int8_t little_to_big32(uint32_t * data, uint32_t length)
  {
	/*
  * @brief - little_to_big32 converts array of data from little endian to big endian representation and returns a non zero value if *the        conversion fails  
  * @param - 1st argument :pointer to array of data in little endian representation , 
  *          2nd argument :length of the data array,
  * @return - 0 for successful conversion , 1 for NULL pointer and 2 for an empty array 
  */
  }

   /**************************************************************************************
  *
  *memory.c
  *
  *
  *
  ***************************************************************************************/


  uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length)
  {
	/* 
  This function copies byte by byte from source to destination
  NOTE : my_memmove() checks the lengths of source and destination hence no memory is corrupted
  Inputs - pointer to source, pointer to destination, length of the bytes to be copied
  Returns - uint8_t
  */
  }


  uint8_t * my_memcpy(uint8_t * src, uint8_t * dst, size_t length)
  {
	/* 
  This function copies byte by byte from source to destination
  NOTE : my_memcpy() doesn't check the lengths of source and destination hence some memory locations could get corrupted with unwanted data
  Inputs - pointer to source, pointer to destination, length of the bytes to be copied
  Returns - pointer to destination byte - uint8_t
  */
  }

  uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value)
  {
	/* 
  This function sets the source with value till a specified length
  Inputs - Pointer to source, length of bytes to be changed, Value to be placed in the source
  Returns - Pointer to the source, uint8_t
  */
  }

  uint8_t * my_memzero(uint8_t * src, size_t length)
  {
	/*
  This function zero out all of the memory that a source pointer points to upto a given length 
  Inputs - pointer to source, length
  Returns - Pointer to source, uint8_t
  */
  }


  uint8_t * my_reverse(uint8_t * src, size_t length)
  {
	/*
  This function reverses the contents of a memory location upto a given length
  Input - Source pointer , length of bytes to be reversed
  Returns - Pointer to the source, uint8_t
  */
  }


  uint32_t * reserve_words(size_t length)  /* Changed to unsigned to match with free_words function*/
  {
	/*
  Reserves a given length of memory dynamically 
  Input - Length of the dynamic memory needed
  Returns - A pointer pointing to the allocated memory, uint32_t
  */
  }

  void free_words(uint32_t * src)
  {
	/*
  Frees the dynamically allocated memory 
  Input - Pointer to the source
  Returns - None
  */
  }

 void swap(uint8_t*, uint8_t*)
 {
	/*
 Generic swap function to swap two bytes
 Inputs - Two byte pointers a and b pointing to two bytes that need to be swapped
 Returns - None
 */
 }
