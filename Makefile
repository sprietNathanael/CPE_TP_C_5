CC=gcc
CFLAGS=-W -Wall -g -Wextra
EXEC=chainedListSort


all: $(EXEC)

chainedListSort: main.o char_list.o sort_splitMerge.o
	$(CC) -o chainedListSort main.o char_list.o sort_splitMerge.o

main.o: main.c char_list.h sort_splitMerge.h
	$(CC) -o main.o -c main.c $(CFLAGS)

char_list.o: char_list.c
	$(CC) -o char_list.o -c char_list.c $(CFLAGS)

sort_splitMerge.o: sort_splitMerge.c
	$(CC) -o sort_splitMerge.o -c sort_splitMerge.c $(CFLAGS)


mrproper: clean
	rm -rf $(EXEC)

clean:
	rm -rf *.o *.h.gch
