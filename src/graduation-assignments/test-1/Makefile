all : prova

run : 
	./prova

main.o : main.c
	gcc -o main.o -c main.c

linked-list.o : linked-list.c
	gcc -o linked-list.o -c linked-list.c

prova : main.o linked-list.o  
	gcc -o prova main.o linked-list.o

clean :
	rm -rf *.exe *.o
	clear

zip :
	zip prova.zip *.c *.h Makefile