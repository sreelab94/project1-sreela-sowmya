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
  #  CPU = cortex-m0plus
else ifeq ($(PLATFORM),BBB)
	CC = ​arm-linux-gnueabi-gcc
endif 


# Compile-time flags C programming files
# #-mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -Wall -Werror -g -O0 -std=c99 
CFLAGS =  -g \
          -Werror \
          -std=c99 \
          -D VERBOSE \
          -D PROJECT1 \

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
OBJS = $(SRCS:.c=.o)

.PHONY: depend clean

all:    $(TARGET)
	@echo  Simple compiler named mycc has been compiled

#DEPS is added now
#$(TARGET): $(OBJS) 
#	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS) $(LDFLAGS) $(LFLAGS) $(LIBS)

$(TARGET): $(OBJS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS) $(LDFLAGS) $(LFLAGS) 

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

#for now .d is added
clean:
	$(RM) *.o *~ $(TARGET)          

depend: $(SRCS)
	makedepend $(INCLUDES) $^

build $(PLATFORM):
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS) $(LDFLAGS) $(LFLAGS) $(LIBS)