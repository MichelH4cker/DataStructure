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

void insert(struct Node **root_ref, struct Data newData){
    if (root_ref == NULL) return;

    struct Node *newNode = createNewNode(newData);

    if((*root_ref) == NULL){
        (*root_ref) = newNode;
    } else {
        struct Node *currentNode = (*root_ref);
        struct Node *previousNode = NULL;

        while(currentNode != NULL){
            previousNode = currentNode;
            if(newData.intData == currentNode->data.intData){
                free(newNode);
                return; //elemento já existe
            }

            if(newData.intData > currentNode->data.intData)
                currentNode = currentNode->right;
            else
                currentNode = currentNode->left;
        }
        
        if(newData.intData > previousNode->data.intData)
            previousNode->right = newNode;
        else
            previousNode->left = newNode;
    }
}

struct Node* removeCurrent(struct Node* currentNode) {
    struct Node *node1, *node2;
    
    if(currentNode->left == NULL){
        node1 = currentNode->right;
        free(currentNode);
        return node1;
    }

    node1 = currentNode;
    node2 = currentNode->left;
    while(node2->right != NULL){
        node1 = node2;
        node2 = node2->right;
    }
    // no2 é o nó anterior a r na ordem e-r-d
    // no1 é o pai de no2
    if(node1 != currentNode){
        node1->right = node2->left;
        node2->left = currentNode->left;
    }

    node2->right = currentNode->right;
    free(currentNode);

    return node2;
}

void removeByInt(struct Node **root_ref, int intData){
    if(*root_ref == NULL) return;

    struct Node* previousNode = NULL;
    struct Node* currentNode = (*root_ref);

    while(currentNode != NULL){
        if(intData == currentNode->data.intData){
            if(currentNode == (*root_ref)){
                (*root_ref) = removeCurrent(currentNode);
            } else {
                if(previousNode->right == currentNode){
                    previousNode->right = removeCurrent(currentNode);
                } else {
                    previousNode->left = removeCurrent(currentNode);
                }
                    
            }
        }

        previousNode = currentNode;
        if (intData > currentNode->data.intData){
            currentNode = currentNode->right;
        } else {
            currentNode = currentNode->left;
        }
    }
}