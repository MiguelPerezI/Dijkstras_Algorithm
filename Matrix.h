#include "list.h"
#include <stdbool.h>

#ifndef _MATRIX_
#define _MATRIX_

#ifdef __cplusplus
extern "C" {
#endif
typedef struct _matriz_{
  int m, n;
  double **A;
}MATRIZ;

int digitCounter(int n);
void space(int n);
int Index(struct lista *pl, int vertex);

MATRIZ creaEspacioMatriz(int m, int n);
int leeMatriz(MATRIZ *mat);
int escMatriz(MATRIZ mat);
MATRIZ tableZeroReal(MATRIZ Table1, int n);
MATRIZ AdjMatrixWeights(int n);
int liberaEspacioMatriz(MATRIZ *mat);
void addEdgeWW(MATRIZ mat, int m, int n, double weight);
struct lista* vecindadR(MATRIZ mat, struct lista *pl, int s);
void dijkstraW(MATRIZ mat, int s, int f);

#ifdef __cplusplus
}
#endif

#endif