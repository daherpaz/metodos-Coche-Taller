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


	struct Coche{
		char matricula[7];
		char marca [50];
		char modelo [50];
		int cv;
	};



	int size (struct Coche taller[]){
		return sizeof(taller)/sizeof(taller[0]);
	}


	int buscar (struct Coche taller[], char matricula[] ){
		 int i = 0;
		do{
				if(strcasecmp(matricula, taller[i].matricula) == 0) return i;
			}
			while(++i<size(taller));
		}
		
		
		void ordenar (struct Coche taller[]) {
		struct Coche aux;
		int i = 0;
		int j = 0;
		for (; i<size(taller) - 1; i++) {
			for (;j<size(taller); ++j){
				if (taller[i].matricula, taller [j].matricula == 1){
					aux = taller[i];
					taller[i] = taller [j];
					taller[j] = aux;
				}
			}
		}
	}



int main(void) {
	return EXIT_SUCCESS;
}
