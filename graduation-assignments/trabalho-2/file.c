#include "file.h"

void readAndStorageFile(struct Node **headNonOrderedPush_ref, struct Node **headNonOrderedAppend_ref, struct Node **headOrdered_ref, int axis){
    struct Node *newHeadPush = *headNonOrderedPush_ref;
    struct Node *newHeadAppend = *headNonOrderedAppend_ref;
    struct Node *newHeadOrdered = *headNonOrderedAppend_ref;

    FILE *fp;
    fp = fopen("dados3d.txt", "r");
    if (fp == NULL) return; // não conseguiu abrir o arquivo

    struct Data data;

    while (fp != NULL){
        fscanf(fp, "%f %f %f %d %d %d %d", &data.coordinate[0], &data.coordinate[1], &data.coordinate[2], &data.rgb.red, &data.rgb.green, &data.rgb.blue, &data.ID);
        if (data.ID == -1){
            break;
        }
        else {
            push(&newHeadPush, data);
            append(&newHeadAppend, data);
            sortedInsert(&newHeadOrdered, data, axis);
        }
        //printf("%f \n", newHead->data.coordinate.x);
    }

    fclose(fp);

    *headNonOrderedPush_ref = newHeadPush;
    *headNonOrderedAppend_ref = newHeadAppend;
    *headOrdered_ref = newHeadOrdered;
}