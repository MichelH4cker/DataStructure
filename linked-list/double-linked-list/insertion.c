#include "insertion.h"

void push(struct Data data, struct Node **head_ref){
    if (emptyList(head_ref)){
        (*head_ref)->data = data;
    } 
}

void append(struct Data data, struct Node **head_ref){
    // verificar se a lista está vazia 

} 