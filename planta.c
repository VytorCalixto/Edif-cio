//Serve para marcar os vértices em que já passamos.
typedef struct{
    bool *** planta;
}Planta;

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

void marcaVertice(Planta *planta, Vertice v){
    planta->planta[v.x][v.y][v.z] = true;
}

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
