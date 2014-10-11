#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "predio.c"
#include "fila.c"
#include "plantaMarcada.c"

//Retorna true se encontra a saída, false caso contrário
int buscaEmLargura(Predio *predio, Vertice raiz);

/*Converte um ponto da planta para um vértice
* x,y = ponto no plano
* z = andar do predio
*/
Vertice pontoParaVertice(Predio *predio, int x, int y, int z);

//Enfileira vértices adjacentes aos vértices dados
void enfileiraAdjacentes(Predio *predio, Fila *fila, Vertice vertice, Planta plantaMarcada);
Vertice *getAdjacentes(Predio *predio, Vertice vertice);
bool isVerticeValido(Vertice vertice);

void main(){
	Predio predio;
	lerDimensoesPredio(&predio);
	scanf("%d", &predio.jirobaldo.baldes);
	lePlantaPredio(&predio);
	imprimePredio(&predio);
	//Busca começa no vértice do Jirobaldo, com 0 baldes com água
	Vertice raiz = {'J', predio.jirobaldo.x, predio.jirobaldo.y, predio.jirobaldo.z, 0, 0};
	int tempo = buscaEmLargura(&predio, raiz);
	printf("%d\n", tempo);

  return;
}

int buscaEmLargura(Predio *predio, Vertice raiz){
	Fila fila; //fila de vértices
	Planta plantaMarcada;
	int tempo = -1;

	iniciaFila(&fila);
	iniciaPlanta(predio, &plantaMarcada);
	marcaVertice(raiz, &plantaMarcada);
	enfileira(&fila, raiz);
	while(!vaziaFila(&fila)){
		Vertice frente = desenfileira(&fila);
		if(frente.baldes > raiz.baldes){
			int bTempo = buscaEmLargura(predio, frente); //faz uma busca em largura com aquela quantidade de baldes.
			if(tempo == -1 || bTempo < tempo){
				tempo = bTempo;
			}
		}
		if(frente.valor == 'S'){
			if(tempo == -1 || frente.tempo < tempo){
				tempo = frente.tempo;
			}
		}
		enfileiraAdjacentes(predio, &fila, frente, plantaMarcada);
	}
	return tempo;
}

Vertice pontoParaVertice(Predio *predio, int x, int y, int z){
	char valor = '/';
	if(isPontoNoPredio(predio, x, y, z)){
		valor = predio->pisos[z].pontos[x][y];
	}
	Vertice vertice = {valor, x, y, z, 0, 0};
	return vertice;
}

void enfileiraAdjacentes(Predio *predio, Fila *fila, Vertice vertice, Planta plantaMarcada){
	int i,	tam = 6; //Só existem 6 adjacentes possíveis
	Vertice *adjacentes = getAdjacentes(predio, vertice);
	for(i = 0; i < tam; i++){
		Vertice v = adjacentes[i];
		if(isVerticeValido(v)){
			if(plantaMarcada.planta[v.x][v.y][v.z] != -1){
				v.tempo = vertice.tempo + 1;
				v.baldes = vertice.baldes;

				if(v.valor == 'F'){
					v.baldes = vertice.baldes - 1;
					marcaVertice(v, &plantaMarcada);
					if(v.baldes >= 0){
						enfileira(fila, v);
					}
				}else if(v.valor == 'T'){
					int j;
					marcaVertice(v, &plantaMarcada);
					enfileira(fila, v); //Enfileira a alternativa em que ele não enche os baldes
					//Enfileira as possibilidades de baldes
					for(j = vertice.baldes + 1; j < predio->jirobaldo.baldes; j++){
						v.baldes = j;
						v.tempo++;
						enfileira(fila, v);
					}
				}else{
					enfileira(fila, v);
					marcaVertice(v, &plantaMarcada);
				}
			}
		}
	}
}

Vertice *getAdjacentes(Predio *predio, Vertice vertice){
	Vertice norte, sul, leste, oeste;
	Vertice acima = {'/', 0, 0, 1, 0, 0};
	Vertice abaixo = {'/', 0, 0, 1, 0, 0};
	Vertice adjacentes[6];

	norte = pontoParaVertice(predio, vertice.x, vertice.y-1, vertice.z);
	sul = pontoParaVertice(predio, vertice.x, vertice.y+1, vertice.z);
	leste = pontoParaVertice(predio, vertice.x+1, vertice.y, vertice.z);
	oeste = pontoParaVertice(predio, vertice.x-1, vertice.y, vertice.z);

	if(vertice.valor == 'U'){
		acima = pontoParaVertice(predio, vertice.x, vertice.y, vertice.z+1);
	}else if(vertice.valor == 'D'){
		abaixo = pontoParaVertice(predio, vertice.x, vertice.y, vertice.z-1);
	}else if(vertice.valor == 'E'){
		abaixo = pontoParaVertice(predio, vertice.x, vertice.y, vertice.z-1);
		acima = pontoParaVertice(predio, vertice.x, vertice.y, vertice.z+1);
	}

	adjacentes[0] = norte;
	adjacentes[1] = sul;
	adjacentes[2] = leste;
	adjacentes[3] = oeste;
	adjacentes[4] = acima;
	adjacentes[5] = abaixo;

	return adjacentes;
}

bool isVerticeValido(Vertice vertice){
	char cValidos[8] = {'.', 'E', 'J', 'U', 'D', 'F', 'S', 'T'};
	int i;
	for(i = 0; i < 8; i ++){
		if(vertice.valor == cValidos[i]){
			return true;
		}
	}
	return false;
}
