#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#include <stdio.h>

#define KL25Z 	1
#define BBB 	2
#define HOST 	3

#if PLATFORM == KL25Z
  #define printf(a) (void)0
#else
  #define printf(a) printf(a)
#endif

#endif /*__PLATFORM_H__*/