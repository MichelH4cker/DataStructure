#include "information.h"

int emptyList(struct Node **head_ref){
    return *head_ref == NULL ? 1 : 0;    
} 

void showAllNodes(struct Node **head_ref){
    if (emptyList(head_ref)) return;
    
    struct Node currentNode = **head_ref;
    
    printf("%d %s %f \n", currentNode.data.dataInteger, currentNode.data.dataString, currentNode.data.dataFloat);

}