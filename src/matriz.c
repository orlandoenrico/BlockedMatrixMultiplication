/*
matriz.c
Autor: Orlando Enrico Liz Silvério Silva
*/
#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"


// Aloca a matriz. Size é definido na struct pra poder percorrer
// a matriz de forma direta, sem a necessidade de parâmetros adicionais
void criaMatriz(Matriz *matrix, int n) {
    matrix->n = n;
    matrix->mat = (int**) calloc(matrix->n, sizeof(int*));
 
    int i;
    for (i = 0; i < matrix->n; i++) {
        matrix->mat[i] = (int*) calloc(matrix->n, sizeof(int));
    }
}
 
// Libera a memória alocada para a matriz (Perceba a utilização de "size" aqui)
void liberaMatriz(Matriz *matrix) {
    int i;
    for (i = 0; i < matrix->n; i++) {
        free(matrix->mat[i]);
    }
 
    free(matrix->mat);
}
