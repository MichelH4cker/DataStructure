#include "information.h"

void preOrder(struct Node **root_ref){
    if(root_ref == NULL)
        return;
    if(*root_ref != NULL){
        printf("%d %f %s\n", (*root_ref)->data.intData, (*root_ref)->data.floatData, (*root_ref)->data.charData);
        preOrder(&((*root_ref)->left));
        preOrder(&((*root_ref)->right));
    }
}

void order(struct Node **root_ref){
    if(root_ref == NULL)
        return;
    if(*root_ref != NULL){
        order(&((*root_ref)->left));
        printf("%d %f %s\n", (*root_ref)->data.intData, (*root_ref)->data.floatData, (*root_ref)->data.charData);
        order(&((*root_ref)->right));
    }
}

void postOrder(struct Node **root_ref){
    if(root_ref == NULL)
        return;
    if(*root_ref != NULL){
        postOrder(&((*root_ref)->left));
        postOrder(&((*root_ref)->right));
        printf("%d %f %s\n", (*root_ref)->data.intData, (*root_ref)->data.floatData, (*root_ref)->data.charData);
    }
}

int totalNodes(struct Node *node){
    int total = 0;

    if(node == NULL) return 0;
    
    total += totalNodes(node->left);
    total += totalNodes(node->right);

    return total;
}
