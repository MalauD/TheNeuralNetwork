#include "matrix.h"

matrix::matrix(uint16_t rows,uint16_t cols){
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
    mT->map([&ArrayR = arr](double val,uint16_t rows,uint16_t cols){
        return ArrayR[rows];
    });
    return mT;
}

void matrix::randomize(matrix* m){
    m->map([](double val,uint16_t rows,uint16_t cols){
        return ((double) rand() / RAND_MAX) * 2 - 1; //! rnd number btw -1 and 1
    });
}

void matrix::map(std::function<double(double,uint16_t,uint16_t)> func){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            double val = data[i][j];
            data[i][j] = func(val,i,j);
        }
    }
}

void matrix::transpose(){
	matrix* m2 = new matrix(cols, rows);
	m2->map([arrM = getMatrixArr()](double tval, uint16_t tcols, uint16_t trows) {
		return arrM[trows][tcols];
	});
	cols = m2->cols;
	rows = m2->rows;
	data = m2->data;
}

matrix matrix::operator+(const matrix & b){
	if (rows != b.rows && cols != b.rows) {
		throw std::exception("Sizes of matrices don't match");
	}
	matrix* m = new matrix(rows, cols);

	m->map([arrA = getMatrixArr(), arrB = b.getMatrixArr()](double tval, uint16_t tcols, uint16_t trows) {
		return arrA[tcols][trows] + arrB[tcols][trows];
	});
	return *m;
}

matrix matrix::operator-(const matrix & b){
	if (rows != b.rows && cols != b.rows) {
		throw std::exception("Sizes of matrices don't match");
	}
	matrix* m = new matrix(rows, cols);

	m->map([arrA = getMatrixArr(), arrB = b.getMatrixArr()](double tval, uint16_t tcols, uint16_t trows) {
		return arrA[tcols][trows] - arrB[tcols][trows];
	});
	return *m;
}

matrix matrix::operator*(const matrix & b){
	if (rows != b.rows && cols != b.rows) {
		throw std::exception("Sizes of matrices don't match");
	}
	matrix* m = new matrix(rows, cols);

	m->map([arrA = getMatrixArr(), arrB = b.getMatrixArr()](double tval, uint16_t tcols, uint16_t trows) {
		return arrA[tcols][trows] * arrB[tcols][trows];
	});
	return *m;
}

matrix matrix::operator*(const double b){
	matrix* m = new matrix(rows, cols);

	m->map([arrA = getMatrixArr(), b](double tval, uint16_t tcols, uint16_t trows) {
		return arrA[tcols][trows] * b;
	});
	return *m;
}

void matrix::print(){
    std::cout << "==== " << rows << " x " << cols << " ==== \n";
    
    map([&c = cols](double tval,uint16_t trows,uint16_t tcols){
        std::cout << tval << " ";
        if(tcols == c - 1)
            std::cout << "\n";
        return tval;
    });
    
    std::cout << "\n";
}

double** matrix::getMatrixArr() const
{
	return data;
}
