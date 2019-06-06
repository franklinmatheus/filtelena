#include <stdio.h>
#include "image.h"
#include "filter.h"

void readImage(int line, int column, PIXEL matriz[line][column]){
	int i, j; 

	for(i = 0; i < line; i++){
		for(j = 0; j < column; j++){
			scanf("%i %i %i", &matriz[i][j].r, &matriz[i][j].g, &matriz[i][j].b);
		}
	}
}

void imageFilter(int line, int column, PIXEL matriz[line][column], PIXEL modified[line][column], enum Filters filter){

	switch(filter){
		case SHARPEN:
			filterSharpen(line, column, matriz, modified);
			break;
		case EMBOSS:
			filterEmboss(line, column, matriz, modified);	
			break;
		case BLUR:
			filterBlur(line, column, matriz, modified);	
			break;
		case IDENTITY:
			filterIdentity(line, column, matriz, modified);	
			break;
		case ROTATE180:
			rotate180(line, column, matriz, modified);
			break;
		case THRESHOLDING:
			thresholding(line, column, matriz, modified);	
			break;
		case GRAYSCALE:
			grayScale(line, column, matriz, modified);
			break;
	}	
}

void generateImage(int line, int column, PIXEL matriz[line][column], char type[2], int quality){
	int i, j;

	printf("%s\n", type);
	printf("%i %i\n", column, line);
	printf("%i\n", quality);

	for(i = 0; i < line; i++){
		for(j = 0; j < column; j++){
			printf("%i %i %i ", matriz[i][j].r, matriz[i][j].g, matriz[i][j].b);
		}
		printf("\n");
	}
}
