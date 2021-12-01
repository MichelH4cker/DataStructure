#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>

#include "insertion.h"
#include "commands.h"
#include "file.h"

struct Coordinate {
    float x;
    float y;
    float z;
};

struct RGB {
    int red;
    int green;
    int blue;
};

struct Data {
    struct Coordinate coordinate;
    struct RGB rgb;
    int ID;
};

struct Node {
    struct Data data;
    struct Node *next;
    struct Node *previous;
};

#endif
