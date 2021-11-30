all : trabalho

run : 
	./trabalho

main.o : main.c 
	gcc -o main.o -c main.c

trabalho : main.o 
	gcc -o trabalho main.o

clean : 
	rm -rf *.o
	clear

zip : 
	zip trabalho-2.zip *.c *.h Makefile