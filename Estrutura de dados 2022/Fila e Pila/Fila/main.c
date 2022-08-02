#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#define t 5

struct cliente{
	char nome[100];
	int data;
	int cod;
};
struct fila{
	 	int ini;
	 	int fim;
	 	struct cliente dados[t];
	 };


void conta_fila();
void Entra_fila();
void verifica_fila();
void sai_fila();

time_t mytime;
struct fila senha;

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	printf("\nCarregando arquivos\n:");
	sleep(0);
	system("cls");
	
	int i=0;
	
	
	
	while(i!=4){
		system("cls");
		printf("    *****Bem vindo a Fila****\n\n");
		printf("\nQuantidade na fila: ");
		conta_fila();
		printf("\n\nEscolha a ação deseja:\n");
		printf("\n1-Retire a senha\n2-Verificar fila\n3-Limpar fila\n4-Sair\n\n:");
		scanf("%d", &i);
	
		switch(i){
				
				case 1:
					system("cls");
					Entra_fila();			
					system("pause");
					system("cls");
				break;	
							
				case 2:
					system("cls");
					verifica_fila();
					system("pause");
					system("cls");
				break;
				
				case 3:
					system("cls");
					sai_fila();
					system("pause");
					system("cls");
				break;
				
				case 4:
					system("cls");
					printf("\nPrograma Encerrado\n\n");
					system("pause");
					system("cls");
				break;
				
				default:
					system("cls");
					printf("\nOpção inválida tente novamente\n\n");
					system("pause");
				
		
			}
			
		}
		
		 
		return 0;
	}
	
	void conta_fila(){
		int i;
			printf("[ ");
			for (i = 0; i < t; i++) {				
				printf("%d ", senha.dados[i].cod);
				}
			printf(" ]");
	}
	
	void Entra_fila(){
		
		struct tm tm = *localtime(&mytime);
		if (senha.fim==t){
			printf("\nA fila está cheia, volte outro dia!\n\n");
			system("pause");			
		}
		else{			
			printf("\nNome por gentileza: ");
			scanf("%s",senha.dados[senha.fim].nome);
			printf("\nHora de chegada:\n");
			printf("Data: %d/%d/%d/\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
			printf("Hora: %d:%d:%d\n", tm.tm_hour, tm.tm_min + 1, tm.tm_sec);
			senha.dados[senha.fim].cod=senha.fim+10;
			printf("\nCódigo de atendimento: %d\n\n", senha.dados[senha.fim].cod);			
			senha.fim++;
			mytime= senha.dados[senha.fim].data;
						
		}
		
	}
	
	void verifica_fila(){
			int i;
			
			for (i = 0; i < t; i++) {
				printf("[ ");
				printf("%d- ", senha.dados[i].cod);
				printf("%s ,", senha.dados[i].nome);
				printf("%d", senha.dados[i].data);
				printf("]\n\n");
			}
	}
	
	void sai_fila(){
		if(senha.ini==senha.fim){
			printf("\nFila vazia, mas logo aparece alguém!\n\n");
			system("pause");
		}
		else{
			int i;
			int elemento = senha.dados[senha.fim].cod +10;
			for(i=0;i<t;i++){
				strcpy(senha.dados[i].nome, senha.dados[i+1].nome);
				senha.dados[i].data=senha.dados[i+1].data;
				senha.dados[i].cod=senha.dados[i+1].cod;
			}
			strcpy(senha.dados[senha.fim].nome, "");
			senha.dados[senha.fim].data=0;	
			senha.dados[senha.fim].cod=0;				
			senha.fim--;
			
			printf("\nElemento %d removido\n\n", elemento);
		}
	}


