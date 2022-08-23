#include <stdio.h>
#include <stdlib.h>
#define max 10

int tam=0;
int grafo[max];
int mat[max][max];
int op=1;

//Prototipação:
int grafo_tam();
void grafo_insert();
void grafo_remove();

 

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

void grafo_insert(){
	int num1, num2;
	system("cls");
	printf("Escolha o vertice de origem entre 0 a %d:", tam-1);
	scanf("%d", &num1);
	printf("Escolha o vertice de destino entre 0 a %d:", tam-1);
	scanf("%d", &num2);
	
	if(num1>tam-1 || num2>tam-1|| num1<0 || num2<0){
		printf("\nos valors precisam estar entre 0 e %d\n\n", tam);
		system("pause");
	}
	else{
		mat[num1][num2]=1;
		mat[num2][num1]=1;
	}
}

void grafo_remover(){
		int num1, num2;
	system("cls");
	printf("Escolha o vertice de origem entre 0 a %d:", tam-1);
	scanf("%d", &num1);
	printf("Escolha o vertice de destino entre 0 a %d:", tam-1);
	scanf("%d", &num2);
	
	if(num1>tam-1 || num2>tam-1|| num1<0 || num2<0){
		printf("\nos valors precisam estar entre 0 e %d\n\n", tam);
		system("pause");
	}
	else{
		mat[num1][num2]=0;
		mat[num2][num1]=0;
	}
}
