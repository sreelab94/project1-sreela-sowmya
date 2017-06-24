#include "conversion.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
	uint32_t check=data; //data is copied into check to find out the length of the string without affecting data
	uint8_t stringsize=0;
	uint8_t length = 0;
	uint8_t sign=0;      // sign=0 means the given signed integer is positive and sign=1 means the given signed integer is negative
	if(data<0)
	{
		data=-data;  //data is made positive so that calculations become easier , the minus sign is added later on in the code
		sign=1;
                check = data;
	}		
                while(check!=0)  //the number is divided by the base until the quotient is zero , this helps in finding out the length of the string
		{
                  check=check/base;
                  stringsize ++;
		}
		length = stringsize; 
                ptr = (uint8_t*)malloc((stringsize+2)*sizeof(uint8_t)); // allocating memory to the pointer
		ptr = ptr+stringsize+sign;
                *(ptr)='\0'; //the last byte of the string is NULL	
		while(length>0)
	          {
			  if(data!=0)
			  {
				  ptr--;
			  }
		       if(data%base>=10)
		       {
		       *ptr=(data%base)+55;  //this moves the ASCII values of numbers between 10 and 15 into the pointer location
			data=data/base;
		       }	
		       else
		       {
		        *ptr=(data%base)+48; //this moves the ASCII values of numbers between 0 and 9 into the pointer location
			 data=data/base;
		       }
                    length--;
                   }
                 if (sign==1)
                {
		     ptr = ptr-1;
                     *ptr=45; //ASCII value of minus sign
                }
                return(stringsize+sign+1);
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
 uint8_t i=0,j=0,n=0;
 uint8_t sign=0;
 uint32_t b=1;
 int32_t number=0;
   if(*ptr==45)
   {
   ptr++;
   sign=1;
   digits--;
   }
   for(i=digits-1;i!=0;i--)
   {
     b=1;
     if(*ptr>=65)
      {
      n=*ptr-55;
      }
     else
      {
      n=*ptr-48;    
      } 
     for(j=i-1;j!=0;j--)
     {
     b=b*base;
     }
    number=(n*b)+number;
    digits--;
    ptr++;
   }
   if(sign==1)
   {
   number=-number;
   }
  return(number);
}

int8_t big_to_little32(uint32_t * data, uint32_t length)
{
int8_t i=length-1;
uint32_t t;
 if(data==NULL)
 {
  return 1;
 }
 if(data=='\0')
 {
  return 2;
 }
 else
 {
  while(i>0)
  {
   t=*(data+i);
   *(data+i)=*data;
   *data =t;
   data++;
   i=i-2;
  }
 }
}

int8_t little_to_big32(uint32_t * data, uint32_t length)
{
int8_t i=length-1;
uint32_t t;
 if(data==NULL)
 {
  return 1;
 }
 if(data=='\0')
 {
  return 2;
 }
 else
 {
  while(i>0)
  {
   t=*(data+i);
   *(data+i)=*data;
   *data =t;
   data++;
   i=i-2;
  }
 }
}
