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
    order(&cpfTree);
    printf("==================\n");
    order(&nRegTree);

    freeTree(cpfTree);
    freeTree(nRegTree);

    return 0;
}