typedef struct{
	char **pontos;
}Pavimento;

typedef struct{
	int x,y,baldes;
}Jirobaldo;

typedef struct{
    Pavimento *pisos;
    int altura, h, w;
    Jirobaldo jirobaldo;
}Predio;

void lerDimensoesPredio(Predio *predio);
void alocaPredio(Predio *predio);
void imprimePredio(Predio *predio);
void lePlantaPredio(Predio *predio);

void lerDimensoesPredio(Predio *predio){
	scanf("%d %d %d", &predio->altura, &predio->w, &predio->h);
}

void lePlantaPredio(Predio *predio){
	int i, j, k;
	alocaPredio(predio);

	for(i = 0; i < predio->altura; i ++){
		for(j = 0; j < predio->h; j++){
			for(k = 0; k < predio->w; k++){
				scanf(" %c", &predio->pisos[i].pontos[j][k]);
				if(predio->pisos[i].pontos[j][k] == 'J'){
					predio->jirobaldo.x = j;
					predio->jirobaldo.y = k;
				}
			}
		}
	}
}

void alocaPredio(Predio *predio){
	int i, j;
	predio->pisos = (Pavimento *) malloc(sizeof(Pavimento) * predio->altura);
	
	for(i = 0; i < predio->altura; i++){
		predio->pisos[i].pontos = (char **) malloc(sizeof(char*) * predio->w);
		for(j = 0; j < predio->w; j++){
			predio->pisos[i].pontos[j] = (char *) malloc(sizeof(char) * predio->h);
		}
	}
}

void imprimePredio(Predio *predio){
	int i, j, k;
	for(i = 0; i < predio->altura; i ++){
		for(j = 0; j < predio->h; j++){
			for(k = 0; k < predio->w; k++){
				printf("%c", predio->pisos[i].pontos[j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
}
