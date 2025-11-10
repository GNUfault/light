SU      = sudo
CC      = gcc
SRC     = light.c
BIN     = light
DEST    = /usr/local/bin
MARCH   = native
MTUNE   = $(MARCH)
OPT     = fast
STD     = c99
FLAGS   = -Wall -Wextra -pedantic -pedantic-errors
LDFLAGS = -lncurses 
CFLAGS  = -march=$(MARCH) -mtune=$(MTUNE) -O$(OPT) -std=$(STD) $(FLAGS)

all: compile strip

compile:
	$(CC) $(SRC) -o $(BIN) $(CFLAGS) $(LDFLAGS)

strip:
	objcopy --strip-all $(BIN)

install:
	$(SU) mkdir -p $(DEST)
	$(SU) install -m 755 $(BIN) $(DEST)

clean:
	rm -f $(BIN)

remove:
	$(SU) rm -f $(DEST)/$(BIN)

.PHONY: all compile strip install clean remove
