/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Miguel Marcos Trillo LOGIN 1: miguel.mt
 * AUTHOR 2: Adrián Edreira Gantes LOGIN 2: adrian.gantes
 * GROUP: 1.4
 * DATE: 28 / 04 / 23
 */

#ifndef JURY_LIST_H
#define JURY_LIST_H

#include "types.h"
#include "participant_list.h"
#include <stdbool.h>
#define MAX 10
#define NULLJ -1


typedef int tPosJ; //entero tipo posicion
typedef struct{
    tJuryName juryName;  //nombre jurado
    tNumVotes totalVoters;  //votos totales
    tNumVotes validVotes;  //votos validos
    tNumVotes nullVotes;  //votos nulos
    tListP participantList;  //lista participantes
}tItemJ;

typedef struct{
    tItemJ dataJ[MAX];  //elemento con tamaño max
    tPosJ lastPosJ; //ultimo elemento de la lista
} tListJ;

/* Prototipos de funciones */

void createEmptyListJ (tListJ* J);
/*Objetivo:Crear lista vacia
  Entrada:Lista
  Salida:Lista
  PostCD:Lista inicializada y sin elementos */

bool insertItemJ (tItemJ d, tListJ* J);
/* Objetivo: Inserta un elemento en la lista segun el criterio de ordenacion sobre el campo Item
Entrada:
Item: Contenido del elemento a insertar
List: Lista donde vamos a insertar
Salida:
List: Lista con el elemento Item insertado en la posicion correspondiente segun su contenido y verdadero si se ha podido insertar, falso en caso contrario
Precondicion: La lista esta inicializada
Postcondicion: Las posiciones de los elementos de la lista posteriores a la del elemento insertado pueden haber variado */

void updateItemJ (tItemJ d, tPosJ p,tListJ* J);
/*Objetivo:Modifica el contenido del elemento de la lista de la posicion indicada
  Entrada:Lista,posicion,elemento
  Salida:lista
  PreCD:Lista inicializada y posicion indicada valida
  PostCD:El orden de los elementos de la lista no se ve modificado*/

tPosJ firstJ (tListJ J);
/*Objetivo:Devuelve la posicion del primer elemento de la lista
  Entrada:Lista
  Salida:posicion
  PreCD:Lista inicializada y no vacia */

tPosJ lastJ (tListJ J);
/*Objetivo:Devuelve la posicion del ultimo elemento de la lista
  Entrada:Lista
  Salida:posicion
  PreCD:Lista inicializada y no vacia */

tPosJ previousJ (tPosJ p, tListJ J);
/*Objetivo:Devuelve la posicion del elemento anterior al de la posicion indicada(o nulo si no la tiene)
  Entrada:Lista,posicion
  Salida:posicion
  PreCD:Lista inicializada y posicion indicada valida */

tPosJ nextJ (tPosJ p, tListJ J);
/*Objetivo:Devuelve la posicion del elemento siguiente al de la posicion indicada(o nulo si no la tiene)
  Entrada:Lista,posicion
  Salida:posicion
  PreCD:Lista inicializada y posicion indicada valida */

bool isEmptyListJ (tListJ J);
/*Objetivo:Determinar si la lista esta vacia
  Entrada:Lista
  Salida:bool
  PreCD:Lista inicializada */

tItemJ getItemJ (tPosJ p, tListJ J);
/*Objetivo:Devuelve el contenido del elemento de la lista de la posicion indicada
  Entrada:Lista,posicion
  Salida:elemento
  PreCD:Lista inicializada y posicion indicada valida */

tPosJ findItemJ (tJuryName d, tListJ J);
/*Objetivo:Devuelve la posicion del primer elemento de la lista cuyo nombre sea igual al indicado o nulo si no existe
  Entrada:Lista,nombre_jurado
  Salida:posicion
  PreCD:Lista inicializada */

void deleteAtPositionJ (tPosJ p, tListJ* J);
/*Objetivo:Elimina de la lista el elemento de la posicion indicada
  Entrada:Lista,posicion
  Salida:lista
  PreCD:Lista inicializada y posicion indicada valida
  PostCD:Las posiciones de los elementos posteriores al eliminado de la lista pueden haber variado */

#endif
