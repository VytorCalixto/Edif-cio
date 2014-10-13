//Serve para marcar os vértices em que já passamos. True caso a busca já passou por lá, false caso contrário
typedef struct{
    bool *** planta;
}Planta;

//Aloca a planta com o mesmo tamanho do prédio e define todas as posições como false
void iniciaPlanta(Planta *planta, Predio *predio){
    int i, j, k;
    planta->planta = (bool ***) malloc(sizeof(bool **) * predio->h);

    for(i = 0; i < predio->h; i++){
        planta->planta[i] = (bool **) malloc(sizeof(bool *) * predio->w);
        for(j = 0; j < predio->w; j++){
            planta->planta[i][j] = (bool *) malloc(sizeof(bool) * predio->altura);
            for(k = 0; k < predio->altura; k++){
                planta->planta[i][j][k] = false;
            }
        }
    }
}

//Marca que um vértice foi enfileirado
void marcaVertice(Planta *planta, Vertice v){
    planta->planta[v.x][v.y][v.z] = true;
}

//Retorna true se o vértice já tiver sido marcado, false caso contrário
bool isVerticeMarcado(Planta *planta, Vertice v){
    return (planta->planta[v.x][v.y][v.z]);
}

void imprimePlanta(Planta planta, Predio *predio){
    int i, j, k;
    for(i = 0; i < predio->altura; i++){
        for(j = 0; j < predio->h; j++){
            for(k = 0; k<predio->w; k++){
                printf("%d \t", planta.planta[j][k][i]); //Imprime 0s e 1s
            }
            printf("\n");
        }
        printf("\n");
    }
}
