CC = gcc
CFLAGS = -Wall -std=c99 -D_GNU_SOURCE

all: match

match: match.o
	$(CC) $(CFLAGS) match.o -o match

clean:
	rm match match.o
