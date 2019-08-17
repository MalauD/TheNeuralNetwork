#include "matrix.h"

int main(){
    matrix* m1 = new matrix(10,2);
	matrix::randomize(m1);
	m1->print();
	m1->transpose();
	m1->print();


    return 0;
}   