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

void fprintfInFile(struct Node **root_ref, FILE **fp){
    if(root_ref == NULL) return;

    if(*root_ref != NULL){
        fprintfInFile(&((*root_ref)->left), &(*fp));
        fprintf((*fp), "%d %d\n", (*root_ref)->data.dataArray[CPF], (*root_ref)->data.dataArray[NREG]);
        fprintfInFile(&((*root_ref)->right), &(*fp));
    }
}


void createAndStorageInFile(struct Node **root_ref, int flag){
    FILE *fp;

    if (flag == CPF){
        fp = fopen("CPF.txt", "w");
    } else {
        fp = fopen("NReg.txt", "w");
    }
    if (fp == NULL) return;
    
    struct Node *newRoot_ref = *root_ref;
    fprintfInFile(&newRoot_ref, &fp);

    fclose(fp);
}

void readCreatedFiles(int flag){
    FILE *fp;

    if (flag == CPF){
        fp = fopen("CPF.txt", "r");
    } else {
        fp = fopen("NReg.txt", "r");
    }

    int cpf;
    int nreg;
    do {
        fscanf(fp, "%d %d\n", &cpf, &nreg);
        printf("%d %d\n", cpf, nreg);    
    } while (!feof(fp));
    
    fclose(fp);
}