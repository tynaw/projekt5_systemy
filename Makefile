CC=gcc

all: server client

server: src/headers.h src/pierwszy.c
	$(CC) -o server src/pierwszy.c

client: src/headers.h src/drugi.c
	$(CC) -o client src/drugi.c

clean:
	$(RM) server client
