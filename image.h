#ifndef __IMAGE_H__
#define __IMAGE_H__

    #include "pixel.h"
    #include "filters.h"
    void readImage(int line, int column, PIXEL matriz[line][column]);
    void imageFilter(int line, int column, PIXEL matriz[line][column], PIXEL modified[line][column], enum Filters filter);
    void generateImage(int line, int column, PIXEL matriz[line][column], char type[2], int quality);

#endif