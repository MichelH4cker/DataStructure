#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>

struct Data {
  //dados 3d  
};


struct Node {
    struct Data data;
    struct Node *next;
    struct Node *previous;
};

#endif
