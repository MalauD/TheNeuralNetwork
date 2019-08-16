#include "matrix.h"

matrix::matrix(int16_t rows,int16_t cols){
    this->rows = rows;
    this->cols = cols;
    
    data = new double* [rows];

    for(int i = 0; i < rows; i++){
        data[i] = new double[cols];
        for(int j = 0; j < cols; j++){
            data[i][j] = 0;
        }
    }
}

matrix matrix::fromArray(double arr[]){

}

matrix matrix::randomize(matrix* m){

}

matrix matrix::map(matrix* m,void* func){

}

matrix matrix::transpose(matrix* m){

}