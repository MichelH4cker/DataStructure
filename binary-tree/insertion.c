#include "insertion.h"

struct Node* createNewNode(struct Data newData){
    struct Node *newNode;
    newNode = malloc(sizeof(struct Node*));

    if (newNode == NULL)
        return NULL;
    
    newNode->data = newData;
    newNode->right = NULL;
    newNode->left = NULL;   

    return (newNode);
}