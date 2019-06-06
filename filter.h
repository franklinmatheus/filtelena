#ifndef __FILTER_H__
#define __FILTER_H__

    #include "pixel.h"
    void filterSharpen(int line, int column, PIXEL matriz[line][column], PIXEL modified[line][column]);
    void filterEmboss(int line, int column, PIXEL matriz[line][column], PIXEL modified[line][column]);
    void filterBlur(int line, int column, PIXEL matriz[line][column], PIXEL modified[line][column]);
    void filterIdentity(int line, int column, PIXEL matriz[line][column], PIXEL modified[line][column]);
    void grayScale(int line, int column, PIXEL matriz[line][column], PIXEL modified[line][column]);
    void rotate180(int line, int column, PIXEL matriz[line][column], PIXEL modified[line][column]);
    void thresholding(int line, int column, PIXEL matriz[line][column], PIXEL modified[line][column]);

#endif