#include "commands.h"

void showAllNodes(struct Node **head_ref){
    if (head_ref == NULL) return;
    
    struct Node *currentNode = *head_ref;
    
    while (currentNode != NULL){
        printf("%f %f %f %d %d %d %d \n", currentNode->data.coordinate.x, currentNode->data.coordinate.y, currentNode->data.coordinate.z, currentNode->data.rgb.red, currentNode->data.rgb.green, currentNode->data.rgb.blue, currentNode->data.ID);
        
        currentNode = currentNode->next;    
    }
}
void li(struct Node *head_ref){
    if (head_ref == NULL) return;
    
    showAllNodes(&head_ref);
    
}

void lf(struct Node *head_ref){
    if (head_ref == NULL) return;
    
    showAllNodes(&head_ref);
}