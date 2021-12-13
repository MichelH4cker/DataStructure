#include "file.h"

void readAndStorageFile(struct Node **cpfTree, struct Node **nRegTree){
    FILE *fp;
    fp = fopen("dados.txt", "r");

    if (fp == NULL) return; // não conseguiu abrir o arquivo

    struct Data data;
    do {
        fscanf(fp, "%d %d %s\n", &data.dataArray[CPF], &data.dataArray[NREG]);

        insert(&(*cpfTree), data, CPF);
        insert(&(*nRegTree), data, NREG);

    } while (!feof(fp));
    
    fclose(fp);
}