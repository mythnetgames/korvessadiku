# Simple, forgiving Makefile for vintage Diku source
# Builds all .c files under the directory tree into one 'dikumud' binary.

CC = gcc
# Use gnu89 to be tolerant of K&R-style code & implicit declarations common in old code
CFLAGS = -O2 -std=gnu89 -D_GNU_SOURCE -I. -fno-strict-aliasing -Wall -Wno-unused-function -Wno-unused-variable -Wno-pointer-sign
LDFLAGS = 
TARGET = dikumud

# find all .c files (ignore .git)
SOURCES = $(shell find . -name '*.c' -not -path './.git/*' | sort)
# corresponding object files
OBJS = $(patsubst %.c,%.o,$(SOURCES))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)

# generic compile rule
%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-find . -name '*.o' -delete
	-rm -f $(TARGET)

.PHONY: all clean
