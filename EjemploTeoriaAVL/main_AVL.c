/*
 * árboles AVL
 * Autor: Miguel A. Alonso
 */

#include <stdio.h>

#include "avl.h"

void showInPreorder(tAVL tree) {
    printf("(");
    if (!isEmptyTree(tree)) {
        if (!isEmptyTree(leftChild(tree)) || !isEmptyTree(rightChild(tree))) {
            printf(" %d ", root(tree));
            showInPreorder(leftChild(tree));
            printf("  ");
            showInPreorder(rightChild(tree));
        } else
            printf(" %d ", root(tree));
    }
    printf(")");
}

int main()
{
    tAVL tree;
    printf("Hello world!\n");

    createEmptyTree(&tree);
    showInPreorder(tree); printf("\n");

    insertKey(&tree, 10); showInPreorder(tree); printf("\n");
    insertKey(&tree, 20); showInPreorder(tree); printf("\n");
    insertKey(&tree, 30); showInPreorder(tree); printf("\n");
    insertKey(&tree, 5); showInPreorder(tree); printf("\n");
    insertKey(&tree, 3); showInPreorder(tree); printf("\n");
    insertKey(&tree, 50); showInPreorder(tree); printf("\n");
    insertKey(&tree, 40); showInPreorder(tree); printf("\n");
    insertKey(&tree, 1); showInPreorder(tree); printf("\n");
    insertKey(&tree, 2); showInPreorder(tree); printf("\n");

    printf("==================================================\n");
    showInPreorder(tree); printf("\n");
    printf("==================================================\n");


    printf("deleting 1... "); removeKey(&tree, 1); showInPreorder(tree); printf("\n");
    printf("deleting 10... "); removeKey(&tree, 10); showInPreorder(tree); printf("\n");
    printf("deleting 2... "); removeKey(&tree, 2); showInPreorder(tree); printf("\n");
    printf("deleting 3... "); removeKey(&tree, 3); showInPreorder(tree); printf("\n");
    printf("deleting 5... "); removeKey(&tree, 5); showInPreorder(tree); printf("\n");

    return 0;
}
