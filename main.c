#include <stdio.h>
#include <stdlib.h>
#include "predio.c"

void main(){
	Predio predio;
	lerDimensoesPredio(&predio);
	scanf("%d", &predio.jirobaldo.baldes);
	lePlantaPredio(&predio);
	printf("%d %d\n", predio.jirobaldo.x, predio.jirobaldo.y);
		
    return;
}