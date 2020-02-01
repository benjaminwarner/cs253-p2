CC = gcc
CFLAGS = -Wall -std=c99

all: match

match: match.c
	$(CC) $(CFLAGS) match.c -o match

clean:
	rm match
