// ## IDE: Visual Studio Code - popOS
// ## Nome Michel Hecker Faria
// ## Número USP: 12609690

#include "main.h"

void showAllNodes(struct Node **head_ref){
    struct Node *node = *head_ref;
    while (node != NULL){
        printf("%s %s %d \n", node->search.prefix, node->search.word, node->search.statistics);
        node = node->next;
    }
    
}

int main(){
    struct Node *head = NULL; 
    struct Node *node;
    struct Search data;

    char prefix[4];
    char word[20];
    int statistics; 
    int numberOfDatas;

    printf("====================================\n");

    printf("\nLendo arquivo de dados: arq.txt \n\n");
    FILE * fd;    
    fd = fopen("arq.txt", "r");
    do{
        fscanf(fd, "%s %s %d", prefix, word, &statistics);
        strcpy(data.prefix, prefix);
        strcpy(data.word, word);        
        data.statistics = statistics;

        append(&head, data);
        numberOfDatas++;
    } while(!feof(fd));
    fclose(fd);


    printf("%d dados lidos no total \n", numberOfDatas);
    showAllNodes(&head);

    printf("\n====================================\n");
    printf("\n");

    int result;

    printf("====================================\n");
    printf("\nAutocompletar \n\n");
    
    printf("Informe o prefixo: (2 ou 3 caracteres) \n");
    printf("Prefixo: ");
    scanf("%s", prefix);
    
    int n = 0;
    while (n < numberOfDatas){
        //
        pop(&head, prefix);
        n++;
    }

    showAllNodes(&head);

    printf("\n====================================\n");


    return 0;
}

