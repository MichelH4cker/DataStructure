#include "commands.h"

int idOfCommand(){
    char *dictionary[10] = {"lx", "ly", "lz", "li", "lf", "tot", "pz", "pi", "id", "cut"};
    char command[3];
    int key = 0;
    scanf("%s", command);
    while (id < 9){
        if (strcmp(command, dictionary[key]) == 0){
            return key;       
        }
        key++;
    }
}

void wallyActs(){
    switch (){
        case 0:
            return;
        case 1:
            return;
        case 2:
            return;
        case 3:
            return;
        case 4:
            return;
        case 5:
            return;
        case 6:

            return;
        case 7:

            return;
        case 8:

            return;
        case 9:

            return;
        default:
            return;
    }
}

void showAllNodes (struct Node **head_ref, int id, int idFunctionActivated){
    if (head_ref == NULL) return;
    
    struct Node *currentNode = *head_ref;
    int currentID;
    while (currentNode != NULL){
        currentID = currentNode->data.ID;
        if ((id != currentID) && idFunctionActivated == 1){
            currentNode = currentNode->next;    
            continue;
        }
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
    
    showAllNodes(&head_ref, -1, 0);
}

void ly (struct Node *head_ref){
    if (head_ref == NULL) return;
    
    showAllNodes(&head_ref, -1, 0);
}

void lz (struct Node *head_ref){
    if (head_ref == NULL) return;
    
    showAllNodes(&head_ref, -1, 0);
}

void li (struct Node *head_ref){
    if (head_ref == NULL) return;
    
    showAllNodes(&head_ref, -1, 0);
}

void lf (struct Node *head_ref){
    if (head_ref == NULL) return;
    
    showAllNodes(&head_ref, -1, 0);
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
    struct Node *anotherHead_ref = *head_ref;
    showAllNodes(&anotherHead_ref, id, 1);
}