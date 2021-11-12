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


LISTA_SEQUENCIAL_OBJS = main-lista-sequencial.o

LIB_LISTA_SEQUENCIAL_OBJS = ListaSequencial.o

LIB_LISTA_SEQUENCIAL = lib-lista-sequencial.a


LISTA_DIN_ENCAD_OBJS = main-lista-din-encad.o

LIB_LISTA_DIN_ENCAD_OBJS = ListaDinEncad.o

LIB_LISTA_DIN_ENCAD = lib-listaDinEncad.a



TARGETS =	lista-sequencial\
			lista-din-encad


LIBS = $(LIB_LISTA_SEQUENCIAL) $(LIB_LISTA_DIN_ENCAD)

ALL = $(TARGETS) $(LIBS)


.c.o:
	$(CC) $(CFLAGS) -c $<

lib-lista-sequencial.a: $(LIB_LISTA_SEQUENCIAL_OBJS)
	$(AR) -r $@ $^

lib-listaDinEncad.a: $(LIB_LISTA_DIN_ENCAD_OBJS)
	$(AR) -r $@ $^

lista-sequencial: $(LIB_LISTA_SEQUENCIAL) $(LISTA_SEQUENCIAL_OBJS)
	$(LD) $(LDFLAGS) -o $@ $^ -L. -l-lista-sequencial

lista-din-encad:$(LIB_LISTA_DIN_ENCAD) $(LISTA_DIN_ENCAD_OBJS)
	$(LD) $(LDFLAGS) -o $@ $^ -L. -l-listaDinEncad


.PHONY: all clean

all: $(TARGETS)

clean:
	$(RM) *.o $(ALL)