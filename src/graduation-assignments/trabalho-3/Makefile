all : L-GRoot

run : 
	./L-GRoot

main.o : main.c
	gcc -o main.o -c main.c

tree.o : tree.c 
	gcc -o tree.o -c tree.c

file.o : file.c
	gcc -o file.o -c file.c

L-GRoot : main.o tree.o file.o
	gcc -o L-GRoot main.o tree.o file.o 

clean :
	rm -rf *.o
	clear

zip : 
	zip L-GRoot *.c *h Makefile