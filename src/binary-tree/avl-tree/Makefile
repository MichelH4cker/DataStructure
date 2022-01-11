all : avltree

run : 
	./avltree

main.o : main.c
	gcc -o main.o -c main.c

tree-tad.o : tree-tad.c
	gcc -o tree-tad.o -c tree-tad.c

avltree : main.o tree-tad.o 
	gcc -o avltree main.o tree-tad.o 

clean :
	rm -rf *.o
	clear

zip : zip binary-tree *.c *h Makefile