#include <stdio.h>
#include "image.h"

/* FILTROS ENUMERADOS:

SHARPEN
EMBOSS
BLUR
IDENTITY
GRAYSCALE
ROTATE180
THRESHOLDING
*/
int main(){

	char type[2];
	scanf("%s", type);

	int column, line, quality;
	scanf("%i %i", &column, &line);
	scanf("%i", &quality);

	PIXEL matriz[line][column];
    PIXEL modified[line][column];

    enum Filters filter = IDENTITY;

    readImage(line, column, matriz);
    imageFilter(line, column, matriz, modified, filter);  
    generateImage(line, column, modified, type, quality);
    
	return 0;
}
