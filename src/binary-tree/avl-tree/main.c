#include "main.h"

int main(){
    struct Node *root;
    int res,i;
    //int N = 10, dados[10] = {50,25,10,5,7,3,30,20,8,15};
    //int N = 11, dados[11] = {50,25,10,5,5,7,3,30,20,8,15};
    int N = 10, dados[10] = {1,2,3,10,4,5,9,7,8,6};

    root = createNewNode();

    for(i = 0; i < N; i++){
        //printf("========================\n");
        //printf("Inserindo: %d\n",dados[i]);
        res = insert(&root,dados[i]);
        //printf("\n\nres = %d\n",res);
        //preOrder(root);
        //printf("\n\n");
    }

    printf("\nroot tree:\n");
    order(&root);
    printf("\n\n");

//    int NR = 4, dadosR[4] = {7,51,3,5};
//    for(i=0;i<NR;i++){
//        printf("\nRemovendo: %d\n",dadosR[i]);
//        res = removeNode Node **(root,dadosR[i]);
//        printf("\n\nres = %d\n",res);
//        preOrder(root);
//        //printf("\n\n");
//    }
//
//    printf("\nroot tree:\n");
//    preOrder(root);
//    printf("\n\n");

    removeNode(&root,6);
    printf("\nroot tree:\n");
    order(&root);
    printf("\n\n");

    removeNode(&root,7);
    printf("\nroot tree:\n");
    order(&root);
    printf("\n\n");

    removeNode(&root,4);
    printf("\nroot tree:\n");
    order(&root);
    printf("\n\n");

    freeTree(root);

    return 0;
}
