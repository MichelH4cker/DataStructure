all : trabalho

run : 
	./trabalho

main.o : main.c 
	gcc -o main.o -c main.c

insertion.o : insertion.c
	gcc -o insertion.o -c insertion.c 

commands.o : commands.c
	gcc -o commands.o -c commands.c

file.o : file.c
	gcc -o file.o -c file.c

trabalho : main.o insertion.o commands.o file.o
	gcc -o trabalho main.o insertion.o commands.o file.o

clean : 
	rm -rf *.o
	clear

zip : 
	zip wally.zip *.c *.h Makefile