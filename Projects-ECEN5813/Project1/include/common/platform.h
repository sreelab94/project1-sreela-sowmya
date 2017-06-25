#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#include <stdio.h>

#define KL25z 	1
#define BBB 	2
#define HOST 	3

#if PLATFORM == KL25z
  #define Printf(a) (void)0
#else
  #define Printf(a) printf(a)
#endif

#endif /*__PLATFORM_H__*/