/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Miguel Marcos Trillo LOGIN 1: miguel.mt
 * AUTHOR 2: Adrián Edreira Gantes LOGIN 2: adrian.gantes
 * GROUP: 1.4
 * DATE: 16 / 03 / 23
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define MAX_BUFFER 255

#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif
#ifdef STATIC_LIST
#include "static_list.h"
#endif

bool exist_item(tList L, char a[NAME_LENGTH_LIMIT]){ //funcion booleana para saber si existe o no un item en la lista
    tPosL p;
    tItemL item;

    if(isEmptyList(L)){
        return false; // si la lista esta vacia devuelve false
    }else{
        for (p=first(L); (p!=LNULL); p=next(p,L)){
            item=getItem(p,L);
            if(strcmp(item.participantName, a)==0){
                return true; //si uno o varios items de la lista coincide con el item a buscar devuelve true
            }
        }
        return false; //si no esta devuelve false
    }
}

void new (char *param1, char *param2, tList *L){
    tItemL item;

    strcpy(item.participantName,param1);  //copiamos el nombre del participante en param1
    item.numVotes=0; //numero de votos a 0
    if (strcmp(param2,"eu")==0){
        item.EUParticipant=true; //si el participante pertenece a la eu devuelve true
    }else{
        item.EUParticipant=false; //sino devuelve false
    }

    if (exist_item(*L,param1)!=true && (insertItem (item,LNULL,L)==true)){ //si se puede añadir a la lista devuelve el nombre y pais del participante
        printf("* New: participant %s location %s\n",param1, param2);
    }else{ //sino devuelve error, por espacio o por existencia del param1
        printf("+ Error: New not possible\n");
    }
}

void vote (char *param1, tList *L, int *cont_null, int *total_votes){
    tItemL item;

    if ((!isEmptyList(*L)) && exist_item(*L,param1)==true){ //si la lista no esta vacia y existe el participante
        item = getItem(findItem(param1,*L),*L); //seleccionamos ese participante
        item.numVotes++; //se suma un voto al participante
        updateItem(item,findItem(param1,*L),L); //se actualiza el participante con su nuevo voto
        printf("* Vote: participant %s location %s numvotes %d\n", item.participantName,item.EUParticipant ? "eu":"non-eu" ,item.numVotes );
    }else{ //si no existe el participante o la lista esta vacia
        (*cont_null)++; //se suma un voto a nulo
        printf("+ Error: Vote not possible. Participant %s not found. NULLVOTE\n",param1);
    }
    (*total_votes)++;
}

void disqualify(char *param1, tList *L, int *cont_null){
    tItemL item;

    if ((!isEmptyList(*L)) && exist_item(*L,param1)==true){ //si la lista no esta vacia y existe el participante
        item = getItem(findItem(param1,*L),*L); //seleccionamos ese participante
        *cont_null += item.numVotes; //se añaden sus votos al contador de nulos
        printf("* Disqualify: participant %s location %s\n", item.participantName, item.EUParticipant ? "eu":"non-eu");
        deleteAtPosition(findItem(param1,*L),L); //borramos el participante de la lista
    }else{ //sino dara error
        printf("+ Error: Disqualify not possible");
    }
}

void stats (char *param1, tList *L, int *cont_null, int *total_votes){
    tItemL item;
    tPosL p;

    if (*total_votes == 0 || *total_votes == *cont_null) { //si los votos totales son 0 o iguales a los votos nulos
        //como los votos totales son 0 son todos pertenecientes a nulos sabemos q ningún participante tiene votos
        //por eso imprimiremos directamente sus votos a cero y su porcentaje de votos tambien a cero
        //ya q dividir entre cero da infinito y ahorramos procesamiento
        for (p = first(*L); p != LNULL; p = next(p, *L)) { //recorremos la lista para imprimirla
            item = getItem(p, *L); //obtenemos los datos del participante
            printf("Participant %s location %s numvotes 0 (0.00%%)\n", item.participantName,
                   item.EUParticipant ? "eu" : "non-eu"); //imprimimos el participante y sus estadísticas
        }
    }else{ //sino podemos hacer la división de los votos válidos obteniendo un porcentaje válido
        for(p=first(*L); p!=LNULL; p=next(p,*L)){ //recorremos la lista para imprimirla
            item = getItem(p, *L); //obtenemos los datos del participante
            printf("Participant %s location %s numvotes %d (%.2f%%)\n", item.participantName,
                   item.EUParticipant ? "eu":"non-eu", item.numVotes,
                   ((float) item.numVotes/((float)*total_votes-(float)*cont_null))*100);//imprimimos el participante y sus estadísticas
                   //restamos a los votos totales los votos nulos, pues no intervienen a la hora de determinar un ganador.
        }
    }
    printf("Null votes %d\n", *cont_null); //devuelve los votos nulos
    printf("Participation: %d votes from %s voters (%.2f%%)\n", *total_votes,
           param1, ((float)*total_votes/atof(param1))*100); //devuelve los datos de participación del jurado
}

void processCommand(char *commandNumber, char command, char *param1, char *param2, tList *L, int start, int *cont_null, int *total_votes) {

    printf("********************\n\n");

    switch (command) {
        case 'N':
            printf("%s %c: participant %s location %s\n", commandNumber, command, param1, param2);

            if(start==0){ //si no han empezado las votaciones
                new(param1, param2, L); //se llama a la función "new"
            }else{ //sino devuelve error
                printf("+ Error: New not possible\n");
            }

            break;

        case 'V':
            printf("%s %c: participant %s\n", commandNumber, command, param1);

            vote(param1, L, cont_null, total_votes); //se llama a la función "vote"

            break;

        case 'D':
            printf("%s %c: participant %s\n", commandNumber, command, param1);

            disqualify(param1, L, cont_null); //se llama a la función "disqualify"

            break;

        case 'S':
            printf("%s %c: totalvoters %s\n", commandNumber, command, param1);

            if(isEmptyList(*L)==true){ //si está vacía devuelve error
                printf("+ Error: Stats not possible");
            }else {
                stats(param1, L, cont_null, total_votes); //sino llama a la función "stats"
            }

            break;

        default:
            break;
    }
}

void readTasks(char *filename, tList *L) {
    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];
    int start=0; //creamos una variable "booleana" para determinar si la votación ha iniciado
    int cont_null=0, total_votes=0; //inicializamos el contador de nulos y el de votos totales a 0


    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {

            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);

            if (strcmp(command,"V")==0){ start = 1;} //si el comando es "Vote", la votación ha iniciado


            processCommand(commandNumber, command[0], param1, param2, L, start, &cont_null, &total_votes); //enviamos a mayores la lista y las variables start, cont_null y total_votes
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}

int main(int nargs, char **args) {
    tList L; //nombre de la lista
    createEmptyList(&L); //se crea una lista vacia

    char *file_name = "vote.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }

    readTasks(file_name, &L);

    return 0;
}






