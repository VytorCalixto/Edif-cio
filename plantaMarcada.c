typedef struct{
    int *** planta;
}Planta;

void iniciaPlanta(Predio *predio, Planta *planta){
    int i, j, k;
    planta->planta = (int ***) malloc(sizeof(int **) * predio->h);

    for(i = 0; i < predio->h; i++){
        planta->planta[i] = (int **) malloc(sizeof(int *) * predio->w);
        for(j = 0; j < predio->w; j++){
            planta->planta[i][j] = (int *) malloc(sizeof(int) * predio->altura);
            for(k = 0; k < predio->altura; k++){
                planta->planta[i][j][k] = 0;
            }
        }
    }
}

void marcaVertice(Vertice vertice, Planta *planta){
    planta->planta[vertice.x][vertice.y][vertice.z] = -1;
}

void imprimePlanta(Predio *predio, Planta planta){
    int i, j, k;
    for(i = 0; i < predio->altura; i++){
        for(j = 0; j < predio->h; j++){
            for(k = 0; k<predio->w; k++){
                printf("%d \t", planta.planta[j][k][i]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
