/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Miguel Marcos Trillo LOGIN 1: miguel.mt
 * AUTHOR 2: Adrián Edreira Gantes LOGIN 2: adrian.gantes
 * GROUP: 1.4
 * DATE: 16 / 03 / 23
 */

#ifndef PRO2_2023_P1_TYPES_H
#define PRO2_2023_P1_TYPES_H


#define NAME_LENGTH_LIMIT 25
#include <stdbool.h>

typedef char tParticipantName[NAME_LENGTH_LIMIT];
typedef int tNumVotes;
typedef bool tEUParticipant;

typedef struct tItemL {
    tParticipantName participantName;
    tNumVotes numVotes;
    tEUParticipant EUParticipant;
} tItemL;

#endif //PRO2_2023_P1_TYPES_H
