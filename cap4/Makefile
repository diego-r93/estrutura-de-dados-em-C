#!/usr/bin/make -f

CC = gcc

RM = rm -f

ifeq ($(compiler), CLANG)
CC = clang
endif

LD = $(CC)

CFLAGS = -Wall -std=c99
LDFLAGS = -Wall

ifeq ($(dialect), ANSI)
CFLAGS = -Wall -ansi
endif

ifeq ($(dialect), C99)
CFLAGS = -Wall -std=c99
endif

ifeq ($(dialect), C11)
CFLAGS = -Wall -std=c11
endif

TARGETS = ponto

OBJS = main.o ponto.o

.c.o:
	$(CC) $(CFLAGS) -c $<

ponto: $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^ -lm

.PHONY: all clean

all: $(TARGETS)

clean:
	$(RM) *.o $(TARGETS)