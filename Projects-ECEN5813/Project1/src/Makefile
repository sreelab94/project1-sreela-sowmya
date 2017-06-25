#

# Make file for project 1
# Use : make [targets] [overrides]

# Targets:
# <FILE>.O - Builds <FILE>.O object file
# build - Builds and links all source files
# all - Same as build 
# clean - Removes all generated files

# Overrides:
# CPU - ARM Cortex Architecure (cortex-m0plus, cortex-m4)
# ARCH - ARM Architecture (arm, thumb)
# SPECS - Specs file to give to the linker (nosys.specs, nano.specs)

include sources.mk
BASENAME = project1
#CPU = cortex-m0plus
#ARCH = thumb
#SPECS = nosys.specs

# define the C compiler to use
CC = gcc
TARGET = $(BASENAME).elf
PLATFORM = HOST
ifeq ($(PLATFORM),HOST) 
	CC = gcc
else ifeq ($(PLATFORM),KL25Z)
	CC = arm-none-eabi-gcc 
	@echo  KL25Z compiler set
  #  CPU = cortex-m0plus
else ifeq ($(PLATFORM),BBB)
	CC = ​arm-linux-gnueabi-gcc
	@echo  BBB compiler set
endif 


# Compile-time flags C programming files
# #-mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -Wall -Werror -g -O0 -std=c99 
#-g compiles with debug information, O0 - do not optimize the code, use C99 compiler, Wall - Give verbose compiler warnings

CFLAGS =  -g -Wall \
          -O0 \
          -std=c99 \
          -D VERBOSE \
          -D PROJECT1 \
          -Werror \
# define any directories containing header files other than /usr/include
#
INCLUDES = -I../include/common/ -I../include/kl25z/ -I../include/CMSIS/ -I../platform

LDFLAGS = -Wl,-Map=$(BASENAME).map 

#LIBS = -lmylib -lm
#LIBS = 

#SRCS = memory.c conversion.c project1.c system_MKL25Z4.c main.c debug.c

#DEPS = $(SRCS:.c=.d)

# define the C object files 
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#
#DEPS = $(SRCS:.c=.d)

OBJS = $(SRCS:.c=.o)

all:    $(TARGET)
	@echo  Build successfully

$(TARGET): $(OBJS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS) $(LDFLAGS) $(LFLAGS) 

#.c.o:
#	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

%.i:
	$(CC) $(CFLAGS) $(INCLUDES) -E $(SRCS) $(LFLAGS) 

%.o:%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $^ 

%.asm: 
	$(CC) $(CFLAGS) $(INCLUDES) -S $(SRCS) $(LFLAGS) 

.PHONY: compile-all
compile-all: 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCS)

.PHONY: clean
clean:
	$(RM) *.o *.map *.asm *.i *.out *.s *.d *~ $(TARGET)          

#.PHONY: build
#build: $(OBJS) 	
	#$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS) $(LDFLAGS) $(LFLAGS) 

#build-all: $(OBJS) 	
#	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS) $(LDFLAGS) $(LFLAGS 

