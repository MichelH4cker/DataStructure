all : les

run : 
	./les

main.o : main.c
	gcc -o main.o -c main.c

createList.o : createList.c
	gcc -o createList.o -c createList.c

les : main.o createList.o 
	gcc -o les main.o createList.o 

clean :
	rm -rf *.exe *.o