#include "insertion.h"

struct Node* createNewNode(struct Data newData){
    struct Node *newNode;
    newNode = malloc(sizeof(struct Node));

    if (newNode == NULL)
        return NULL;
    
    newNode->data = newData;
    newNode->right = NULL;
    newNode->left = NULL;   

    return (newNode);
}

void insert(struct Node **root_ref, struct Data newData, int flag){
    if (root_ref == NULL) return;

    struct Node *newNode = createNewNode(newData);

    if((*root_ref) == NULL){
        (*root_ref) = newNode;
    } else {
        struct Node *currentNode = (*root_ref);
        struct Node *previousNode = NULL;

        while(currentNode != NULL){
            previousNode = currentNode;
            if(newData.dataArray[flag] == currentNode->data.dataArray[flag]){
                free(newNode);
                return; //elemento já existe
            }

            if(newData.dataArray[flag] > currentNode->data.dataArray[flag])
                currentNode = currentNode->right;
            else
                currentNode = currentNode->left;
        }
        
        if(newData.dataArray[flag] > previousNode->data.dataArray[flag])
            previousNode->right = newNode;
        else
            previousNode->left = newNode;
    }
}
