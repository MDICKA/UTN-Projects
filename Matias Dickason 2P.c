#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3 // CANTIDAD DE CANCIONES N PUEDE VARIAR.

struct CANCION {
	char NOMBRE[50];
	char AUTOR[50];
	int REPRODUCCIONES[12];
};

void CARGAR (struct CANCION[]);
void IMPRIMIR_AUTORES(struct CANCION[]);
void AUTOR_TOTALES (struct CANCION[], char[]);

int main () {

    struct CANCION TEMAS[N];
    char AUBUS [50];


    CARGAR(TEMAS);
    IMPRIMIR_AUTORES(TEMAS);


    printf("\n\nINGRESE EL AUTOR A BUSCAR: ");
    gets(AUBUS);

    AUTOR_TOTALES(TEMAS, AUBUS);

    printf("\n\n");

}

void CARGAR (struct CANCION PTEMAS[]){

    int I, J;

    printf("\n\t\t *** CARGA DE CANCIONES *** \n\n");

    for(I=0; I<N; I++) {
        printf("INGRESE EL NOMBRE DE LA CANCION: ");
        gets(PTEMAS[I].NOMBRE);
        printf("INGRESE EL AUTOR DE LA CANCION: ");
        gets(PTEMAS[I].AUTOR);

        for(J=0; J>12; J++)
            PTEMAS[I].REPRODUCCIONES[J] = 20 + rand() % 80;
    }
}

void IMPRIMIR_AUTORES(struct CANCION PTEMAS[]) {

    int I, J, FLAG, POS = 0;
    char AUX [N][50];

    printf("\n\t\t *** IMPRESION DE AUTORES *** \n\n");

    for(I=0; I<N; I++) {
        FLAG = 0;
        for(J=0; J<=POS; J++)
            if(strcmp (PTEMAS[I].AUTOR, AUX[J]) == 0)
                FLAG = 1;

            if (FLAG == 0) {
                strcpy(AUX[POS], PTEMAS[I].AUTOR);
                POS++;
            }
    }

    for(I=0; I<POS; I++)
        printf("\n %-10s", AUX[I]);
}

void AUTOR_TOTALES (struct CANCION PTEMAS[], char PAUBUS []) {

    int I, J, CONT = 0;

    for(I=0; I<N; I++)
        if (strcmp (PTEMAS[I].AUTOR, PAUBUS) == 0)
                for(J=0; J<12; J++)
                    CONT = CONT + PTEMAS[I].REPRODUCCIONES[J];

    printf("\n\nEL AUTOR %s TUVO: %d REPRODUCCIONES TOTALES", PAUBUS, CONT);
}
