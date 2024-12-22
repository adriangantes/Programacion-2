#ifndef EJEMPLOTEORIAARBOLES_ABB_H
#define EJEMPLOTEORIAARBOLES_ABB_H

#include <stdbool.h>
#include <stdlib.h>

#define BSTNULL NULL

typedef int tKey;
typedef struct tBSTNode* tBSTPos;
struct tBSTNode{
    tKey key;
    tBSTPos left, right;
};
typedef tBSTPos tBST;

void createEmptyTree(tBST* tree);
bool insertKey (tBST* tree, tKey key);

tBST leftChild (tBST tree);
tBST rightChild (tBST tree);
tKey root (tBST tree);
bool isEmptyTree (tBST tree);
tBST findKey (tBST tree, tKey key);

void removeKey (tBST* tree, tKey key);

#endif //EJEMPLOTEORIAARBOLES_ABB_H
