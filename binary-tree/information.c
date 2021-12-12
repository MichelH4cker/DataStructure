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

int treeMinimum(struct Node **root_ref){
    if (root_ref == NULL)  return -1;
    if (*root_ref == NULL) return -1;

    struct Node *currentNode = *root_ref;
    
    int smallestInt;
    while (currentNode->left != NULL){
        currentNode = currentNode->left;
    }
    smallestInt = currentNode->data.intData;
    
    return smallestInt;
}

int treeMaximum(struct Node **root_ref){
    if (root_ref == NULL)  return -1;
    if (*root_ref == NULL) return -1;

    struct Node *currentNode = *root_ref;
    
    int biggerInt;
    while (currentNode->right != NULL){
        currentNode = currentNode->right;
    }
    biggerInt = currentNode->data.intData;
    
    return biggerInt;

}

int treeHeight(struct Node **root_ref){
    if (root_ref == NULL)  return 0;
    if (*root_ref == NULL) return 0;

    int leftHeight = treeHeight(&((*root_ref))->left);
    int rightHeight = treeHeight(&((*root_ref))->right);

    if (leftHeight > rightHeight){
        return (leftHeight + 1);
    } else {
        return(rightHeight + 1);
    }
        
}

int totalNodes(struct Node **root){
    if (root == NULL)  return 0;
    if (*root == NULL) return 0;

    int leftHeight = totalNodes(&((*root)->left));
    int rightHeight = totalNodes(&((*root)->right));

    return(leftHeight + rightHeight + 1);
}
