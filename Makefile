block_TARGET = ./block
noBlock_TARGET = ./noBlock
 
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic -O2 -g

CLEAN = rm *.o
 
.PHONY: default all clean
 
default: $(block_TARGET) $(noBlock_TARGET)
all: default
 
block_OBJECTS = $(patsubst %.c, %.o, block.c matriz.c)
block_HEADERS = $(matriz.h)
 
noBlock_OBJECTS = $(patsubst %.c, %.o, noBlock.c matriz.c)
noBlock_HEADERS = $(matriz.h)
 
%.o: %.c $(block_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
   
%.o: %.c $(noBlock_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
     
.PRECIOUS: $(block_TARGET) $(block_OBJECTS) $(noBlock_TARGET) $(noBlock_OBJECTS)
 
$(block_TARGET): $(block_OBJECTS)
	$(CC) $(block_OBJECTS) -o $@
     
$(noBlock_TARGET): $(noBlock_OBJECTS)
	$(CC) $(noBlock_OBJECTS) -o $@
     
clean:
	$(CLEAN)
