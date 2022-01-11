#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"
#include "file.h"

struct Data {
    char uniqueIdentifier[6];
    int typeOfNode;
    int inputValue;
};

struct Node {
    struct Data data;
    struct Node *left;
    struct Node *right;
};

#endif