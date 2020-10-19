#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "Matrix.h"
#include "list.h"

int main() {
	printf("\n{{{{....Grafos....}}}}\n\n\n");
    int k;
    printf("Digite el numero de vertices deseados: \n");
    scanf("%d", &k);
	
  MATRIZ B = AdjMatrixWeights(k);
    printf("\n*--- Ingrese las conexiones del grafo y digite -1 para detener.\n");
    int s0;
    int f0;

    int counted = 1;
    int exit = 1;
    int con;

    printf("\nPresione 1 contruir un grafo con pesos o  -1 para una grafica sin pesos.\n");
    scanf("%d", &con);

    if ( con == 1) {
        double weight;
        while (exit != -1) {
            printf("Arista(%d)  ------->    \n", counted);
            printf("inVertice = \n");
            scanf("%d", &s0);
            printf("fiVertice = \n");
            scanf("%d", &f0);
            printf("weight = ");
            scanf("%lg", &weight);
            printf("\nDigite -1 para terminar o cualquier otro numero para continar.\n");
            scanf("%d", &exit);
            addEdgeWW(B, s0, f0, weight);
            counted += 1;
            printf("\n\n");
        }
    } else {
        while (exit != -1) {
            printf("Arista(%d)  ------->    \n", counted);
            printf("inVertice = \n");
            scanf("%d", &s0);
            printf("fiVertice = \n");
            scanf("%d", &f0);
            printf("Digite -1 para terminar o cualquier otro numero para continar.\n");
            scanf("%d", &exit);
            addEdgeWW(B, s0, f0, 1.0);
            counted += 1;
            printf("\n\n");
        }
    }

    int s;
    int f;
    exit = 1;
    while (exit != -1) {
        printf("\n*--- Eliga dos vertices para conocer el camino minimo entre ellos:\n");
        printf("Inicio = \n");
        scanf("%d", &s);
        printf("Fin = \n");
        scanf("%d", &f);

        printf("\n\nEl camino de %d -> %d: \n\n", s, f);
        dijkstraW(B, s, f);
        printf("\nPara salir digite -1 y cualquier numero para intentar de nuevo.\n");
        scanf("%d", &exit);
    }

	printf("\n\n\n");
	return 0;
}