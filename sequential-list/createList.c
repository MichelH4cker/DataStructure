#include "createDestroyList.h"

List* createList(){
    List *list;
    list = malloc(sizeof(List));

    printf("vai entrar no if \n");
    if (list != NULL){
        printf("entrou no if! \n");
        list->occupiedPositions = 0;
        printf("As posições ocupadas são: %d \n", list->occupiedPositions);
        return list;
    }
    printf("não entrou no if\n");
}

void freeList(List *list){
    free(list);

}