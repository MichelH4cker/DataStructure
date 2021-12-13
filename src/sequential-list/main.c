#include<stdio.h>

#include "main.h"
#include "createDestroyList.h"
#include "insertion.h"

#define START 1
#define END 2

int selectTheTypeInsertion(int typeInsertion){
    printf("Digite o número correspondente à maneira pela qual você deseja inserir o dado \n");
    scanf("%d", &typeInsertion);
    printf("\n");

    return typeInsertion;
}

int main (){
    List *list;
    list = createList();

    struct Data content0 = {0, "oi"};
    struct Data content1 = {1, "fala"};
    struct Data content2 = {77, "ULTIMA"}; 

    //system("clear");

    printf("\n====================================================\n");
    printf("\n");
    printf("MODOS DE INSERÇÃO \n");

    printf("1) inserir dado no início da lista. \n");
    printf("2) inserir dado no final da lista. \n");
    printf("3) inserir dado na posição que eu informar. \n");

    printf("\n====================================================\n");
    printf("\n");

    int typeInsertion;
    for (int i = 0; i < 2; i++){
        typeInsertion = selectTheTypeInsertion(typeInsertion);
        if (typeInsertion == START){
            startInsertion(list, content0);
            startInsertion(list, content1);

        } else if (typeInsertion == END){
            endInsertion(list, content2);

        }    
        
    }
    
    printf("\n");
    printf("os dados inseridos foram: \n"); 

    int lastData = list->occupiedPositions - 1;

    printf("%d \n", list->list[0].dataInteger);
    printf("%s \n", list->list[0].dataString);
    
    printf("%d \n", list->list[1].dataInteger);
    printf("%s \n", list->list[1].dataString);
    
    printf("%d \n", list->list[lastData].dataInteger);
    printf("%d \n", list->list[lastData].dataString);

    freeList(list);
    return 0;
}
