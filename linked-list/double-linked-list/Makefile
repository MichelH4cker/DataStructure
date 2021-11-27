all : ll

run : 
	./ll

main.o : main.c
	gcc -o main.o -c main.c

information.o : information.c
	gcc -o information.o -c information.c

insertion.o : insertion.c
	gcc -o insertion.o -c insertion.c

ll : main.o information.o insertion.o
	gcc -o ll main.o information.o insertion.o

clean :
	rm -rf *.o
	clear

zip : zip double-linked-list *.c *h Makefile