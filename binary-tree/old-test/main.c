#include "main.h"

void freeTree(struct Node* node){
    if(node == NULL) return;

    freeTree(node->left);
    freeTree(node->right);
    
    free(node);
    node = NULL;
}

int main (){
    struct Node *cpfTree  = NULL;
    struct Node *nRegTree = NULL;

    readAndStorageFile(&cpfTree, &nRegTree);

    //preOrder(&cpfTree);
    printf("Dados CPF:\n");
    order(&cpfTree);
    printf("===============================\n");
    printf("Dados NREG:\n");
    order(&nRegTree);

    freeTree(cpfTree);
    freeTree(nRegTree);

    return 0;
}