#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include <time.h>

//Definindo a estrutura da fila
struct noFila{
	int dado;
	struct noFila *prox;
};

//Definindo variáveis
int op;
typedef struct noFila* no_fila;
no_fila fila;

//Prototipação
void menu_mostrar();
void menu_selecionar(int op);
void fila_mostra(no_fila fila);
void fila_inserir(no_fila fila);
void fila_remover(no_fila fila);

//Função principal
int main(int argc, char *argv[]) {
//Inicializando máquina de números randômicos
	srand(time(NULL));
	op = 1;
//Criando o primeiro nó da fila
	fila =(no_fila) malloc(sizeof(struct noFila));
	fila->dado=0;
	fila->prox=NULL;
	while(op!=0){
		system("cls");
		fila_mostra(fila);
		menu_mostrar();
		scanf("%d", &op);
		menu_selecionar(op);
	}	
	system("Pause");
	return 0;
}

void menu_mostrar(){
	
	printf("\n\nEscolha uma das opcoes:\n");
	printf("1 - Inserir no final da fila\n");
	printf("2 - Remover no inicio da fila\n");
	printf("0 - Sair\n\n");
}

void menu_selecionar(int op){
	switch (op){
		case 1:
			 fila_inserir(fila);
		break;
		case 2:
		fila_remover(fila);
	
		break;
	}
}

void fila_mostra(no_fila fila){
	system("cls");
	printf("Fila: ");
	while(fila->prox !=NULL){
		printf("%d ", fila->dado);
		fila=fila->prox;
	}
	printf("%d, ", fila->dado);
}

void fila_inserir(no_fila fila){
	while(fila->prox !=NULL){
		fila=fila->prox;
	}
	fila->prox= (no_fila) malloc(sizeof(struct noFila));
	fila=fila->prox;
	fila->dado=rand()%100;
	fila->prox=NULL;
}

void fila_remover(no_fila fila){
	no_fila atual;
	atual =(no_fila) malloc(sizeof(struct noFila));
	atual=fila;
	if(fila->prox !=NULL){
		fila=fila->prox;
		atual->prox=fila->prox;
	}
}
