#include "file.h"

int whichAxis(){
    char command[3];
    scanf("%s", command);

    if (strcmp(command, "lx") == 0){
        return X;
    } else if (strcmp(command, "ly") == 0) {
        return Y;
    } else {
        return Z;
    }
}

//headOrderedX, &headOrderedY, headOrderedZ, &headPush, &headAppend

void readAndStorageFile(struct Node **headOrderedX_ref, struct Node **headOrderedY_ref, struct Node **headOrderedZ_ref, struct Node **headPush_ref, struct Node **headAppend_ref){
    struct Node *newHeadPush     = *headPush_ref;
    struct Node *newHeadAppend   = *headAppend_ref;
    struct Node *newHeadOrderedX = *headOrderedX_ref;
    struct Node *newHeadOrderedY = *headOrderedY_ref;
    struct Node *newHeadOrderedZ = *headOrderedZ_ref;

    FILE *fp;
    fp = fopen("dados3d.txt", "r");
    if (fp == NULL) return; // não conseguiu abrir o arquivo

    struct Data data;

    while (fp != NULL){
        fscanf(fp, "%f %f %f %d %d %d %d", &data.coordinate[X], &data.coordinate[Y], &data.coordinate[Z], &data.rgb.red, &data.rgb.green, &data.rgb.blue, &data.ID);

        if (data.ID == -1){
            break;
        } else {
            push(&newHeadPush, data);
            append(&newHeadAppend, data);
            sortedInsert(&newHeadOrderedX, data, X, X);
            sortedInsert(&newHeadOrderedY, data, Y, Y);
            sortedInsert(&newHeadOrderedZ, data, Z, Z);
        }
    }

    fclose(fp);

    *headPush_ref     = newHeadPush;
    *headAppend_ref   = newHeadAppend;
    *headOrderedX_ref = newHeadOrderedX;
    *headOrderedY_ref = newHeadOrderedY;
    *headOrderedZ_ref = newHeadOrderedZ;
    
}