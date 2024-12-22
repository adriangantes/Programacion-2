//
// Created by alonso on 23/11/18.
//

#ifndef AVL_C_AVL_H
#define AVL_C_AVL_H

#include <stdbool.h>

#define NULLAVL NULL

typedef int tKey;
typedef struct tAVLNode *tAVLPos;  // type of AVL Positions
struct tAVLNode {               // Type of AVL Nodes
    tKey key;
    int bf;                     // balance factor: -1 .. 1
    tAVLPos left, right;
};

typedef tAVLPos tAVL;        // type of AVL trees

// function prototypes
// Constructor - Generators
void createEmptyTree(tAVL *tree);

bool insertKey(tAVL *tree, tKey key);

// Observers
tAVL leftChild(tAVL tree);

tAVL rightChild(tAVL tree);

tKey root(tAVL tree);

bool isEmptyTree(tAVL tree);

tAVL findKey(tAVL tree, tKey key);

// Destrutors
void removeKey(tAVL *tree, tKey key);


#endif //AVL_C_AVL_H
