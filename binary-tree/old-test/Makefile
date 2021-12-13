all : old-test

run : 
	./old-test

main.o : main.c
	gcc -o main.o -c main.c

information.o : information.c
	gcc -o information.o -c information.c

insertion.o : insertion.c
	gcc -o insertion.o -c insertion.c

file.o : file.c
	gcc -o file.o -c file.c

old-test : main.o information.o insertion.o  file.o
	gcc -o old-test main.o information.o insertion.o file.o

clean :
	rm -rf *.o
	clear

zip : zip old-test *.c *h Makefile