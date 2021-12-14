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

void fprintfInFile(struct Node **root_ref, FILE **fp){
    if(root_ref == NULL) return;

    if(*root_ref != NULL){
        fprintfInFile(&((*root_ref)->left), &(*fp));
        fprintf((*fp), "%d %d\n", (*root_ref)->data.initialCEP, (*root_ref)->data.endCEP);
        fprintfInFile(&((*root_ref)->right), &(*fp));
    }
}


void createAndStorageInFile(struct Node **root_ref, int flag){
    FILE *fp;

    fp = fopen("cepdata.txt", "w");
    if (fp == NULL) return;
    
    struct Node *newRoot_ref = *root_ref;
    fprintfInFile(&newRoot_ref, &fp);

    fclose(fp);
}

void readCreatedFiles(int flag){
    FILE *fp;

    fp = fopen("cepdata.txt", "r");
    if (fp == NULL) return;
  
    int cpf;
    int nreg;
    do {
        fscanf(fp, "%d %d\n", &cpf, &nreg);
        printf("%d %d\n", cpf, nreg);    
    } while (!feof(fp));
    
    fclose(fp);
}