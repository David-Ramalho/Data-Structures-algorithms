//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//Número máximo de vértices
#define MAXV 8

//Estrutura de um nó
typedef struct str_no {
int id;
struct str_no *proximo;
} str_no;

//Grafo
struct str_no grafo[MAXV];

void buscaEmProfundidade(struct str_no g[], int inicio, int
alvo);



int main(int argc, char *argv[]) {
	

	return 0;
}


void buscaEmProfundidade(struct str_no g[], int inicio, int
alvo){
	int pilha[MAXV]; //pilha
	bool visitado[MAXV]; //nós visitados
	int indice = 0; //índice do topo da pilha
	bool achou = false; //flag de controle (não visitados)
	int corrente = inicio;
	struct str_no *ptr;
	int i;
	printf("=-=-=-= Busca em Profundidade =-=-=-=\n");
	//Marcando os nós como ‘não visitados’.
	for(i=0; i < MAXV; i++){
	visitado[i] = false;
	}
	while(true){
	//Nó corrente não visitado? Marque como visitado.
	//Empilhe o nó corrente.
	if(!visitado[corrente]){
	printf("VISITANDO: %d. \n", corrente);
	if(corrente == alvo)
	{
	printf("Alvo encontrado!\n\n\n");
	return;
	}
	visitado[corrente] = true;
	pilha[indice] = corrente;
	indice++;
	}
	//Buscando por nós adjacentes, não visitados.
	achou = false;
	for(ptr = g[corrente].proximo; ptr != NULL;
	ptr = ptr->proximo){
	if(!visitado[ptr->id]){
	achou = true;
	break;
	}
	}
	if(achou){
	//Atualizando o nó corrente.
	corrente = ptr->id;
	}
	else{
	//Não há vértices adjacentes não visitados.
	//Tentando desempilhar o vértice do topo.
	indice--;
	if(indice==-1){
	//Não há mais vértices não visitados.
	printf("Encerrando a busca. \n");
	break;
	}
	corrente = pilha[indice-1];
	}
	}
	return;
	}
