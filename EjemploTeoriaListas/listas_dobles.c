#include "listas_dobles.h"

void createEmptyList (tList* L){
    *L=LNULL;
}

bool createNode(tPosL *p){
    *p=malloc(sizeof (struct tNode));
    return *p !=LNULL;
}

bool insertItem(tItemL d,tPosL p,tList* L){
    tPosL q,r;

    if(!createNode(&q))
        return false;
    else{
        q->data = d;
        q->next = LNULL;
        q->prev = LNULL;

        if(*L==LNULL){
            *L =q;
        }else if(p== LNULL){
            for(r=*L;r->next!=LNULL;r=r->next);
            r->next=q;
            q->prev=r;
        }else if(p== *L){
            q->next=*L;
            p->prev=q;
            *L =q;
        }else{
            q->data=p->data;
            p->data=d;
            if (p->next != LNULL){
                p->next->prev= q;
            }
            q->next = p->next;
            p->next = q;
            q->prev = p;
        }
        return true;
    }
}

bool copyList(tList L,tList* M){
    tPosL p;
    bool result;

    createEmptyList(M);
    if(isEmptyList(L)){
        result=true;
    }else{
        for(p=L;(p!=LNULL)&& insertItem(getItem(p,L),LNULL,M);p=p->next);
        if(p==LNULL){
            result=true;
        }else{
            result=false;
            deleteList(M);
        }
    }
    return result;
}

void updateItem(tItemL d,tPosL p,tList* L){
    p->data=d;
}

tPosL findItem(tItemL d,tList L){
    tPosL p;
    for(p=L;(p!=LNULL) && (p->data!=d);p=p->next);
    return p;
}

tPosL first(tList L){
    return L;
}
tPosL last (tList L){
    tPosL p;
    for(p=L;p->next !=LNULL;p=p->next);
    return p;
}
tPosL previous(tPosL p,tList L){
    return p->prev;
}
tPosL next(tPosL p,tList L){
    return p->next;
}

bool isEmptyList(tList L){
    return L==LNULL;
}

tItemL getItem(tPosL p,tList L){
    return p->data;
}

void deleteList(tList* L){
    tPosL p;

    while (*L !=LNULL){
        p=*L;
        *L =(*L)->next;
        free(p);
    }
}

void deleteAtPosition(tPosL p,tList* L){
    tPosL q;
    if (p== *L){
        *L= (*L)->next;
        if (*L != LNULL){
            (*L)->prev=LNULL;
        }
    }else{
        q=p->prev;
        q->next = p->next;
        if (p->next !=LNULL){
            p->next->prev=q;
        }
    }
    free(p);
    p=LNULL;
}

void deleteLast(tList* L){
    tPosL p;

    if ((*L)!=LNULL){
        if ((*L)->next == LNULL){
            free(*L);
            (*L)=LNULL;
        }else{
            for (p = *L;p->next->next!=LNULL;p=p->next);
            free(p->next);
            p->next=LNULL;
        }

    }
}

void backRotate (tList* L){
    tPosL temp, ini;
    if ((*L)->next!=LNULL && (*L)!=LNULL) {
        for (temp= *L;temp-> next -> next!= LNULL; temp= temp-> next);
        ini= (*L)->next;
        (*L)-> next = LNULL;
        (*L)-> prev= temp->next;
        temp-> next -> next = *L;
        (*L)= ini;
        (*L)->prev= LNULL;
    }
}