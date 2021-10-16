#include "main.h"

void showAllNodes(struct Node **array, int totalInputs){
    printf("dentro da posicao zero do array, temos o float de %f \n", array[0]->data);
    float ithInput = 1;
    printf("entrou no showAllNodes \n");
    for (int positionOnArray = 0; positionOnArray < totalInputs; positionOnArray++){
        printf("entrou no primeiro for! \n");
        struct Node *currentNode = array[positionOnArray]; // receive head_ref
        
        for (int i = 0; ithInput != 0; i++){    // run all nodes
            printf("entrou no segundo for! \n");
            printf("valor do currentNode %f \n", currentNode->data);
            ithInput = (*currentNode).data;
            printf("Input: %f \n", ithInput);
            currentNode = (*currentNode).next;
        }
        
    }
    

}
    
struct Node* receiveInputs(struct Node **head){
    float input;
    struct Node *head_ref = *head;
    for (int data = 0; ; data++){   // insert all values
        scanf("%f", &input);
        if (input == 0){
            append(&head_ref, input);
            return head_ref;
        } else {
            crescentInsert(&head_ref, input);
            printf("o input inserido foi %f \n", input);
        }
    
    }
}

int main (void){
    int type;
    scanf("%d", &type);

    int totalInputs;
    scanf("%d", &totalInputs);

    struct Node* array[totalInputs];
    
    //receive inputs
    for (int positionOnArray = 0; positionOnArray < totalInputs; positionOnArray++){
        struct Node *head = NULL;
        head = receiveInputs(&head);
        array[positionOnArray] = head;
    }
    
    printf("\n %f \n\n", array[0]->next->data);
    showAllNodes(array, totalInputs);
}

/*

####### TIPOS DE ENTRADA LISTA #######

1 - listas de dados que já estão ordenadas, sendo necessário 
apenas a unificação das duas listas (merge)

2 - contém listas de dados que não foram ordenadas

3 - listas não ordenadas, mas que devem ser exibidas 
na ordem inversa  (decrescente) 
no final do processo de ordenação e  unificação

*/