SRCS     = $(wildcard ./src/*.c ./*.c)
SRCSM    = $(wildcard ./*.c)
OBJS     = $(patsubst %.c,%.o, $(SRCS))
OBJSM    = $(patsubst %.c,%.o,$(SRCSM))
TARGETS  = $(SRCSM:%.c=%)
#MCU      =arm-none-eabi-
CC	 =$(MCU)gcc
all : $(TARGETS)

$(TARGETS): %: %.o  
	$(CC)  -Wall -I ./src  -o $@ $<  -L. -lFunc 
	
$(OBJS) : %.o: %.c  
	$(CC) -Wall -I ./src -c  -o $@ $<
lib :
	$(CC) -Wall -I ./src -c $(wildcard ./src/*.c) -o libFunc.o
	$(MCU)ar crv libFunc.a libFunc.o 	
clean :
	    @rm -rf $(TARGETS) $(OBJS) libFunc.*
