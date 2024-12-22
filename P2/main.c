/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Miguel Marcos Trillo LOGIN 1: miguel.mt
 * AUTHOR 2: Adrián Edreira Gantes LOGIN 2: adrian.gantes
 * GROUP: 1.4
 * DATE: 28 / 04 / 23
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "jury_list.h"

#define MAX_BUFFER 255

void printWinner (tPosP pos, int votes, bool location, tItemJ item);

void printStats (tItemJ item);

bool create (char *param1, char *param2, tListJ *J){

    if (findItemJ(param1,*J)==NULLJ){  //si no existe el jurado en la lista
        tItemJ item;
        tListP P;
        createEmptyListP (&P);  //inicializamos la lista de los participantes

        strcpy (item.juryName, param1);  //copiamos el nombre del jurado en param1
        item.totalVoters = atoi(param2); //numero total de votos del jurado
        item.validVotes = 0;  //votos validos a 0
        item.nullVotes = 0;  //votos nulos a 0
        item.participantList = P;  //lista de participantes

        if (insertItemJ (item,J)){ //si se puede añadir a la lista devuelve true
            return true;
        }
    }
    return false;  //si ya existe el jurado o no se puede añadir a la lista devuelve false
}

bool new ( char *param2, char *param3, tListJ *J, tPosJ j){

    if (!isEmptyListJ(*J) && (findItemP(param2, J->dataJ[j].participantList) == NULLP)){
        //si la lista del jurado no esta vacia y no se encuentra el participante a añadir

        tItemP item;

        strcpy(item.participantName, param2);  //copiamos el nombre del participante en param2
        item.numVotes = 0; //numero de votos a 0
        if (strcmp(param3, "eu") == 0) {
            item.EUParticipant = true; //si el participante pertenece a la eu devuelve true
        } else {
            item.EUParticipant = false; //sino devuelve false
        }

        if (insertItemP(item, &J->dataJ[j].participantList)) {  //si se puede añadir a la lista devuelve true
            printf("* New: jury %s participant %s location %s\n", J->dataJ[j].juryName, item.participantName,
                   item.EUParticipant ? "eu" : "non-eu");
            return true;
        }
    }
    return false;  //si no se cumple alguna de las condiciones anteriores devuelve false

}

void vote (char *param1,char *param2, tListJ *J){

    tPosJ itemPos = findItemJ(param1, *J);  //guardamos la posicion del jurado
    tItemJ item = getItemJ(itemPos, *J);  //guardamos el item del jurado en esa posicion

    if (!isEmptyListJ(*J) && itemPos!=NULLJ && (item.totalVoters > item.validVotes + item.nullVotes)){
        //si la lista del jurado no esta vacia, existe el jurado y los votos totales son mayores a los votos validos+nulos

        tPosP partPos = findItemP(param2, item.participantList);  //guardamos la posicion del participante

        if(partPos != NULLP){  //si existe el participante

            tItemP part = getItemP(partPos, item.participantList);  //guardamos el item del participante
            part.numVotes++;  //aumentamos en uno sus votos
            updateItemP(part, partPos, &item.participantList); //se actualiza el participante con su nuevo voto
            printf("* Vote: jury %s participant %s location %s numvotes %d\n", param1, part.participantName,
                   part.EUParticipant ? "eu" : "non-eu", part.numVotes);
            item.validVotes++;  //aumentamos en uno los votos validos del jurado
            updateItemJ(item, itemPos, J);  //actualizamos el jurado con su nuevo voto valido

        }else{  //si el participante no esta en la lista del jurado
            printf("+ Error: Vote not possible. Participant %s not found in jury %s. NULLVOTE\n", param2, param1);
            item.nullVotes++;  //sumamos uno a los votos nulos del jurado
            updateItemJ(item, itemPos, J);  //actualizamos el jurado con su nuevo voto nulo
        }
    }else{  //si no se cumplio ninguna de las condiciones
        printf("+ Error: Vote not possible\n");
    }

}

void stats (tListJ *J){
    tItemJ item;

    for (tPosJ j = firstJ(*J); j!=NULLJ; j = nextJ(j,*J)){  //recorremos la lista de jurados
        item = getItemJ(j, *J);  //obtenemos el jurado
        printf ("Jury %s\n",J->dataJ[j].juryName);
        if (!isEmptyListP(item.participantList)){  //si la lista de participantes no esta vacia
            printStats (item);  //imprimimos sus estadísticas
        }else{  //sino no existen
            printf ("No participants\n");
        }
        printf ("Nullvotes %d\n", item.nullVotes);  //imprimimos el numero de votos nulos
        printf ("Participation: %d votes from %d voters (%.2f%%)\n", item.validVotes + item.nullVotes, item.totalVoters,
                (((float)item.validVotes + (float)item.nullVotes)/(float)item.totalVoters)*100);  //imprimimos la participacion del jurado
        printf ("\n");
    }
}

void disqualify (char *param1, tListJ *J){
    tItemJ item;
    tItemP part;
    tPosP partPos;

    for (tPosJ j = firstJ(*J); j!= NULLJ ; j = nextJ(j,*J)){  //recorremos la lista de jurados
        item = getItemJ(j, *J);  //obtenemos el jurado
        partPos = findItemP(param1, item.participantList);  //obtenemos la posicion de los participantes del jurado
        printf ("Jury %s\n", J->dataJ[j].juryName);
        if (partPos != NULLP){  //si existe el participante
            part = getItemP(partPos, item.participantList);  //obtenemos el participante
            item.validVotes -= part.numVotes;  //los votos validos del jurado decrementan 1
            item.nullVotes += part.numVotes;  //los votos nulos del jurado incrementan 1
            deleteAtPositionP(partPos, &item.participantList);  //borramos el participante
            updateItemJ(item, j, J);  //actualizamos la lista del jurado
            printf ("Participant %s disqualified\n", param1);
        }else{  //si no existe este participante en ese jurado
            printf ("No participant %s\n",param1);
        }
        printf ("\n");
    }
}

bool clean (tListJ *J){
    tItemJ item;
    tPosP p;
    bool confirm = false;  //negamos que se borro algún jurado

    for (tPosJ j = firstJ(*J); j!= NULLJ ; j = nextJ(j,*J)){  //recorremos la lista de jurados
        item = getItemJ(j, *J);  //obtenemos el jurado
        if (item.validVotes == 0){  //si los votos validos es igual a 0
            while (p!= NULLP){ //recorremos los participantes hasta que no quede ninguno;
                //borramos los participantes del jurado antes de borrar el jurado para cumplir su precondición
                deleteAtPositionP( p, &item.participantList); //borramos el participante
                p = previousP(p, item.participantList); //movemos p a la posición anterior porque al eliminar una posición la lista se reorganiza
            }
            printf ("* Remove: jury %s\n", item.juryName);
            deleteAtPositionJ(j,J);  //eliminamos el jurado
            j = previousJ(j, *J);  //movemos j a la posición anterior porque al eliminar una posición la lista se reorganiza
            confirm = true;  //afirmamos que se borro algún jurado
        }
    }
    return confirm;
}

void winners (tListJ *J){
    tItemJ item;
    tItemP part;
    tPosP eu=NULLP, neu=NULLP;
    int maxeu, maxneu;

    for (tPosJ j = firstJ(*J); j!= NULLJ ; j = nextJ(j,*J)){  //recorremos la lista de jurados
        eu=NULLP, neu=NULLP, maxeu=0, maxneu=0;
        item = getItemJ(j, *J);  //obtenemos el jurado
        printf ("Jury %s\n",J->dataJ[j].juryName);
        for (tPosP p = firstP(item.participantList); p != NULLP; p = nextP(p, item.participantList)) {  //recorremos la lista de participantes
            part = getItemP(p, item.participantList);  //obtenemos el item del participante

            if (part.EUParticipant && part.numVotes >= maxeu) {  //si pertenece a la eu y los votos del participante son mayores que el maximo de eu
                eu = (part.numVotes > maxeu) ? p : NULLP;
                //la posicion sera la del actual maximo si, y solo si, su numero de votos es mayor al maximo anterior
                // sino habra un empate y diremos que la posición es nula
                maxeu = part.numVotes;  //el maximo de eu sera el actual
            }
            if (!part.EUParticipant && part.numVotes >= maxneu){  //si no pertenece a la eu y los votos del participante son mayores que el maximo de non-eu
                neu = (part.numVotes > maxneu) ? p : NULLP;
                //la posicion sera la del actual maximo si, y solo si, su numero de votos es mayor al maximo anterior
                // sino habra un empate y diremos que la posición es nula
                maxneu = part.numVotes;  //el maximo de non-eu sera el actual
            }
        }

        printWinner (eu, maxeu, true, item);  //imprimimos el participante que pertenece a eu
        printWinner (neu, maxneu, false, item);  //imprimimos el participante que no pertenece a eu

        printf ("\n");
    }
}

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, tListJ *J) {

    printf("********************\n");

    switch (command) {
        case 'C':
            printf("%s %c: jury %s totalvoters%s\n", commandNumber, command, param1, param2);

            if (create(param1,param2, J)){  //si se puede crear el jurado
                printf ("* Create: jury %s totalvoters %s\n",param1,param2);
            }else{
                printf ("+ Error: Create not possible\n");
            }

            break;
        case 'N':
            printf("%s %c: jury %s participant %s location %s\n", commandNumber, command, param1, param2, param3);

            if (!new(param2,param3, J, findItemJ (param1,*J))){  //si no se pudo añadir participante
                printf("+ Error: New not possible\n");
            }

            break;
        case 'V':
            printf("%s %c: jury %s participant %s\n", commandNumber, command, param1, param2);

            vote (param1, param2, J);

            break;
        case 'D':
            printf("%s %c: participant %s\n", commandNumber, command, param1);

            if(isEmptyListJ(*J)){  //si la lista esta vacia
                printf("+ Error: Disqualify not possible\n");
            }else{
                disqualify(param1, J);
            }

            break;
        case 'S':
            printf("%s %c:\n", commandNumber, command);

            if (isEmptyListJ(*J)){  //si la lista esta vacia
                printf ("+ Error: Stats not possible\n");
            }else{
                stats(J);
            }
            break;
        case 'R':
            printf("%s %c:\n", commandNumber, command);

            if (isEmptyListJ(*J) || !clean(J)){  //si la lista esta vacia o no se pudo eliminar a algún jurado
                printf ("+ Error: Remove not possible\n");
            }

            break;
        case 'W':
            printf("%s %c:\n", commandNumber, command);

            if (isEmptyListJ(*J)){  //si la lista esta vacia
                printf ("+ Error: Winners not possible\n");
            }else{
                winners(J);
            }
            break;
        default:
            break;
    }
}

void readTasks(char *filename) {
    tListJ J;
    createEmptyListJ(&J);  //inicializamos la lista de los jurados

    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, param3, &J);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }

}

int main(int nargs, char **args) {

    char *file_name = "create.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
#ifdef INPUT_FILE
        file_name = INPUT_FILE;
#endif
    }

    readTasks(file_name);

    return 0;
}

void printWinner(tPosP pos, int votes, bool location, tItemJ item) {
    if (pos != NULLP && votes != 0) {  //si la posicion no es nula y los votos son distintos de 0, imprimimos el ganador
        tItemP part = getItemP(pos, item.participantList);  //obtenemos al participante
        printf("Location %s: Participant %s numvotes %d\n", location ? "eu" : "non-eu", part.participantName, votes);
    } else {  //si no imprimimos que no hay ganador
        printf("Location %s: No winner\n", location ? "eu" : "non-eu");
    }
}

void printStats (tItemJ item) {
    tItemP part;

    for (tPosP p = firstP(item.participantList); p != NULLP ; p = nextP(p, item.participantList)) { //recorremos la lista de participantes
        part = getItemP(p, item.participantList);  //obtenemos al participante
        if (item.validVotes==0){  //si los votos validos son 0
            printf("Participant %s location %s numvotes 0 (0.00%%)\n", part.participantName,
                   part.EUParticipant ? "eu" : "non-eu"); //imprimimos el participante, localizacion y las estadisticas a 0
        }else{
            printf("Participant %s location %s numvotes %d (%.2f%%)\n", part.participantName,
                   part.EUParticipant ? "eu" : "non-eu", part.numVotes,
                   ((float)part.numVotes/(float)item.validVotes)*100);
                   //imprimimos el participante, localizacion y sus estadísticas como la division entre los votos del participante entre los votos validos del jurado
        }
    }
}