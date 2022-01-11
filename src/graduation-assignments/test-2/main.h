#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree-tad.h"
#include "file.h"
#include "commands.h"

struct Data {
    int initialCEP;
    int endCEP;
    char city[30];
    char state[2];
};

struct Node {
    int height;    
    struct Node *left;
    struct Node *right;
    struct Data data;
};

#endif