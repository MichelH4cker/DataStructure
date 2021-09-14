#include<stdio.h>
#include "main.h"
#include "createDestroyList.h"

int main (){
    List *list;
    list = createList();


    freeList(list);
    return 0;
}
/* FUNÇÕES PRINCIPAIS DE UMA TAD:
-
-
-
-
*/
    