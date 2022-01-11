#include "commands.h"

void remoteController(struct Node **root_ref, int id){
    int total, height, searchedCEP;
    struct Node *searchedNode = NULL;
    switch (id){
        case 1:
            total = totalNodes(&(*root_ref));
            printf("%d\n", total);
            return;
        case 2:
            height = heightTree(&(*root_ref));
            printf("%d\n", height);
            return;
        case 3:
            scanf("%d", &searchedCEP);
            searchedNode = searchByCEP(&(*root_ref), searchedCEP);

            if (searchedNode == NULL){
                printf("FAIL\n");
            } else {
                printf("%d %d %s %s\n", searchedNode->data.initialCEP, searchedNode->data.endCEP, searchedNode->data.city, searchedNode->data.state);
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
