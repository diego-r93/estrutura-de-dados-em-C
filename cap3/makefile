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

TARGETS =	array-ordering\
			struct-ordering\
			array-search\
			struct-search

ARRAY_ORDERING_OBJS =	array-ordering.o\
						buble-sort.o\
						selection-sort.o\
						insertion-sort.o\
						merge-sort.o\
						quick-sort.o\
						heap-sort.o

STRUCT_ORDERING_OBJS =	struct-ordering.o\
						struct-insertion-sort.o

ARRAY_SEARCH_OBJS =	array-search.o\
					search.o\
					buble-sort.o\
					selection-sort.o\
					insertion-sort.o\
					merge-sort.o\
					quick-sort.o\
					heap-sort.o

STRUCT_SEARCH_OBJS =	struct-search.o\
						search.o					

.c.o:
	$(CC) $(CFLAGS) -c $<

array-ordering: $(ARRAY_ORDERING_OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

struct-ordering: $(STRUCT_ORDERING_OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

array-search: $(ARRAY_SEARCH_OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

struct-search: $(STRUCT_SEARCH_OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

.PHONY: all clean

all: $(TARGETS)

clean:
	$(RM) *.o $(TARGETS)