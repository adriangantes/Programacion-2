#ifndef EJEMPLOTEORIACOLAS_COLAS_ARRAYS_H
#define EJEMPLOTEORIACOLAS_COLAS_ARRAYS_H

#include <stdbool.h>
#include <stdlib.h>
#define QNULL NULL
#define Q_MAX 10

typedef int tItemQ;
typedef struct queue{
    tItemQ data [Q_MAX];
    int front, rear;
}tQueue;

void createEmptyQueue(tQueue *Q);
bool enqueue(tItemQ d, tQueue *Q);
void dequeue (tQueue *Q);
tItemQ front (tQueue Q);
bool isEmptyQueue (tQueue Q);

#endif //EJEMPLOTEORIACOLAS_COLAS_ARRAYS_H
