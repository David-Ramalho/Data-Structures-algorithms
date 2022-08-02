#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include <time.h>

int main() {
    	
	int x;
	int *a;
	int *b;
	int i;
	
	printf("\nQual o tamanho do vetor?\n");
	scanf("%d", &x);
	
	a=(int*)malloc(sizeof(int)*(x));
	b=(int*)malloc(sizeof(int)*(x));
	
	for(i=0;i<x;i++){
		a[i]=pow(2,i);
		printf("\nPosição %d:\n%d", i,a[i]);
	}
	printf("\n*********\n");
    for(i=0;i<x;i++){
    	b[i]= pow(3,i);
    	printf("\nPosição %d:\n%d", i,b[i]);
    	
	}

	printf("\n\nSucesso!!\n");
	return(0);
}
