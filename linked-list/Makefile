all : ll

run : 
	./ll

main.o : main.c
	gcc -o main.o -c main.c

createDestroyList.o : createDestroyList.c
	gcc -o createDestroyList.o -c createDestroyList.c

insertion.o : insertion.c
	gcc -o insertion.o -c insertion.c

information.o : information.c
	gcc -o information.o -c information.c

removal.o : removal.c
	gcc -o removal.o -c removal.c 

ll : main.o createDestroyList.o insertion.o information.o removal.o
	gcc -o ll main.o createDestroyList.o insertion.o information.o removal.o

clean :
	rm -rf *.exe *.o
	clear

zip :
	zip linked-list.zip *.c *.h Makefile