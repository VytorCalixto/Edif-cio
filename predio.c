typedef struct{
	char **pontos;
}Pavimento;

typedef struct{
	int x,y,z,baldes;
}Jirobaldo;

typedef struct{
    Pavimento *pisos;
    int altura, h, w;
    Jirobaldo jirobaldo;
}Predio;

void lerDimensoesPredio(Predio *predio);
void alocaPredio(Predio *predio);
void imprimePredio(Predio *predio);
void lePredio(Predio *predio);
bool isPontoNoPredio(Predio *predio, int x, int y, int z);


//Lê as dimensões do prédio
void lerDimensoesPredio(Predio *predio){
	scanf(" %d %d %d", &predio->altura, &predio->w, &predio->h);
}

//Lê a planta do prédio
void lePredio(Predio *predio){
	int i, j, k;
	alocaPredio(predio);

	for(i = 0; i < predio->altura; i++){
		for(j = 0; j < predio->h; j++){
			for(k = 0; k < predio->w; k++){
				scanf(" %c", &predio->pisos[i].pontos[j][k]);
				if(predio->pisos[i].pontos[j][k] == 'J'){
					predio->jirobaldo.x = j;
					predio->jirobaldo.y = k;
					predio->jirobaldo.z = i;
				}
			}
		}
	}
}

//Aloca em memória o espaço necessário para a planta do prédio
void alocaPredio(Predio *predio){
	int i, j;
	predio->pisos = (Pavimento *) malloc(sizeof(Pavimento) * predio->altura);

	for(i = 0; i < predio->altura; i++){
		predio->pisos[i].pontos = (char **) malloc(sizeof(char*) * predio->h);
		for(j = 0; j < predio->h; j++){
			predio->pisos[i].pontos[j] = (char *) malloc(sizeof(char) * predio->w);
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

bool isPontoNoPredio(Predio *predio, int x, int y, int z){
	return ((x >= 0 && x < predio->h) && (y >= 0 && y < predio->w) && (z >= 0 && z <predio->altura));
}
