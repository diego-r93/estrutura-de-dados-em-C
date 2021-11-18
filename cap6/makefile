#!/usr/bin/make -f

CC = gcc
AR = ar

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


FILA_ESTATICA_OBJS = main-fila-estatica.o

LIB_FILA_ESTATICA_OBJS = FilaEstatica.o

LIB_FILA_ESTATICA = lib-fila-estatica.a


FILA_DIN_OBJS = main-fila-din.o

LIB_FILA_DIN_OBJS = FilaDin.o

LIB_FILA_DIN = lib-fila-din.a



TARGETS =	fila-estatica\
			fila-din


LIBS =	$(LIB_FILA_ESTATICA)\
		$(LIB_FILA_DIN)

ALL = $(TARGETS) $(LIBS)


.c.o:
	$(CC) $(CFLAGS) -c $<

lib-fila-estatica.a: $(LIB_FILA_ESTATICA_OBJS)
	$(AR) -r $@ $^

fila-estatica: $(LIB_FILA_ESTATICA) $(FILA_ESTATICA_OBJS)
	$(LD) $(LDFLAGS) -o $@ $^ -L. -l-fila-estatica


lib-fila-din.a: $(LIB_FILA_DIN_OBJS)
	$(AR) -r $@ $^

fila-din: $(LIB_FILA_DIN) $(FILA_DIN_OBJS)
	$(LD) $(LDFLAGS) -o $@ $^ -L. -l-fila-din


.PHONY: all clean

all: $(TARGETS)

clean:
	$(RM) *.o $(ALL)