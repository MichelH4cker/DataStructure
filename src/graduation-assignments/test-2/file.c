#include "file.h"

void readAndStorageFile(struct Node **root_ref){
    FILE *fp;
    fp = fopen("cepdata.txt", "r");

    if (fp == NULL) return; 
    
    struct Data data;

    while (fp != NULL){
        fscanf(fp, "%d %d %s %s\n", &data.initialCEP, &data.endCEP, data.city, data.state);

        if (data.initialCEP == 0){
            break;
        } 

        insert(&(*root_ref), data);

    }
    
    fclose(fp);
}