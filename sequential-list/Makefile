all : les

run : 
	./les

main.o : main.c
	gcc -o main.o -c main.c

createDestroyList.o : createDestroyList.c
	gcc -o createDestroyList.o -c createDestroyList.c

insertion.o : insertion.c
	gcc -o insertion.o -c insertion.c

les : main.o createDestroyList.o insertion.o
	gcc -o les main.o createDestroyList.o insertion.o

clean :
	rm -rf *.exe *.o