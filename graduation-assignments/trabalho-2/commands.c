#include "commands.h"

void showAllNodes (struct Node **head_ref){
    if (head_ref == NULL) return;
    
    struct Node *currentNode = *head_ref;
    
    while (currentNode != NULL){

        printf("%f %f %f %d %d %d %d\n", currentNode->data.coordinate[X], currentNode->data.coordinate[Y], currentNode->data.coordinate[Z], currentNode->data.rgb.red, currentNode->data.rgb.green, currentNode->data.rgb.blue, currentNode->data.ID);
        
        currentNode = currentNode->next;    
    }
}

int readCommand (){
    char command[30];
    scanf("%s", command);
    if (strcmp(command, "ID") == 0){
        int id;
        scanf("%d", &id);
    }
    
    printf("O comando digitado foi %s \n", command);    
}

void lx (struct Node *head_ref){
    if (head_ref == NULL) return;
    
    showAllNodes(&head_ref);
}

void ly (struct Node *head_ref){
    if (head_ref == NULL) return;
    
    showAllNodes(&head_ref);
}

void lz (struct Node *head_ref){
    if (head_ref == NULL) return;
    
    showAllNodes(&head_ref);
}

void li (struct Node *head_ref){
    if (head_ref == NULL) return;
    
    showAllNodes(&head_ref);
}

void lf (struct Node *head_ref){
    if (head_ref == NULL) return;
    
    showAllNodes(&head_ref);
}

int addNodes (struct Node **head_ref){
    struct Node *currentNode = *head_ref;

    int accessedNodes = 0;

    while (currentNode != NULL){
        accessedNodes = accessedNodes + currentNode->timesAccessed;
        currentNode = currentNode->next;
    }

    return accessedNodes;
}

void tot (struct Node **headOrdered_ref, struct Node **headPush_ref, struct Node **headAppend_ref){
    int accessedNodesOrdered = 0;
    int accessedNodesPush = 0;
    int accessedNodesAppend = 0;

    accessedNodesOrdered = addNodes(headOrdered_ref);    
    accessedNodesPush = addNodes(headPush_ref);
    accessedNodesAppend = addNodes(headAppend_ref);    

    printf("LX:%d LI:%d LF:%d\n", accessedNodesOrdered, accessedNodesPush, accessedNodesAppend);
}

void pz(){

}

void pi(struct Node **head_ref){
    float smallerX = (*head_ref)->data.coordinate[X];
    float smallerY = (*head_ref)->data.coordinate[Y];
    float smallerZ = (*head_ref)->data.coordinate[Z];
    
    float currentX;
    float currentY;
    float currentZ;

    int accessNodes = 0;

    struct Node *currentNode = (*head_ref);
    struct Node *smallerNode = NULL;
    while (currentNode != NULL){
        currentX = currentNode->data.coordinate[X];    
        currentY = currentNode->data.coordinate[Y];    
        currentZ = currentNode->data.coordinate[Z];    
        
        if (currentZ < smallerZ){
            smallerZ = currentZ;
            smallerNode = currentNode;
        } else if (currentZ == smallerZ) {
            if (currentX < smallerX){
                smallerX = currentX;
                smallerNode = currentNode;
            } else if (currentX == currentX){
                if (currentY < smallerY){
                    smallerY = currentY;
                    smallerNode = currentNode;
                }
            }
        }
        currentNode = currentNode->next;
        accessNodes++;
    }

    printf("%f %f %f TOTAL:%d\n", smallerNode->data.coordinate[X], smallerNode->data.coordinate[Y], smallerNode->data.coordinate[Z], accessNodes);

}

void id (struct Node **head_ref, int id){
    struct Node *currentNode = (*head_ref);
    struct Node *headRequiredID = NULL;

    struct Data data;
    int currentID;
    while (currentNode != NULL){
        data = currentNode->data;
        currentID = currentNode->data.ID;
        
        //printf("%f %f %f %d %d %d %d\n", data.coordinate[X], data.coordinate[Y], data.coordinate[Z], data.rgb.red, data.rgb.green, data.rgb.blue, data.ID);
        
        if (currentID == id){
            sortedInsert(&headRequiredID, data, X, X);
        }
        currentNode = currentNode->next;

        showAllNodes(&headRequiredID);
    }
    //printf("===========\n");
    //struct Node *head = headRequiredID;
    //showAllNodes(&head);
}