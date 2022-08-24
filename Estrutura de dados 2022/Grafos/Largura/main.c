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

void buscaEmLargura(struct str_no g[], int inicio, int alvo);


int main(int argc, char *argv[]) {
	
	return 0;
}

void buscaEmLargura(struct str_no g[], int inicio, int alvo){
	int fila[MAXV]; //fila
	bool visitado[MAXV]; //nós visitados
	int indice = 0; //controle da fila
	bool achou = false; //flag (não visitados)
	int corrente = inicio;
	struct str_no *ptr;
	int i;
	printf("=-=-=-= Busca em Largura =-=-=-= \n");
	//Marcando os nós como ‘não visitados’.
	for(i=0; i < MAXV; i++)
		visitado[i] = false;
		//Partindo do primeiro vértice.
		printf("VISITANDO: %d. \n", corrente);
		visitado[corrente] = true;
		fila[indice] = corrente;
		indice++;
	while(true){
		//Visitar os nós adjacentes ao vértice corrente
		for(ptr = g[corrente].proximo; ptr != NULL; ptr =
		ptr->proximo){
		//Caso corrente ainda não tenha sido visitado:
		corrente = ptr->id;
		if(!visitado[corrente]){
		//Enfileira e marca como visitado.
		printf("VISITANDO: %d. \n", corrente);
		if(corrente == alvo)
		{
		printf("Alvo encontrado!\n\n\n");
		return;
		}
		visitado[corrente] = true;
		fila[indice] = corrente;
		indice++;
		}
		}
		//Caso a fila não esteja vazia:
		if(indice!=0)
		{
			//Atualizando vértice corrente.
		corrente = fila[0];
		//Desenfileirando o primeiro vértice.
		for(i=1;i<indice+1;i++)
		fila[i-1]=fila[i];
		indice--;
		}
		else
		{
		//Não há mais vértices para visitar.
		printf("Encerrando busca.\n");
		break;
		}
		}
	return;
	}
