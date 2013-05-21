###########################################################################
# Some rules for building asm files:

SUFFIXES = .asm

.asm.o:
	nasm -f bin $< -o $@
###########################################################################

bin_PROGRAMS = 	example1

example1_SOURCES = example1.c

AM_CFLAGS = -Wall -Wextra -Werror -I../src/include
LDADD = -L../src/.libs -lunstable
