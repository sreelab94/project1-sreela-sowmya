#
BASENAME = project1
#CPU = cortex-m0plus
#ARCH = thumb
#SPECS = nosys.specs

# define the C compiler to use
CC = gcc
TARGET = $(BASENAME).elf
#PLATFORM = HOST
#ifeq ($(PLATFORM),HOST) \
#	CC = gcc
#else ifeq ($(PLATFORM),KL25Z)
#	CC = arm-none-eabi-gcc 
#else ifeq ($(PLATFORM),BBB)
#	CC = ​arm-linux-gnueabi-gcc
#endif 


# Compile-time flags C programming files
# #-mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -Wall -Werror -g -O0 -std=c99 
CFLAGS =  -g \
          -Werror \
          -std=c99 \
          -D VERBOSE \
          -D PROJECT1
# define any directories containing header files other than /usr/include
#
INCLUDES = -I../include/common/ -I../include/kl25z/ -I../include/CMSIS/ -I../platform

LDFLAGS = -Wl,-Map=$(BASENAME).map
# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname 
#   option, something like (this will link in libmylib.so and libm.so:
#LIBS = -lmylib -lm
#LIBS = 

# define the C source files
# SRCS = memory.c project1.c system_MKL25Z4.c debug.c
SRCS = memory.c conversion.c project1.c system_MKL25Z4.c main.c debug.c

# define the C object files 
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#
OBJS = $(SRCS:.c=.o)

DEPS = $(SRCS:.c=.d)

.PHONY: depend clean

all:    $(TARGET)
	@echo  Simple compiler named mycc has been compiled

#DEPS is added now
$(TARGET): $(OBJS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(DEPS) $(OBJS) $(LDFLAGS) $(LFLAGS) $(LIBS)

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

#for now .d is added
clean:
	$(RM) *.o *.d *~ $(TARGET)          

depend: $(SRCS)
	makedepend $(INCLUDES) $^

build $(PLATFORM):
	@echo  Build tested successfully