#include "listas_array.h"

void createEmptyList(tList* L){
    L -> lastPos =LNULL;
}

bool insertItem (tItemL d, tPosL p, tList* L){
    tPosL q;
    if (L->lastPos==MAX-1){
        return false;
    }else{
        L->lastPos++;
        if (p==LNULL){
            L->data[L->lastPos]=d;
            return true;
        }else{
            for (q=L->lastPos; q>p; q--){
                L->data [q]=L->data[q-1];
            }
            L-> data [p] = d;
        }
        return false;
    }
}

void updateItem(tItemL d, tPosL p,tList* L){
    L->data[p]=d;
}

bool copyList(tList  L, tList* M){
    tPosL p;
    createEmptyList(M);
    if (!isEmptyList(L)){
        for(p=first(L);p<=L.lastPos;p++){
            insertItem(getItem(p,L),p,M );
        }
    }
    return true;
}

tPosL first (tList L){
    return 0;
}

tPosL last(tList L){
    return L.lastPos;
}

tPosL previous(tPosL p, tList L){
    if(p==0){
        return LNULL;
    }else{
        return --p;
    }
}

tPosL next(tPosL p, tList L){
    if(p==L.lastPos){
        return LNULL;
    }else{
        return ++p;
    }
}

bool isEmptyList(tList L){
    return L.lastPos==LNULL;
}

tItemL getItem(tPosL p, tList L){
    return L.data[p];
}

tPosL findItem (tItemL d, tList L){
    tPosL p;
    if(L.lastPos==LNULL){
        return LNULL;
    }else{
        for(p=0;(p<L.lastPos) && (L.data[p] != d);p++);
        if (L.data[p] == d){
            return p;
        }else{
            return LNULL;
        }
    }
}

void deleteList(tList* L){
    L->lastPos =LNULL;
}

void deleteAtPosition (tPosL p, tList* L){
    tPosL q;
    for (q=p;q<L->lastPos;q++){
        L->data[q]=L->data[q+1];
    }
    L->lastPos--;
}
