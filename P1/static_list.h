/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Miguel Marcos Trillo LOGIN 1: miguel.mt
 * AUTHOR 2: Adrián Edreira Gantes LOGIN 2: adrian.gantes
 * GROUP: 1.4
 * DATE: 16 / 03 / 23
 */

#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include "types.h"
#include <string.h>
#define LNULL (-1) //constante nula
#define max 25  //maximo participantes
//declaracion de tipos
typedef int tPosL; //entero tipo posicion
typedef struct { //struct formada por los participantes y la ulima posicion de la lista
    tItemL member[max];
    tPosL lastPos; //ultimo elemento de la lista
}tList;

void createEmptyList(tList* L);
/*Objetivo:Crear lista vacia
  Entrada:Lista
  Salida:Lista
  PostCD:Lista inicializada y sin elementos*/
bool isEmptyList(tList L);
/*Objetivo:Determinar si la lista esta vacia
  Entrada:Lista
  Salida:bool
  PreCD:Lista inicializada */
tPosL first(tList L);
/*Objetivo:Devuelve la posicion del primer elemento de la lista
  Entrada:Lista
  Salida:posicion
  PreCD:Lista inicializada y no vacia */
tPosL last (tList L);
/*Objetivo:Devuelve la posicion del ultimo elemento de la lista
  Entrada:Lista
  Salida:posicion
  PreCD:Lista inicializada y no vacia */
tPosL previous(tPosL p ,tList L);
/*Objetivo:Devuelve la posicion del elemento anterior al de la posicion indicada(o nulo si no la tiene)
  Entrada:Lista,posicion
  Salida:posicion
  PreCD:Lista inicializada y posicion indicada valida */
tPosL next(tPosL p ,tList L);
/*Objetivo:Devuelve la posicion del elemento siguiente al de la posicion indicada(o nulo si no la tiene)
  Entrada:Lista,posicion
  Salida:posicion
  PreCD:Lista inicializada y posicion indicada valida */
bool insertItem(tItemL D ,tPosL p ,tList* L);
/*Objetivo:Inserta un elemento en la lista antes de la posicion indicada o al final si la posicion es nula.Devuelve true o false en funcion de si el elemento fue insertado o no
  Entrada:Lista,posicion,elemento
  Salida:lista,bool
  PreCD:Lista inicializada y posicion indicada valida o nula
  PostCD:Las posiciones de los elementos de la lista pueden haber variado*/
void deleteAtPosition(tPosL p ,tList* L);
/*Objetivo:Elimina de la lista el elemento de la posicion indicada
  Entrada:Lista,posicion
  Salida:lista
  PreCD:Lista inicializada y posicion indicada valida
  PostCD:Las posiciones de los elementos posteriores al eliminado de la lista pueden haber variado*/
tItemL getItem(tPosL p ,tList L);
/*Objetivo:Devuelve el contenido del elemento de la lista de la posicion indicada
  Entrada:Lista,posicion
  Salida:elemento
  PreCD:Lista inicializada y posicion indicada valida */
void updateItem(tItemL d ,tPosL p ,tList* L);
/*Objetivo:Modifica el contenido del elemento de la lista de la posicion indicada
  Entrada:Lista,posicion,elemento
  Salida:lista
  PreCD:Lista inicializada y posicion indicada valida
  PostCD:El orden de los elementos de la lista no se ve modificado*/
tPosL findItem(tParticipantName d ,tList L);
/*Objetivo:Devuelve la posicion del primer elemento de la lista cuyo nombre sea igual al indicado o nulo si no existe
  Entrada:Lista,nombre_participante
  Salida:posicion
  PreCD:Lista inicializada*/


#endif
