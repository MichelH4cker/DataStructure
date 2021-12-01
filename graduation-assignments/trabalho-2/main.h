#ifndef __MAIN_H__
#define __MAIN_H__

#define TRUE 1;
#define FALSE 0;
#define X 1
#define Y 2
#define Z 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "insertion.h"
#include "commands.h"
#include "file.h"

struct RGB {
    int red;
    int green;
    int blue;
};

struct Data {
    float coordinate[3];
    struct RGB rgb;
    int ID;
};

struct Node {
    struct Data data;
    struct Node *next;
    struct Node *previous;
};

#endif
