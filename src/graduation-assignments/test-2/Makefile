all : test-2

run : 
	./test-2

main.o : main.c
	gcc -o main.o -c main.c

tree-tad.o : tree-tad.c
	gcc -o tree-tad.o -c tree-tad.c

file.o : file.c
	gcc -o file.o -c file.c

commands.o : commands.c
	gcc -o commands.o -c commands.c

test-2 : main.o tree-tad.o file.o commands.o
	gcc -o test-2 main.o tree-tad.o file.o commands.o

clean :
	rm -rf *.o
	clear

zip : 
	zip test-2 *.c *h Makefile