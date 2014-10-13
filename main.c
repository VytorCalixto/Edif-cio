#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "predio.c"
#include "fila.c"
#include "planta.c"

int buscaEmLargura(Predio predio, Vertice raiz);
void enfileiraAdjacentes(Fila *fila, Vertice vertice, Predio predio, Planta *planta);
Vertice *getAdjacentes(Vertice vertice, Predio predio);
bool isVerticeValido(Predio predio, Vertice v);
Vertice pontoParaVertice(Predio predio, int x, int y, int z);

void main(){
	Predio predio;
	lerDimensoesPredio(&predio);
	scanf("%d", &predio.jirobaldo.baldes);
	lePredio(&predio);
	//Raiz da busca em largura: Jirobaldo, com 0 baldes cheios e tempo inicial = 0
	Vertice raiz = {'J', predio.jirobaldo.x, predio.jirobaldo.y, predio.jirobaldo.z, 0, 0};
	int tempo = buscaEmLargura(predio, raiz);
	printf("%d\n", tempo);
	return;
}

int buscaEmLargura(Predio predio, Vertice raiz){
	Fila fila; //Fila dos vértices.
	Planta plantas[predio.jirobaldo.baldes+1]; //Estrutura para marcar os vértices visitados.
	int tempo = -1;

	iniciaFila(&fila);
	int i;
	for(i = 0; i <= predio.jirobaldo.baldes; i++){
		iniciaPlanta(&plantas[i],&predio);
	}
	
	marcaVertice(&plantas[0], raiz); //Jirobaldo sempre começa com 0 baldes
	enfileira(&fila, raiz);

	while(!vaziaFila(&fila)){
		Vertice frente = desenfileira(&fila);
		enfileiraAdjacentes(&fila, frente, predio, &plantas[frente.baldes]);
		if(frente.valor == 'S'){
			if(tempo == -1 || frente.tempo < tempo){
				tempo = frente.tempo;
			}
		}
	}

	return tempo;
}

void enfileiraAdjacentes(Fila *fila, Vertice vertice, Predio predio, Planta *planta){
	Vertice *adj = getAdjacentes(vertice, predio);
	int i;
	Vertice adjacentes[6];
	for(i = 0; i < 6; i++){
		adjacentes[i] = adj[i];
	}
	for(i = 0; i < 6; i++){
		Vertice v = adjacentes[i];
		if(isVerticeValido(predio, v)){
			if(!isVerticeMarcado(planta, v)){
				v.tempo = vertice.tempo + 1;
				v.baldes = vertice.baldes;
				
				if(v.valor == 'F'){
					v.baldes--;
					if(v.baldes >= 0){
						marcaVertice(planta, v);
						enfileira(fila, v);
					}
				}else if(v.valor == 'T'){
					marcaVertice(planta, v);
					//Enfileira a opção em que Jirobaldo não enche baldes
					enfileira(fila, v);

					//Enfileira as opções em que Jirobaldo enche o balde
					int j;
					for(j = vertice.baldes + 1; j <= predio.jirobaldo.baldes; j++){
						v.baldes = j;
						v.tempo++;
						enfileira(fila, v);
					}
				}else{
					marcaVertice(planta, v);
					enfileira(fila, v);
				}
			}
		}
	}
}

Vertice *getAdjacentes(Vertice vertice, Predio predio){
	Vertice norte, sul, leste, oeste, acima, abaixo;
	acima.valor = '#';
	abaixo.valor = '#';
	Vertice adjacentes[6]; //Só existem seis adjacentes possíveis

	norte 	= pontoParaVertice(predio, vertice.x - 1, vertice.y, vertice.z);
	sul 	= pontoParaVertice(predio, vertice.x + 1, vertice.y, vertice.z);
	leste 	= pontoParaVertice(predio, vertice.x, vertice.y + 1, vertice.z);
	oeste 	= pontoParaVertice(predio, vertice.x, vertice.y - 1, vertice.z);

	if(vertice.valor == 'D'){
		abaixo = pontoParaVertice(predio, vertice.x, vertice.y, vertice.z - 1);
	}else if(vertice.valor == 'U'){
		acima = pontoParaVertice(predio, vertice.x, vertice.y, vertice.z + 1);
	}else if(vertice.valor == 'E'){
		acima = pontoParaVertice(predio, vertice.x, vertice.y, vertice.z + 1);
		abaixo = pontoParaVertice(predio, vertice.x, vertice.y, vertice.z - 1);
	}

	adjacentes[0] = norte;
	adjacentes[1] = sul;
	adjacentes[2] = leste;
	adjacentes[3] = oeste;
	adjacentes[4] = acima;
	adjacentes[5] = abaixo;

	return adjacentes;
}

bool isVerticeValido(Predio predio, Vertice vertice){
	char cValidos[8] = {'.', 'E', 'J', 'U', 'D', 'F', 'S', 'T'};
	int i;
	for(i = 0; i < 8; i ++){
		if(vertice.valor == cValidos[i]){
			return true && (isPontoNoPredio(&predio, vertice.x, vertice.y, vertice.z));
		}
	}
	return false;
}

Vertice pontoParaVertice(Predio predio, int x, int y, int z){
	//			 valor, x, y, z, baldes, tempo
	Vertice v = {'#', 	0, 0, 0, 0, 	 0};
	if(isPontoNoPredio(&predio, x, y, z)){
		v.valor = predio.pisos[z].pontos[x][y];
		v.x = x;
		v.y = y;
		v.z = z;
	}
	return v;
}
