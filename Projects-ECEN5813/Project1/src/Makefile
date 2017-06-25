# _*_ MakeFile _*_

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

# define the C compiler to use

TARGET = $(BASENAME).elf
INCLUDES = -I../include/common/ -I../include/kl25z/ -I../include/CMSIS/ 
ifeq ($(PLATFORM),HOST) 
	CC = gcc
else ifeq ($(PLATFORM),KL25Z)
	CC = arm-none-eabi-gcc 
INCLUDES = -I../include/common/ -I../include/kl25z/ -I../include/CMSIS/ -I../platform
	CFLAGS:=-mcpu=cortex-m0plus
	CFLAGS +=-mthumb -march=armv6-m
	CFLAGS+=-mfpu=fpv4-sp-d16 
	CFLAGS+=--specs=nosys.specs 
	#LDFLAGS = Xlinker
  # -mfloat-abi=​ ???
else ifeq ($(PLATFORM),BBB)
	CC = ​arm-linux-gnueabihf-gcc
endif 

# Compile-time flags C programming files
#-g compiles with debug information, O0 - do not optimize the code, use C99 compiler, Wall - Give verbose compiler warnings

#CFLAGS =  -g -Wall \
#          -O0 \
 #         -std=c99 \
#          -D VERBOSE \
 #         -D PROJECT1 \
  #        -Werror  

# define any directories containing header files other than /usr/include

LDFLAGS = -Wl,-Map=$(BASENAME).map 

#DEPS = $(SRCS:.c=.d)
OBJS = $(SRCS:.c=.o)

.PHONY: build
build: $(TARGET) 

$(TARGET): $(OBJS) DEPENDS.dep
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS) $(LDFLAGS) $(LFLAGS)

DEPENDS.dep:
	$(CC) $(CFLAGS) $(INCLUDES) -M $(SRCS) $(DEPS) -o $@  $^  > DEPENDS
	objdump -a $(OBJS) 
	size -d $(OBJS)
	@echo  Build with .d files, .o files and .elf executable successfull

.PHONY: compile-all
compile-all: 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCS)

.PHONY: clean
clean:
	$(RM) *.o *.map *.asm *.i *.out *.s *.d *~ $(TARGET) 

%.i: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -E -o $@ $^  

%.o:%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $^ 

%.asm: 
	$(CC) $(CFLAGS) $(INCLUDES) -S $(SRCS) $(LFLAGS) 

         


