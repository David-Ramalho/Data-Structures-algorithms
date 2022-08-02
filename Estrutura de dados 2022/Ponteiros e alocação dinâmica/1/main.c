#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include <time.h>

struct infoSema{
    char cor[20];
    int id;
};
	

int main() {
    	
	struct infoSema *Bols;
	int i;
	
	struct infoSema Bola1={"Vermelho2", 1};
	struct infoSema Bola2={"Amarelo", 2};
	struct infoSema Bola3={"Verde", 3};

	
	Bols=&Bola1;	
	printf("\nMemo: %p\n\n", &Bols);
	printf("\nValor da Memo:\nCor:%s\nID: %d\n", (*Bols).cor, (*Bols).id);
	
	Bols=&Bols+sizeof(struct infoSema);	
	printf("\nMemo: %p\n\n", &Bols);
	printf("\nValor da Memo:\nCor: %s\nID: %d\n", (*Bols).cor , (*Bols).id);
    
    

	printf("\n\nSucesso!!\n");
	return(0);
}
