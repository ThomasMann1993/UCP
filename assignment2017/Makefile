
CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
OBJ1 = main.o fileReader.o linkedList.o array.o actionTime.o check.o
OBJ2 = main.o fileReader.o linkedList.o array.o actionTime.o
EXEC = spellcheck

EXEC : $(OBJ2)
	$(CC) $(OBJ2) -o $(EXEC) 

main.o : main.c linkedList.h header.h chech.h
	$(CC) -c main.c $(CFLAGS)

fileReader.o : fileReader.c header.h 
	$(CC) -c fileReader.c $(CFLAGS) 

linkedList.o : linkedList.c linkedList.h
	$(CC) -c linkedList.c $(CFLAGS)

array.o : array.c linkedList.h
	$(CC) -c array.c $(CFLAGS)

actionTime.o : actionTime.c header.h chech.h
	$(CC) -c actionTime.c $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJ2) 

help:
	@echo 
	@echo output $(EXEC)


