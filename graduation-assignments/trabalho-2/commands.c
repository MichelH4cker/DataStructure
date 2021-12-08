#include "commands.h"

int idOfCommand(){
    char *dictionary[10] = {"LX", "LY", "LZ", "LI", "LF", "TOT", "PZ", "PI", "ID", "CUT"};
    char command[3];
    int key = 0;
    scanf("%s", command);
    while (key < 10){
        if (strcmp(command, dictionary[key]) == 0){
            return key;       
        }
        key++;
    }
}


void wallyActs(struct Node **headOrderedX_ref, struct Node **headOrderedY_ref, struct Node **headOrderedZ_ref, struct Node **headPush_ref, struct Node **headAppend_ref){
    int task = idOfCommand();
    int intID;
    float coordinateMax[3];
    float coordinateMin[3];

    struct Node *newHeadX = *headOrderedX_ref;
    struct Node *newHeadPush = *headPush_ref;
    struct Node *newHeadAppend = *headAppend_ref;
    struct Node *head = NULL;
    switch (task){
        case 0:
            head = *headOrderedX_ref;
            lx(&head);
            return;
        case 1:
            head = *headOrderedY_ref;
            ly(&head);
            return;
        case 2:
            head = *headOrderedZ_ref;
            lz(&head);
            return;
        case 3:
            head = *headPush_ref;
            li(&head);
            return;
        case 4:
            head = *headAppend_ref;
            lf(&head);
            return;
        case 5:
            tot(&newHeadX, &newHeadPush, &newHeadAppend);
            return;
        case 6:
            head = *headOrderedZ_ref;
            pz(&head);
            return;
        case 7:
            head = *headPush_ref;
            pi(&head);
            return;
        case 8:
            scanf("%d", &intID);
            head = *headOrderedX_ref;
            id(&head, intID);
            return;
        case 9:
            scanf("%f %f %f %f %f %f \n", &coordinateMin[X], &coordinateMin[Y], &coordinateMin[Z], &coordinateMax[X], &coordinateMax[Y], &coordinateMax[Z]);
       
            head = *headOrderedX_ref;

            cut(&head, coordinateMax, coordinateMin);
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
        printf("%.5f, %.5f, %.5f, %d, %d, %d, %d\n", currentNode->data.coordinate[X], currentNode->data.coordinate[Y], currentNode->data.coordinate[Z], currentNode->data.rgb.red, currentNode->data.rgb.green, currentNode->data.rgb.blue, currentNode->data.ID);
        
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

void lx (struct Node **head_ref){
    if (head_ref == NULL) return;
    struct Node *newHead = *head_ref;
    showAllNodes(&newHead, -1, 0);
}

void ly (struct Node **head_ref){
    if (head_ref == NULL) return;
    struct Node *newHead = *head_ref;
    showAllNodes(&newHead, -1, 0);
}

void lz (struct Node **head_ref){
    if (head_ref == NULL) return;
    struct Node *newHead = *head_ref;
    showAllNodes(&newHead, -1, 0);
}

void li (struct Node **head_ref){
    if (head_ref == NULL) return;
    struct Node *newHead = *head_ref;
    showAllNodes(&newHead, -1, 0);
}

void lf (struct Node **head_ref){
    if (head_ref == NULL) return;
    struct Node *newHead = *head_ref;
    showAllNodes(&newHead, -1, 0);
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

void pz (struct Node **head_ref){
    struct Node *smallerNode = *head_ref;
    printf("%.5f %.5f %.5f TOTAL:1\n", smallerNode->data.coordinate[X], smallerNode->data.coordinate[Y], smallerNode->data.coordinate[Z]);
}

void pi (struct Node **head_ref){
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

    printf("%.5f %.5f %.5f TOTAL:%d\n", smallerNode->data.coordinate[X], smallerNode->data.coordinate[Y], smallerNode->data.coordinate[Z], accessNodes);

}

void id (struct Node **head_ref, int id){
    struct Node *anotherHead_ref = *head_ref;
    showAllNodes(&anotherHead_ref, id, 1);
}


void cut (struct Node **head_ref, float *coordinateMax, float *coordinateMin){
    struct Node *currentNode = *head_ref;
    struct Node *newHead = NULL;
    struct Data data;

    float currentCoordinate[3];

    int show = 0;

    while (currentNode != NULL){
        currentCoordinate[X] = currentNode->data.coordinate[X]; 
        currentCoordinate[Y] = currentNode->data.coordinate[Y]; 
        currentCoordinate[Z] = currentNode->data.coordinate[Z]; 
        
        if ((currentCoordinate[X] <= coordinateMax[X]) && (currentCoordinate[Y] <= coordinateMax[Y]) && (currentCoordinate[Z] <= coordinateMax[Z]) && (currentCoordinate[X] >= coordinateMin[X]) && (currentCoordinate[Y] >= coordinateMin[Y]) && (currentCoordinate[Z] >= coordinateMin[Z])){
            data = currentNode->data;
            append(&newHead, data);
        }
    
        currentNode = currentNode->next;
    }
    showAllNodes(&newHead, -1 , 0);
}