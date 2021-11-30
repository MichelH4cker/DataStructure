all : trabalho

run : 
	./trabalho

main.o : main.c 
	gcc -o main.o -c main.c

insertion.o : insertion.c
	gcc -o insertion.o -c insertion.c 

commands.o : commands.c
	gcc -o commands.o -c commands.c

trabalho : main.o insertion.o commands.o
	gcc -o trabalho main.o insertion.o commands.o

clean : 
	rm -rf *.o
	clear

zip : 
	zip trabalho-2.zip *.c *.h Makefile