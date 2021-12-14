#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>

#include "tree-tad.h"

struct Node {
    int intData;
    int height;
    struct Node *left;
    struct Node *right;
};

#endif