all : test-2

run : 
	./test-2

main.o : main.c
	gcc -o main.o -c main.c

tree-tad.o : tree-tad.c
	gcc -o tree-tad.o -c tree-tad.c

test-2 : main.o tree-tad.o 
	gcc -o test-2 main.o tree-tad.o 

clean :
	rm -rf *.o
	clear

zip : zip test-2 *.c *h Makefile