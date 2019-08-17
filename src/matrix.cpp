#include "matrix.h"

matrix::matrix(int16_t rows,int16_t cols){
    this->rows = rows;
    this->cols = cols;
    
    srand(time(NULL));

    data = new double* [rows];

    for(int i = 0; i < rows; i++){
        data[i] = new double[cols];
        for(int j = 0; j < cols; j++){
            data[i][j] = 0;
        }
    }
}

matrix::~matrix(){
    for(int i = 0; i < rows; ++i) {
    delete [] data[i];
    }
    delete [] data;
}

matrix* matrix::fromArray(std::vector<double> arr){
    auto mT = new matrix(arr.size(),1);
    mT->map([&ArrayR = arr](double val,int16_t rows,int16_t cols){
        return ArrayR[rows];
    });
    return mT;
}

matrix matrix::randomize(matrix* m){
    m->map([](double val,int16_t rows,int16_t cols){
        return ((double) rand() / RAND_MAX) * 2 - 1; //! rnd number btw -1 and 1
    });
}

void matrix::map(std::function<double(double,int16_t,int16_t)> func){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            double val = data[rows][cols];
            *data[rows,cols] = func(val,rows,cols);
        }
    }
}

matrix matrix::transpose(matrix* m){

}

matrix matrix::operator+(const matrix & b){

}

matrix matrix::operator-(const matrix & b){
    
}

matrix matrix::operator*(const matrix & b){
    
}

matrix matrix::operator*(const double b){
    
}

void matrix::print(){
    std::cout << "==== " << rows << " x " << cols << " ====";
    map([&c = cols](double tval,int16_t trows,int16_t tcols){
        std::cout << tval << " ";
        if(tcols == c)
            std::cout << "\n";
    });
    std::cout << "\n";
}