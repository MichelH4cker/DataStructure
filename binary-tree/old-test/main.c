#include "main.h"

void freeTree(struct Node* node){
    if(node == NULL) return;

    freeTree(node->left);
    freeTree(node->right);
    
    free(node);
    node = NULL;
}

int main (){
    struct Node *root = NULL;

    struct Data newData1;
    newData1.intData = 0;
    newData1.floatData = 0.0;
    strcpy(newData1.charData, "alguma coisa");

    struct Data newData2;
    newData2.intData = 1;
    newData2.floatData = 2.0;
    strcpy(newData2.charData, "outra coisa");

    struct Data newData3;
    newData3.intData = 2;
    newData3.floatData = 3.0;
    strcpy(newData3.charData, "outra coisa");

    struct Data newData4;
    newData4.intData = -1;
    newData4.floatData = 3.0;
    strcpy(newData4.charData, "lado esquerdo");

    insert(&root, newData1);
    insert(&root, newData2);
    insert(&root, newData3);
    insert(&root, newData4);

    printf("preOrder: \n");
    preOrder(&root);
    printf("=====================\n");
    
    printf("Order: \n");
    order(&root);
    printf("=====================\n");

    printf("postOrder: \n");
    postOrder(&root);
    printf("=====================\n");

    printf("o total de nodos: %d \n", totalNodes(&root));

    printf("altura: %d \n", treeHeight(&root));
    
    printf("o menor int: %d\n", treeMinimum(&root));
    printf("o maior int: %d\n", treeMaximum(&root));

    freeTree(root);

    return 0;
}