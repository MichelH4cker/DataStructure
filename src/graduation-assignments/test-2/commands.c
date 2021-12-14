#include "commands.h"

void remoteController(struct Node **root_ref, int id){
    int total, height, searchedCEP;
    struct Node *searchedNode = NULL;
    switch (id){
        case 1:
            totalNodes(&(*root_ref));
            printf("Exibe na tela: %d\n", total);
            return;
        case 2:
            heightTree(&(*root_ref));
            printf("Exibe na tela: %d\n", height);
            return;
        case 3:
            scanf("%d", &searchedCEP);
            searchedNode = searchByCEP(&(*root_ref), searchedCEP);

            if (searchedNode == NULL){
                printf("Exibe na tela: FAIL\n");
            } else {
                printf("Exibe na tela: %d %d %s %s\n", searchedNode->data.initialCEP, searchedNode->data.endCEP, searchedNode->data.city, searchedNode->data.state);
            }
            return;
        case 4:
            preOrder(&(*root_ref));
            return;
        case 5:
            order(&(*root_ref));
            return;
        default:
            printf("Inválido!\n");
            return;
    }
}
