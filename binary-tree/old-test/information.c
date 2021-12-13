#include "information.h"

void preOrder(struct Node **root_ref){
    if(root_ref == NULL)
        return;
    if(*root_ref != NULL){
        printf("%d %d \n", (*root_ref)->data.dataArray[CPF], (*root_ref)->data.dataArray[NREG]);
        
        preOrder(&((*root_ref)->left));
        preOrder(&((*root_ref)->right));
    }
}

void order(struct Node **root_ref){
    if(root_ref == NULL)
        return;
    if(*root_ref != NULL){
        order(&((*root_ref)->left));
        printf("Dados: %d (CPF) - %d (NREG)\n", (*root_ref)->data.dataArray[CPF], (*root_ref)->data.dataArray[NREG]);
        order(&((*root_ref)->right));
    }
}

void postOrder(struct Node **root_ref){
    if(root_ref == NULL)
        return;
    if(*root_ref != NULL){
        postOrder(&((*root_ref)->left));
        postOrder(&((*root_ref)->right));
        printf("%d %d \n", (*root_ref)->data.dataArray[CPF], (*root_ref)->data.dataArray[NREG]);
    }
}

int searchIntData(struct Node **root_ref, int intData, int flag){
    if (root_ref == NULL) return -1;

    struct Node *currentNode = *root_ref;
    while (currentNode != NULL){
        if (intData == currentNode->data.dataArray[flag]){
            return 1;
        } 

        if (intData > currentNode->data.dataArray[flag]){
            currentNode = currentNode->right;
        } else {
            currentNode = currentNode->left;
        }
    }
    
    return 0;
}