#include "colas_punteros.h"

void createEmptyQueue(tQueue *Q){
    Q->front = QNULL;
    Q->rear = QNULL;
}

bool createNode (tPosQ *p){
    *p = malloc (sizeof(struct tNodeQ));
    return *p != QNULL;
}

bool enqueue(tItemQ d, tQueue *Q){
    tPosQ q;

    if(!createNode(&q)){
        return false;
    }else{
        q->data = d;
        q->next = QNULL;
        if (Q->front == QNULL){
            Q->front = q;
        }else{
            Q->rear->next = q;
        }
        Q->rear = q;
        return true;
    }
}

void dequeue (tItemQ d, tQueue *Q){
    tPosQ q;

    q = Q->front;
    Q->front = q->next;

    if (Q->front == QNULL){
        Q->rear = QNULL;
    }
    free(q);
}

tItemQ front (tQueue Q){
    return Q.front->data;
}

bool isEmptyQueue (tQueue Q){
    return (Q.front == QNULL);
}