#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "predio.c"
#include "fila.c"

//Retorna true se encontra a saída, false caso contrário
bool buscaEmLargura(Predio *predio);

/*Converte um ponto da planta para um vértice
* x,y = ponto no plano
* z = andar do predio
*/
Vertice pontoParaVertice(Predio *predio, int x, int y, int z);

//Enfileira vértices adjacentes aos vértices dados
void enfileiraAdjacente(Fila *fila, Vertice vertice);

int ***plantaMarcada;
void iniciaPlantaMarcada(Predio *predio){
	int i, j, k;
	plantaMarcada = (int ***) malloc(sizeof(int **) * predio->altura);

	for(i = 0; i < predio->altura; i++){
		plantaMarcada[i] = (int **) malloc(sizeof(int *) * predio->h);
		for(j = 0; j < predio->h; j++){
			plantaMarcada[i][j] = (int *) malloc(sizeof(int) * predio->w);
			for(k = 0; k < predio->w; k++){
				plantaMarcada[i][j][k] = 0;
			}
		}
	}
}

void main(){
	Predio predio;
	lerDimensoesPredio(&predio);
	iniciaPlantaMarcada(&predio);
	scanf("%d", &predio.jirobaldo.baldes);
	lePlantaPredio(&predio);
	printf("%d %d\n", predio.jirobaldo.x, predio.jirobaldo.y);

  return;
}

bool buscaEmLargura(Predio *predio){
	Fila fila; //fila de vértices
	iniciaFila(&fila);
	//Busca começa no vértice do Jirobaldo, com 0 baldes com água
	Vertice raiz = {'J', predio->jirobaldo.x, predio->jirobaldo.y, predio->jirobaldo.z, 0};
	enfileira(&fila, raiz);
	while(!vaziaFila(&fila)){
		Vertice frente = desenfileira(&fila);
		enfileiraAdjacente(&fila, frente);
		// marcaVertice(vertice);
	}
}

Vertice pontoParaVertice(Predio *predio, int x, int y, int z){
	char valor = predio->pisos[z].pontos[x][y];
	Vertice vertice = {valor, x, y, z, 0};
	return vertice;
}

void enfileiraAdjacente(Fila *fila, Vertice vertice){

}
