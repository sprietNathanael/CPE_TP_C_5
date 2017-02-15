CC=gcc
CFLAGS=-W -Wall -g -Wextra
EXEC=chainedListSort


all: $(EXEC)

chainedListSort: main.o char_list.o
	$(CC) -o chainedListSort main.o char_list.o

main.o: main.c char_list.h
	$(CC) -o main.o -c main.c $(CFLAGS)

char_list.o: char_list.c
	$(CC) -o char_list.o -c char_list.c $(CFLAGS)


mrproper: clean
	rm -rf $(EXEC)

clean:
	rm -rf *.o *.h.gch
