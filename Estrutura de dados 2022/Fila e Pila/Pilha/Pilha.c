#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define t 5

struct livro{
	char nome[100];
	char autor[100];
	int cod;
};

struct livro_Pilha{
	 	int ini;
	 	int fim;
	 	struct livro dados[t];	 	
	 	
	 };
struct livro_Pilha cadastro;

void push_livro();	
void pop_livro();
void achar_livro();


FILE * arq;

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	printf("\nCarregando arquivos\n:");
	sleep(0);
	system("cls");
		
	int i=0;
	
		
	while(i!=4){
		printf("    *****Bem vindo ao push/pop livros****\n\n");
		printf("\nQuantidade na pilha: ");
		conta_livro();
		printf("\nEscolha a ação deseja:\n\n");
		printf("\n1-Guardar livro\n2-Retirar livro\n3-Achar livro\n4-Sair\n");
		scanf("%d", &i);
		
		switch(i){
			
			case 1:
				system("cls");
				push_livro();				
				system("pause");
				system("cls");
			break;	
						
			case 2:
				system("cls");
				pop_livro();
				system("pause");
				system("cls");
			break;
			
			case 3:
				system("cls");
				achar_livro();
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
				system("cls");
			
	
		}
		
	}
	
	 
	return 0;
}


void push_livro(){
	printf("    *****Cadastrando Livros****\n");
	
	if(cadastro.fim==t){
		printf("\nA pilha está lotada.\n");
		system("pause");
		

	}
	else{
		
		printf("\n\nQual o nome do Livro\n:");
		scanf("%s",cadastro.dados[cadastro.fim].nome);
		fflush(stdin);
		printf("\nNome do autor\n:");
		scanf("%s", cadastro.dados[cadastro.fim].autor);
		fflush(stdin);
		cadastro.dados[cadastro.fim].cod=cadastro.fim;
		printf("\nCódigo,%d, gerado com sucesso!\n\n",cadastro.dados[cadastro.fim].cod=cadastro.fim);
		cadastro.fim++;	
		system("pause");
		system("cls");
		}
	}
	


void pop_livro(){
	
	printf("    *****Retirando Livros****\n");
	if(cadastro.ini==cadastro.fim){
		printf("\nA pilha está vazia!!\n\n");
	}
	else{
		printf("\n%d\n",cadastro.dados[cadastro.fim-1].cod=cadastro.fim);		
		cadastro.dados[cadastro.fim-1].cod=0;
		strcpy(cadastro.dados[cadastro.fim].nome, "");
		strcpy(cadastro.dados[cadastro.fim].autor, "");
		cadastro.fim--;
		
	}
		
};

void conta_livro() {
	
	int i;
	printf("[ ");
	for(i=0;i<t;i++){
		printf("%d", cadastro.dados[i].cod);
	}
	printf(" ]\n\n");
};

void achar_livro(){
	int i;
	
	arq=fopen("Database.dat", "a+b");
	if(arq==NULL){	
		system("cls");
		printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\BANCO DE DADOS\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
		printf("\nO arquivo não foi aberto!\n***************************ERROR*************");
	}
		else {
				
			for(i=0;i<t;i++){
				printf("\n[ ");
				printf("%s, ", cadastro.dados[i].nome);
				printf("%s, ", cadastro.dados[i].autor);
				printf("%d", cadastro.dados[i].cod);
				printf(" ]\n");
			}		
	}
	fclose(arq);
	}
	


