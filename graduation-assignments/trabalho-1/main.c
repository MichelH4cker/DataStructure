#include "main.h"

void showAllNodes(struct Node *head_ref){
    struct Node *node = head_ref;    

    while (node != NULL){
        printf("%.1f ", node->data);

        node = node->next;
    }
    
}
    
void receiveInputs(struct Node **head, int typeInsertion){
    float input;
    for (int data = 0; ; data++){   // insert all values
        scanf("%f", &input);
        if (input == 0){
            break;
        } else {
            if (typeInsertion == 3)
                descendingInsert(head,input);
            else 
                crescentInsert(head, input);
            
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
    
    struct Node *head = NULL;
    for (int i = 0; i < totalInputs; i++){
        receiveInputs(&head, type);
    }
    
    showAllNodes(head);
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