all : trabalho

run : 
	./trabalho

main.o : main.c
	gcc -o main.o -c main.c

createDestroyList.o : createDestroyList.c
	gcc -o createDestroyList.o -c createDestroyList.c

insertion.o : insertion.c
	gcc -o insertion.o -c insertion.c

trabalho : main.o createDestroyList.o insertion.o 
	gcc -o trabalho main.o createDestroyList.o insertion.o

clean :
	rm -rf *.exe *.o
	clear

zip :
	zip trabalho-1.zip *.c *.h Makefile