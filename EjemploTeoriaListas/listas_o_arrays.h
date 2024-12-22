#ifndef EJEMPLOTEORIA_LISTAS_O_ARRAYS_H
#define EJEMPLOTEORIA_LISTAS_O_ARRAYS_H

#include <stdbool.h>
#define MAX 100
#define LNULL -1

typedef int tItemL;
typedef int tPosL;

typedef struct{
    tItemL data[MAX];
    tPosL lastPos;
} tList;

void createEmptyList(tList* L);
bool insertItem (tItemL d, tPosL p, tList* L);
void updateItem(tItemL d, tPosL p,tList* L);
bool copyList(tList  L, tList* M);
tPosL first (tList L);
tPosL last(tList L);
tPosL previous(tPosL p, tList L);
tPosL next(tPosL p, tList L);
bool isEmptyList(tList L);
tItemL getItem(tPosL p, tList L);
tPosL findItem (tItemL d, tList L);
void deleteList(tList* L);
void deleteAtPosition (tPosL p, tList* L);

#endif //EJEMPLOTEORIA_LISTAS_O_ARRAYS_H
