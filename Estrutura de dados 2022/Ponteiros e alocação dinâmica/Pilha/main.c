#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include <time.h>

//Definindo a estrutura da pilha
struct no {
	int dado;
	struct no *prox;
};
typedef struct no *no_ptr;

//Definindo variáveis
int op;
no_ptr pilha;


//Prototipação
void menu_mostrar();
void menu_selecionar(int op);
void pilha_mostrar(no_ptr pilha);
void pilha_inserir(no_ptr pilha);
void pilha_remover(no_ptr pilha);

//Função principal

int main(int argc, char *argv[]) {
	srand(time(NULL));
	op=1;
	//primeiro nó
	pilha = (no_ptr) malloc(sizeof(no_ptr));
	pilha->dado=0;
	pilha->prox=NULL;
	
	
	while (op !=0){
		system("cls");
		menu_mostrar();
		scanf("%d", &op);
		menu_selecionar(op);
	}
system("Pause");
	
	return 0;
}

//Mostra o menu de opções
void menu_mostrar(){
	pilha_mostrar(pilha);
	printf("\n\nEscolha uma das opcoes:\n");
	printf("1 - Inserir no final da pilha\n");
	printf("2 - Remover no final da pilha\n");
	printf("0 - Sair\n\n");
}

//Executa a opção escolhida no menu
void menu_selecionar(int op){
	switch (op){
		case 1:
			pilha_inserir(pilha);
		break;
		case 2:
			pilha_remover(pilha);
		break;
	}
}

void pilha_mostrar(no_ptr pilha){
	system("cls");
	printf("Pilha: ");
	while(pilha->prox !=NULL){
		printf("%d, ", pilha->dado);
		pilha=pilha->prox;
	}
	printf("%d, ", pilha->dado);
	
}
void pilha_inserir(no_ptr pilha){
	while(pilha->prox !=NULL){
		pilha=pilha->prox;
	}
	pilha->prox=(no_ptr) malloc(sizeof(struct no));
	pilha= pilha->prox;
	pilha->dado=rand()%100;
	pilha->prox=NULL;
}

void pilha_remover(no_ptr pilha){
	no_ptr atual;
	atual=(no_ptr) malloc(sizeof(struct no));
	while(pilha->prox != NULL){
		atual=pilha;
		pilha=pilha->prox;
	}
	atual->prox=NULL;
			
}

