#include <stdio.h>
#include <stdlib.h>
#define max 10

int tam=0;
int grafo[max];
int mat[max][max];
int op=1;

//Prototipação:
int grafo_tam();

 

int main(int argc, char *argv[]) {	
	printf("                      ***Welcome to the graphs concept program***\n\n");
	
	while(tam <=0 || tam>max){
		tam=grafo_tam();
		
		if(tam<=0 || tam >max){
			system("cls");
			printf("Escolha um valor entre 1 e %d\n\n", max);
		}
		else{
			
		}
	}
	
	return 0;
}

//Define o número de vértices do Grafo
int grafo_tam(){
	int tam;
	printf("Escolha a quantidade de vertices do grafo: ");
	scanf("%d", &tam);
	return tam;
}
