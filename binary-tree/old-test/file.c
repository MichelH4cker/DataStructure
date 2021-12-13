#include "file.h"

void readAndStorageFile(struct Node **cpfTree, struct Node **nRegTree){
    FILE *fp;
    fp = fopen("dados.txt", "r");

    if (fp == NULL) return; 
    
    struct Data data;
    do {
        fscanf(fp, "%d %d\n", &data.dataArray[CPF], &data.dataArray[NREG]);

        insert(&(*cpfTree), data, CPF);
        insert(&(*nRegTree), data, NREG);

    } while (!feof(fp));
    
    
    fclose(fp);
}

void createAndStorageInFile(){

}