CC      := gcc

CFLAGS  := -W -Wall  -Wextra -Werror -I/usr/local/include/

BIN     := unstable

SRC := src/main.c src/unstable.c
OBJ := $(patsubst %.c,%.o,$(SRC))

%.o: %.c
		$(CC) $(CFLAGS) -o $@ -c $<

all: $(OBJ)
		$(CC) $(CFLAGS) -o $(BIN) $(OBJ)

clean:
		$(RM) $(BIN) $(OBJ) *.o $(LIB)
