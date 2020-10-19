#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "Matrix.h"
#include "list.h"

int digitCounter(int n) {
    int count = 0;
    if (n == 0) {return 1;}
    while (n != 0) {
          n /= 10; 
          ++count;
    }
    
return count;
}

void space(int n) {
     int i;
     for (i = 0; i < n; i++) 
         printf(" ");
}

int Index(struct lista *pl, int vertex) {
  int i;
  int count = 0;
  struct lista *aux = pl;
  while (vertex != aux->a) {
    aux = aux->sig;
    count += 1;
  }
  return count;
}

MATRIZ creaEspacioMatriz(int m, int n)
{
  MATRIZ ret={m:m, n:n, A:NULL}; /*en caso que esto no la aceptara el 
                                   compilador, se puede usar
                                   ret = {m, n, NULL} debido a que
                                   sabemos el orden de los campos
                                  */
  int i;

  ret.A = (double**)malloc(m*sizeof(double*));
  if (ret.A!=NULL){
    for(i=0; i<m; i++){
      ret.A[i] = (double *)malloc(n*sizeof(double));
      if (ret.A[i]==NULL){
        while(i>0){
          free(ret.A[--i]);/*liberando espacio previamente reservado
                         (i disminuyo antes de ser liberado A[])
                        */
          ret.A[i] = NULL;
        }
        break;
      }
    }
  }

  return ret;
}

int leeMatriz(MATRIZ *mat)
{
  int m, n, i, j;

  if (mat == NULL) return -1; /*codigo de error*/
  printf("Digite numero de renglones m:");
  scanf("%d", &m);
  printf("Digite numero de columnas n:");
  scanf("%d", &n);
  *mat = creaEspacioMatriz(m, n);
  printf("digite las entradas de la matriz:\n");
  for(i=0; i<m; i++)
    for (j=0; j<n; j++){
      printf("[%2d, %2d]=", i, j);
      scanf("%lg", &(mat->A[i][j]));
    }

  return 0; /*codigo de terminacion exita*/
}

int escMatriz(MATRIZ mat)
{
  int i, j;

  for (i=0; i<mat.m; i++){
    printf("\n");
    for (j=0; j<mat.n; j++){
      printf("%6lg ", mat.A[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  return 0;
}

int liberaEspacioMatriz(MATRIZ *mat)
{
  int i;

  for (i=0; i<mat->m; i++){
    free(mat->A[i]);
    mat->A[i]=NULL;
  }
  free(mat->A);
  mat->A=NULL;
  mat->m = mat->n = 0;

  return 0;
}

MATRIZ tableZeroReal(MATRIZ Table1, int n) {
      int i;
      int j;
    
      Table1 = creaEspacioMatriz(n, n);
               for (i = 0; i < n; i++)
                   for (j = 0; j < n; j++) 
                       Table1.A[i][j] = 0;
      return Table1;
}

MATRIZ AdjMatrixWeights(int n) {
  MATRIZ B;
  B = tableZeroReal(B, n);
  return B;
}

void addEdgeWW(MATRIZ mat, int m, int n, double weight) {
  if (m == n) {
    mat.A[m][n] = 0;
  } else {
    mat.A[m][n] = weight;
    mat.A[n][m] = weight;
  }

}

struct lista* vecindadR(MATRIZ mat, struct lista *pl, int s) {
  struct lista *connection = creaEL(1313130013);
  int u = lengthSub(pl);
  int i;
  for (i = 0; i < u; i++) {
    int ii = getSmallLista(pl, i);
    if (mat.A[ii][s] != 0.0) {
      struct lista *aux = creaEL(ii);
      aux->sig = connection;
      connection = aux;
    }
  }

  connection = removeSub(connection, 1313130013);

  return connection;
}

void dijkstraW(MATRIZ mat, int s, int f) {
  double dist[mat.n];
  int prev[mat.n];

  prev[s] = -1;

  int i;
  for (i = 0; i < mat.n; i++) {
    dist[i] = 1000000000; 
  }

  dist[s] = 0; 

  struct lista *Q = creaEL(mat.n - 1);
  for (i = mat.n - 2; i >= 0; i--) {
    struct lista *aux = creaEL(i);
    aux->sig = Q;
    Q = aux;
  }

  struct lista *A = Q; 

int bound = 0;
  while (Q != NULL) {

    double recordd = 1000010007;
    int winner;
    for (i = 0; i < lengthSub(Q); i++) {
      int ii = getSmallLista(Q, i);
      if (dist[ii] < recordd) {
        recordd = dist[ii];
      }
    }

    for (i = 0; i < lengthSub(Q); i++) {
      int ii = getSmallLista(Q, i);
      if (dist[ii] == recordd){
        winner = ii;
      }
    }

    int v = winner;
    Q = removeSub(Q, v);
    
    struct lista *ball = vecindadR(mat, Q, v);
    ball = removeSub(ball, v);

    for (i = 0; i < lengthSub(ball); i++) {

      int ii = getSmallLista(ball, i);
      double alt = dist[v] + mat.A[v][ii];

        if (alt < dist[ii]) {
          dist[ii] = alt;
          prev[ii] = v;
        }
    }

    bound += 1;
  }

  struct lista *shortesPath = creaEL(f);
  int w = prev[f];
  struct lista *AUX1 = creaEL(w);
    AUX1->sig = shortesPath;
    shortesPath = AUX1;
  while (w != -1) {
    w = prev[w];
    if (w != -1) {
      struct lista *AUX = creaEL(w);
      AUX->sig = shortesPath;
      shortesPath = AUX;
    }

  }

  removeSub(shortesPath, -1);
  int k;
  struct lista *auxPath = shortesPath;
  for (k = 0; k < lengthSub(shortesPath); k++) {
    printf("%d - ", getSmallLista(shortesPath, k));
  }

}// end of dijlstra