CC=gcc
CFLAGS = -Wall -Werror -pedantic -ggdb
test: test.c
	$(CC) $(CFLAGS) test.c
