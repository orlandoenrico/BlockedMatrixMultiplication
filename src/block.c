/*
block.c
Autor: Orlando Enrico Liz Silvério Silva
*/
#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(){
	Matriz A, B, C;
	int N=0, bsize=0, sum=0;
	int kk, jj, i, j, k;

	if(scanf("%d %d", &N, &bsize)!=2) printf("Erro");

	criaMatriz(&A, N);
	criaMatriz(&B, N);

	//Lê os valores da Matriz A
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			if(scanf("%d", &A.mat[i][j])!=1) printf("Erro");
		
	//Lê os valores da Matriz B
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			if(scanf("%d", &B.mat[i][j])!=1) printf("Erro");

	criaMatriz(&C, N);

	//Faz a multiplicação com blocos
	for (kk = 0; kk < N; kk += bsize){
		for (jj = 0; jj < N; jj += bsize){
			for (i = 0; i < N; i++){
				for (j = jj; j< jj + bsize; j++){
					sum = C.mat[i][j];
					for (k = kk; k < kk + bsize; k++){
						sum += A.mat[i][k] * B.mat[k][j];
					}
					C.mat[i][j] = sum;
				}
			}
		}
	}

	//Imprime a matriz C
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("%d ", C.mat[i][j]);
		}
		printf("\n");
	}

	liberaMatriz(&C);
	liberaMatriz(&A);
	liberaMatriz(&B);

	return 0;
}