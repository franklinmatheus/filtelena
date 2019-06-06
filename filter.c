#include <stdio.h>
#include "filter.h"

void filterSharpen(int line, int column, PIXEL matriz[line][column], PIXEL modified[line][column]){
	int lin, col, sum_r, sum_g, sum_b, i, j;

	float boxsharpen[3][3] = {
		{ 0, -1, 0 },
		{ -1, 5, -1 },
		{ 0, -1, 0 }
	};

	for(lin = 1; lin < line-1; lin++){
		for(col = 1; col < column-1; col++){
			sum_r = 0, sum_g = 0, sum_b = 0;
			for(i = 0; i < 3; i++){
				for(j = 0; j < 3; j++){
					sum_r += matriz[lin-1 + i][col-1 + j].r * boxsharpen[i][j];
                    sum_g += matriz[lin-1 + i][col-1 + j].g * boxsharpen[i][j];
                    sum_b += matriz[lin-1 + i][col-1 + j].b * boxsharpen[i][j];
				}
			}
			sum_r > 255 ? sum_r = 255: sum_r < 0 ? sum_r = 0 : sum_r;
			sum_g > 255 ? sum_g = 255: sum_g < 0 ? sum_g = 0 : sum_g;
			sum_b > 255 ? sum_b = 255: sum_b < 0 ? sum_b = 0 : sum_b;
			
			modified[lin][col].r = sum_r;
            modified[lin][col].g = sum_g;
            modified[lin][col].b = sum_b;
		}
	}
}

void filterEmboss(int line, int column, PIXEL matriz[line][column], PIXEL modified[line][column]){
	int lin, col, sum_r, sum_g, sum_b, i, j;

	float boxemboss[3][3] = {
		{ -2, -1, 0 },
		{ -1, 1, 1 },
		{ 0, 1, 2 }
	};

	for(lin = 1; lin < line-1; lin++){
		for(col = 1; col < column-1; col++){
			sum_r = 0, sum_g = 0, sum_b = 0;
			for(i = 0; i < 3; i++){
				for(j = 0; j < 3; j++){
					sum_r += matriz[lin-1 + i][col-1 + j].r * boxemboss[i][j];
                    sum_g += matriz[lin-1 + i][col-1 + j].g * boxemboss[i][j];
                    sum_b += matriz[lin-1 + i][col-1 + j].b * boxemboss[i][j];
				}
			}
			sum_r > 255 ? sum_r = 255: sum_r < 0 ? sum_r = 0 : sum_r;
			sum_g > 255 ? sum_g = 255: sum_g < 0 ? sum_g = 0 : sum_g;
			sum_b > 255 ? sum_b = 255: sum_b < 0 ? sum_b = 0 : sum_b;
			
			modified[lin][col].r = sum_r;
            modified[lin][col].g = sum_g;
            modified[lin][col].b = sum_b;
		}
	}
}

void filterBlur(int line, int column, PIXEL matriz[line][column], PIXEL modified[line][column]){
	int lin, col, sum_r, sum_g, sum_b, i, j;

	float boxblur[3][3] = {
		{ 0.0625, 0.125, 0.0625 },
		{ 0.125,  0.25,  0.125  },
		{ 0.0625, 0.125, 0.0625 }
	};

	for(lin = 1; lin < line-1; lin++){
		for(col = 1; col < column-1; col++){
			sum_r = 0, sum_g = 0, sum_b = 0;
			for(i = 0; i < 3; i++){
				for(j = 0; j < 3; j++){
					sum_r += matriz[lin-1 + i][col-1 + j].r * boxblur[i][j];
                    sum_g += matriz[lin-1 + i][col-1 + j].g * boxblur[i][j];
                    sum_b += matriz[lin-1 + i][col-1 + j].b * boxblur[i][j];
				}
			}
			sum_r > 255 ? sum_r = 255: sum_r < 0 ? sum_r = 0 : sum_r;
			sum_g > 255 ? sum_g = 255: sum_g < 0 ? sum_g = 0 : sum_g;
			sum_b > 255 ? sum_b = 255: sum_b < 0 ? sum_b = 0 : sum_b;
			
			modified[lin][col].r = sum_r;
            modified[lin][col].g = sum_g;
            modified[lin][col].b = sum_b;
		}
	}
}

void filterIdentity(int line, int column, PIXEL matriz[line][column], PIXEL modified[line][column]){
	int lin, col, sum_r, sum_g, sum_b, i, j;

	float boxidentity[3][3] = {
		{ 0, 0, 0 },
		{ 0, 1, 0 },
		{ 0, 0, 0 }
	};

	for(lin = 1; lin < line-1; lin++){
		for(col = 1; col < column-1; col++){
			sum_r = 0, sum_g = 0, sum_b = 0;
			for(i = 0; i < 3; i++){
				for(j = 0; j < 3; j++){
					sum_r += matriz[lin-1 + i][col-1 + j].r * boxidentity[i][j];
                    sum_g += matriz[lin-1 + i][col-1 + j].g * boxidentity[i][j];
                    sum_b += matriz[lin-1 + i][col-1 + j].b * boxidentity[i][j];
				}
			}
			sum_r > 255 ? sum_r = 255: sum_r < 0 ? sum_r = 0 : sum_r;
			sum_g > 255 ? sum_g = 255: sum_g < 0 ? sum_g = 0 : sum_g;
			sum_b > 255 ? sum_b = 255: sum_b < 0 ? sum_b = 0 : sum_b;
			
			modified[lin][col].r = sum_r;
            modified[lin][col].g = sum_g;
            modified[lin][col].b = sum_b;
		}
	}
}

void grayScale(int line, int column, PIXEL matriz[line][column], PIXEL modified[line][column]){
	int lin, col, pixel;

	for(lin = 0; lin < line; lin++){
		for(col = 0; col < column; col++){
			pixel = (matriz[lin][col].r + matriz[lin][col].g + matriz[lin][col].b)/3;

			modified[lin][col].r = pixel;
			modified[lin][col].g = pixel;
			modified[lin][col].b = pixel;
		}
	}
}

void rotate180(int line, int column, PIXEL matriz[line][column], PIXEL modified[line][column]){
	int lin, col;

	for(lin = 0; lin < line; lin++){
		for(col = 0; col < column; col++){
			modified[line-lin][column-col] = matriz[lin][col];
		}
	}
}

void thresholding(int line, int column, PIXEL matriz[line][column], PIXEL modified[line][column]){
	int lin, col, pixel, average;
	
	for(lin = 0; lin < line; lin++){
		for(col = 0; col < column; col++){
			average = (matriz[lin][col].r + matriz[lin][col].g + matriz[lin][col].b)/3;
			
			if(average > 126){
				pixel = 255;
			} else {
				pixel = 0;
			}
			modified[lin][col].r = pixel;
			modified[lin][col].g = pixel;
			modified[lin][col].b = pixel;
		}
	}
}