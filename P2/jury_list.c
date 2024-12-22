/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Miguel Marcos Trillo LOGIN 1: miguel.mt
 * AUTHOR 2: Adrián Edreira Gantes LOGIN 2: adrian.gantes
 * GROUP: 1.4
 * DATE: 28 / 04 / 23
 */

#include "jury_list.h"
#include "participant_list.h"

void createEmptyListJ (tListJ* J){
    J -> lastPosJ = NULLJ; //creamos una lista vacia
}

bool insertItemJ (tItemJ d, tListJ* J){
    tPosJ i;

    if(J->lastPosJ==MAX-1){ //si el ultimo elemento esta en la ultima posicion no se puede insertar el elemento
        return false;
    }else{
        if(isEmptyListJ(*J) || strcmp(J->dataJ[J->lastPosJ].juryName, d.juryName)<0 ){
            //si la lista es vacia o es mayor que el ultimo elemento se añade al final
            J->lastPosJ++;
            J->dataJ[J->lastPosJ] = d;
        }else{
            J->lastPosJ++; //sino añadimos el elemento en la lista de forma ordenada
            for(i=J->lastPosJ;i>0 && strcmp(J->dataJ[i-1].juryName, d.juryName)>0;i--){
                J->dataJ[i] = J->dataJ[i-1];
            }
            J->dataJ[i] = d;
        }
    }
    return true;
}

void updateItemJ (tItemJ d, tPosJ p,tListJ* J){
    J->dataJ[p]=d; //otorgamos al valor de la posicion indicada el elemento indicado
}

tPosJ firstJ (tListJ J){
    return 0;  //primera posicion
}

tPosJ lastJ (tListJ J){
    return J.lastPosJ;  //ultima posicion
}

tPosJ previousJ (tPosJ p, tListJ J){
    if(p==0){ //si es la primera posicion devuelve nulo
        return NULLJ;
    }else{ //sino devuelve la posicion previa
        return --p;
    }
}

tPosJ nextJ (tPosJ p, tListJ J){
    if(p==J.lastPosJ){  //si es la ultima posicion devuelve nulo
        return NULLJ;
    }else{ //sino devuelve la posicion siguiente
        return ++p;
    }
}

bool isEmptyListJ (tListJ J){
    return J.lastPosJ==NULLJ;  //si esta vacia devuelve true sino false
}

tItemJ getItemJ (tPosJ p, tListJ J){
    return J.dataJ[p]; //devuelve el item en la pòsicion indicada
}

tPosJ findItemJ (tJuryName d, tListJ J){
    tPosJ p;
    if (J.lastPosJ==NULLJ) { //si la lista esta vacia devuelve nulo
        return NULLJ;
    }else if ( strcmp(J.dataJ[0].juryName, d)>0 || strcmp(J.dataJ[J.lastPosJ].juryName, d)<0){
        //si no esta en la lista devuelve nulo
        return NULLJ;
    }else{
        for(p=0;(p<J.lastPosJ) &&  strcmp(J.dataJ[p].juryName, d)<0;p++); //recorremos la lista
        if ( strcmp(J.dataJ[p].juryName, d)==0){
            return p;  //si hay un elemento igual devuelve su posicion
        }else{  //sino devuelve nulo
            return NULLJ;
        }
    }
}

void deleteAtPositionJ (tPosJ p, tListJ* J){
    tPosJ q;
    for (q=p;q<J->lastPosJ;q++){ //recorremos la lista y eliminamos la posicion indicada
        J->dataJ[q]=J->dataJ[q+1];
    }
    J->lastPosJ--;
}