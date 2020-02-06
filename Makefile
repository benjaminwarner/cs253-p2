CC = gcc
CFLAGS = -Wall -std=c99 -D_GNU_SOURCE

all: match

match: match.c
	$(CC) $(CFLAGS) match.c -o match

clean:
	rm match
