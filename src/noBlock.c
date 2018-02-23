/*
noBlock.c
Autor: Orlando Enrico Liz Silvério Silva
*/
#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(){
	Matriz A, B, C;
	int i, j, k, N=0, bsize=0;

	if(scanf("%d %d", &N, &bsize)!=2) printf("Erro");

	criaMatriz(&A, N);
	criaMatriz(&B, N);
	criaMatriz(&C, N);

	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			if(scanf("%d", &A.mat[i][j])!=1) printf("Erro");
		
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
				if(scanf("%d", &B.mat[i][j])!=1) printf("Erro");
	
	//Faz a multiplicação
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			C.mat[i][j] = 0;
			for(k=0; k<N; k++)
				C.mat[i][j] += A.mat[i][k] * B.mat[k][j];
		}
	}

	//Imprime a matriz C
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
				printf("%d ", C.mat[i][j]);
		}
		printf("\n");
	}
	
	liberaMatriz(&A);
	liberaMatriz(&B);
	liberaMatriz(&C);

	return 0;
}