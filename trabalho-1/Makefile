all : trabalho

run : 
	./trabalho

main.o : main.c
	gcc -o main.o -c main.c

createDestroyList.o : createDestroyList.c
	gcc -o createDestroyList.o -c createDestroyList.c

trabalho : main.o createDestroyList.o 
	gcc -o trabalho main.o createDestroyList.o

clean :
	rm -rf *.exe *.o
	clear