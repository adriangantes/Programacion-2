#ifndef EJEMPLOTEORIA_COLAS_PUNTEROS_H
#define EJEMPLOTEORIA_COLAS_PUNTEROS_H

#include <stdbool.h>
#include <stdlib.h>
#define QNULL NULL

typedef int tItemQ;
typedef struct tNodeQ *tPosQ;
struct tNodeQ{
    tItemQ data;
    tPosQ next;
};

typedef struct Queue{
    tPosQ front;
    tPosQ rear;
} tQueue;

void createEmptyQueue(tQueue *Q);
bool enqueue(tItemQ d, tQueue *Q);
void dequeue (tItemQ d, tQueue *Q);
tItemQ front (tQueue Q);
bool isEmptyQueue (tQueue Q);

#endif //EJEMPLOTEORIA_COLAS_PUNTEROS_H
