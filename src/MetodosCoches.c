/*
 ============================================================================
 Name        : MetodosCoches.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

struct Coche {

    char matricula[7];
    char marca[50];
    char modelo[50];
    int cv;
};


int buscar(struct Coche taller[], char matricula[]){

	int i=0;
do
    {
    if (strcasecmp((matricula), taller[i].matricula)==0) return i;
    }
 	 	 while(++i<10);

    return -1;
}

int insertar(struct Coche coche, struct Coche taller[]){

    if (buscar(taller, coche.matricula) != -1) return 1;
    	else {
    		int i;
    			for (i = 0; i < 10; i++)
    			{
    if (strcasecmp(taller[i].matricula, "0") == 0)
       {
                taller[i]=coche;
                return 0;
            }
        }
    }
}

//INSERTAR

void ordenar(struct Coche taller[]){

    struct Coche aux;

    int i;
    for (i=0; i < 9; i++)
    {
        int j;
        for (j=i+1;j<10; j++)
        {
            if (strcasecmp(taller[i].matricula, taller[j].matricula) > 0)
            {
                aux = taller[i];
                taller[i] = taller[j];
                taller[j] = aux;
            }

        }
    }
}

int main(void) {

    setbuf(stdout, NULL);

    struct Coche taller[10];
    struct Coche aux;

    int i;
    for (i = 0; i < 10; i++)
    {
       strcpy(taller[i].matricula, "_");
    }

    int caso = 0;
    char CasoEscogido[30];

    do {

        printf("1. Dar de ALTA al coche\n2. Dar de BAJA al coche\n3. Imprimir COCHE seleccionado\n4. ordenar nuestro TALLER\n"
            "5. Salir de la app\n");

        printf("\nSelecciona la opcion que desee: \n");
        scanf("%d", &caso);
        setbuf(stdin, NULL);

        switch(caso)
        {
            case 1:
                printf("Introduce la matricula\n");
                gets(aux.matricula);
                printf("Introduce la marca\n");
                gets(aux.marca);
                printf("Introduce el modelo\n");
                gets(aux.modelo);
                printf("Introduce los cv\n");
                scanf("%d", &aux.cv);
                setbuf(stdin, NULL);
                printf("%d", insertar(aux, taller));
                break;
            case 2:
                printf("Introduce la matricula\n");
                scanf("%s", &CasoEscogido);
                printf("%d", borrar(taller, CasoEscogido));
                break;
            case 3:
                printf("Introduce la matricula\n");
                scanf("%s", &CasoEscogido);
                imprimir(taller,CasoEscogido);
                break;
            case 4:
                ordenar(taller);

                for (i = 0; i < 10; i++)
                {
                    printf("%s\n", taller[i].matricula);
                }
                break;
            case 5:
                break;
            default:
                break;
        }


    } while (caso != 5);

    return (EXIT_SUCCESS);
}
