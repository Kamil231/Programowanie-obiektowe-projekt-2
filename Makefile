CC=g++
CFLAGS=-c -Wall

output: main.o list1.o
	$(CC) main.o list1.o -o output

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

person.o: list1.cpp list1.h
	$(CC) $(CFLAGS) list1.cpp

clean: 
	rm *.o output
