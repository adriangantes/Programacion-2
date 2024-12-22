/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Miguel Marcos Trillo LOGIN 1: miguel.mt
 * AUTHOR 2: Adrián Edreira Gantes LOGIN 2: adrian.gantes
 * GROUP: 1.4
 * DATE: 28 / 04 / 23
 */

#ifndef PARTICIPANT_LIST_H
#define PARTICIPANT_LIST_H

#include "types.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define NULLP NULL

typedef struct {
    tParticipantName participantName; //nombre del participante
    tNumVotes numVotes; //numero de votos
    tEUParticipant EUParticipant; //bool que indica eu o non-eu
}tItemP;

typedef struct tNode* tPosP;
struct tNode{
    tItemP dataP; //elemento de la dirección de memoria
    tPosP next; //siguiente dirección de memoria
};
typedef tPosP tListP;

/* Prototipos de funciones */

void createEmptyListP (tListP* P);
/*Objetivo:Crear lista vacia
  Entrada:Lista
  Salida:Lista
  PostCD:Lista inicializada y sin elementos*/

bool insertItemP (tItemP d,tListP* P);
/*Objetivo:Inserta un elemento en la lista antes de la posicion indicada o al final si la posicion es nula.Devuelve true o false en funcion de si el elemento fue insertado o no
  Entrada:Lista,posicion,elemento
  Salida:lista,bool
  PreCD:Lista inicializada y posicion indicada valida o nula
  PostCD:Las posiciones de los elementos de la lista pueden haber variado*/

bool isEmptyListP (tListP P);
/*Objetivo:Determinar si la lista esta vacia
  Entrada:Lista
  Salida:bool
  PreCD:Lista inicializada */

void deleteAtPositionP (tPosP p,tListP* P);
/*Objetivo:Elimina de la lista el elemento de la posicion indicada
  Entrada:Lista,posicion
  Salida:lista
  PreCD:Lista inicializada y posicion indicada valida
  PostCD:Las posiciones de los elementos posteriores al eliminado de la lista pueden haber variado */

tPosP firstP (tListP P);
/*Objetivo:Devuelve la posicion del primer elemento de la lista
  Entrada:Lista
  Salida:posicion
  PreCD:Lista inicializada y no vacia */

tPosP lastP (tListP P);
/*Objetivo:Devuelve la posicion del ultimo elemento de la lista
  Entrada:Lista
  Salida:posicion
  PreCD:Lista inicializada y no vacia */

tPosP previousP (tPosP p,tListP P);
/*Objetivo:Devuelve la posicion del elemento anterior al de la posicion indicada(o nulo si no la tiene)
  Entrada:Lista,posicion
  Salida:posicion
  PreCD:Lista inicializada y posicion indicada valida */

tPosP nextP (tPosP p,tListP P);
/*Objetivo:Devuelve la posicion del elemento siguiente al de la posicion indicada(o nulo si no la tiene)
  Entrada:Lista,posicion
  Salida:posicion
  PreCD:Lista inicializada y posicion indicada valida */

tItemP getItemP (tPosP p,tListP P);
/*Objetivo:Devuelve el contenido del elemento de la lista de la posicion indicada
  Entrada:Lista,posicion
  Salida:elemento
  PreCD:Lista inicializada y posicion indicada valida */

void updateItemP (tItemP d,tPosP p,tListP* P);
/*Objetivo:Modifica el contenido del elemento de la lista de la posicion indicada
  Entrada:Lista,posicion,elemento
  Salida:lista
  PreCD:Lista inicializada y posicion indicada valida
  PostCD:El orden de los elementos de la lista no se ve modificado*/

tPosP findItemP (tParticipantName d,tListP P);
/*Objetivo:Devuelve la posicion del primer elemento de la lista cuyo nombre sea igual al indicado o nulo si no existe
  Entrada:Lista,nombre_participante
  Salida:posicion
  PreCD:Lista inicializada */

#endif
