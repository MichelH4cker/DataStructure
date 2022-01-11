#include "file.h"

void readAndStoreFile (struct Node **root_ref){
    FILE *fp;
    fp = fopen("circuit.txt", "r");
    if (fp == NULL) return; 

    struct Data newData;

    char direction;
    char fatherIdentifier[6];
    char type[4];

    while (fp != NULL){
        fscanf(fp, "%s %c %s\n", newData.uniqueIdentifier, &direction, fatherIdentifier);

        if (direction == 'X'){
            break;
        } else {
            newData.typeOfNode = identifiesNodeType(newData.uniqueIdentifier);
            insert(&(*root_ref), newData, direction, fatherIdentifier);
        }
    }

    fclose(fp);
}