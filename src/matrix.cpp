#include "matrix.h"

matrix::matrix(uint16_t rows,uint16_t cols){
    this->rows = rows;
    this->cols = cols;
    
    srand(time(NULL));

    data = new float* [rows];

    for(int i = 0; i < rows; i++){
        data[i] = new float[cols];
        for(int j = 0; j < cols; j++){
            data[i][j] = 0;
        }
    }
}

matrix::~matrix(){
    /*for(int i = 0; i < rows; ++i) {
    delete [] data[i];
    }
    delete [] data;*/
}

matrix* matrix::fromArray(std::vector<float> arr){
    auto mT = new matrix(arr.size(),1);
    mT->map([&ArrayR = arr](float val,uint16_t rows,uint16_t cols){
        return ArrayR[rows];
    });
    return mT;
}

std::vector<float> matrix::toArray(matrix* m)
{
	std::vector<float> v;
	m->map([a = &v](float val, uint16_t rows, uint16_t cols) {
		a->push_back(val);
		return val;
	});
	return v;
}

matrix* matrix::dotProduct(matrix* m1, matrix* m2)
{
	if (m1->cols != m2->rows) {
		throw std::exception("Columns of m1 must match rows of m2.");
	}

	matrix* r = new matrix(m1->rows, m2->cols);
	r->map([a = m1->getMatrixArr(),b = m2->getMatrixArr(),aCols = m1->cols](float val, uint16_t rows, uint16_t cols) {
		float sum = 0.0;
		for (int k = 0; k < aCols; k++) {
			sum += a[rows][k] * b[k][cols];
		}
		return sum;
	});
	return r;
}

matrix* matrix::map(matrix* m, std::function<float(float, uint16_t, uint16_t)> func)
{
	matrix* m2 = m->clone();
	m2->map(func);
	return m2;
}

matrix* matrix::transpose(matrix* m)
{
	matrix* m2 = m->clone();
	m2->transpose();
	return m2;
}

void matrix::randomize(matrix* m){
    m->map([](float val,uint16_t rows,uint16_t cols){
        return ((float) rand() / RAND_MAX) * 2 - 1; //! rnd number btw -1 and 1
    });
}

void matrix::map(std::function<float(float,uint16_t,uint16_t)> func){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            float val = data[i][j];
            data[i][j] = func(val,i,j);
        }
    }
}

void matrix::transpose(){
	matrix* m2 = new matrix(cols, rows);
	m2->map([arrM = getMatrixArr()](float tval, uint16_t tcols, uint16_t trows) {
		return arrM[trows][tcols];
	});
	cols = m2->cols;
	rows = m2->rows;
	data = m2->data;
}

matrix matrix::operator+(const matrix & b){
	if (rows != b.rows || cols != b.cols) {
		throw std::exception("Sizes of matrices don't match");
	}
	matrix m = matrix(rows, cols);

	m.map([arrA = getMatrixArr(), arrB = b.getMatrixArr()](float tval, uint16_t tcols, uint16_t trows) {
		return arrA[tcols][trows] + arrB[tcols][trows];
	});
	return m;
}

matrix matrix::operator+=(const matrix& b)
{
	if (rows != b.rows || cols != b.cols) {
		throw std::exception("Sizes of matrices don't match");
	}
	matrix m = matrix(rows, cols);

	m.map([arrA = getMatrixArr(), arrB = b.getMatrixArr()](float tval, uint16_t tcols, uint16_t trows) {
		return arrA[tcols][trows] + arrB[tcols][trows];
	});
	return m;
}

matrix matrix::operator-(const matrix & b){
	if (rows != b.rows || cols != b.cols) {
		throw std::exception("Sizes of matrices don't match");
	}
	matrix* m = new matrix(rows, cols);

	m->map([arrA = getMatrixArr(), arrB = b.getMatrixArr()](float tval, uint16_t tcols, uint16_t trows) {
		return arrA[tcols][trows] - arrB[tcols][trows];
	});
	return *m;
}

matrix matrix::operator*(const matrix & b){
	if (rows != b.rows || cols != b.cols) {
		throw std::exception("Sizes of matrices don't match");
	}
	matrix* m = new matrix(rows, cols);

	m->map([arrA = getMatrixArr(), arrB = b.getMatrixArr()](float tval, uint16_t tcols, uint16_t trows) {
		return arrA[tcols][trows] * arrB[tcols][trows];
	});
	return *m;
}

matrix matrix::operator*(const float b){
	matrix* m = new matrix(rows, cols);

	m->map([arrA = getMatrixArr(), b](float tval, uint16_t tcols, uint16_t trows) {
		return arrA[tcols][trows] * b;
	});
	return *m;
}

matrix* matrix::clone()
{
	return new matrix(*this);
}

void matrix::print(){
    std::cout << "==== " << rows << " x " << cols << " ==== \n";
    
    map([&c = cols](float tval,uint16_t trows,uint16_t tcols){
        std::cout << tval << " ";
        if(tcols == c - 1)
            std::cout << "\n";
        return tval;
    });
    
    std::cout << "\n";
}

float** matrix::getMatrixArr() const
{
	return data;
}
