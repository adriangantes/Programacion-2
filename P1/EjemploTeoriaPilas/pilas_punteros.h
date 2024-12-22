#ifndef EJEMPLOTEORIAPILAS_PILAS_PUNTEROS_H
#define EJEMPLOTEORIAPILAS_PILAS_PUNTEROS_H

#include <stdbool.h>
#include <stdlib.h>
#define SNULL NULL

typedef int tItemS;
typedef struct tNodeS* tPosS;

struct tNodeS {
    tItemS data;
    tPosS down;
};
typedef tPosS tStack;

void createEmptyStack (tStack *S);
bool push (tItemS d, tStack *S);
void pop (tStack *S);
tItemS peek (tStack S);
bool isEmptyStack (tStack S);

#endif
