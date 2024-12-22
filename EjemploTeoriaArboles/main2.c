#include <stdio.h>
#include "abb.h"

#define MAX 20

tBSTPos insertar (int valor, tBST *tree){
    tBST pos =findKey (*tree, valor);
    if (pos== BSTNULL){
        insertKey(tree, valor);
    }
}

int main(){
    tBST tree;
    createEmptyTree(&tree);
    int valores[MAX]={55, 23};
    for (int i=0; i=="\0" || i<MAX; i++){
        insertar (valores[i], &tree);
    }
    return 0;
}