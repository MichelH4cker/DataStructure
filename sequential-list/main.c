#include<stdio.h>

#include "main.h"
#include "createDestroyList.h"
#include "insertion.h"

#define START 1
#define END 2

int main (){
    List *list;
    list = createList();

    
    int typeInsertion;    
    printf("\n====================================================\n");
    printf("\n");
    printf("Digite o número correspondente à maneira pela qual você deseja inserir os dados \n");

    printf("1) inserir dado no início da lista. \n");
    printf("2) inserir dado no final da lista. \n");
    printf("3) inserir dado na posição que eu informar. \n");

    printf("\n====================================================\n");
    printf("\n");

    scanf("%d", &typeInsertion);
    printf("\n");

    struct Data content0 = {0, "oi"};
    struct Data content1 = {1, "fala"}; 

    if (typeInsertion == START){
        startInsertion(list, content0);
        startInsertion(list, content1);

    } 
    
    printf("\n");
    printf("os dados inseridos foram: \n"); 

    printf("%d \n", list->list[0].dataInteger);
    printf("%s \n", list->list[0].dataString);
    
    printf("%d \n", list->list[1].dataInteger);
    printf("%s \n", list->list[1].dataString);
    
    freeList(list);
    return 0;
}
/* FUNÇÕES PRINCIPAIS DE UMA TAD:
-
-
-
-
*/
    