#include "file.h"

void readFileAndPush(struct Node **headNonOrdered_ref){
    struct Node *newHead = *headNonOrdered_ref;

    FILE *fp;
    fp = fopen("dados3d.txt", "r");
    if (fp == NULL) return; // não conseguiu abrir o arquivo

    struct Data data;

    while (fp != NULL){
        fscanf(fp, "%f %f %f %d %d %d %d", &data.coordinate.x, &data.coordinate.y, &data.coordinate.z, &data.rgb.red, &data.rgb.green, &data.rgb.blue, &data.ID);
        if (data.ID == -1){
            break;
        }
        else {
            push(&newHead, data);
        }
        printf("%f \n", newHead->data.coordinate.x);
    }

    fclose(fp);

    *headNonOrdered_ref = newHead;
}