#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "linked-list.h"

struct Search {
    char prefix[4];
    char word[20];
    int statistics;
};

struct Node {
    struct Search search;
    struct Node *next;
};


#endif