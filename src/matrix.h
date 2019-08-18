#include <stdint.h>
#include <iostream>
#include <vector>
#include <functional>
#include <time.h>
#include <stdexcept>

#pragma once

class matrix {
    private:
        uint16_t rows,cols;
        double **data;
    public:
        matrix(uint16_t rows,uint16_t cols);
        ~matrix();

        static matrix* fromArray(std::vector<double> arr);
        static void randomize(matrix* m);
		static std::vector<double> toArray(matrix* m);
		static matrix* dotProduct(matrix* m1, matrix* m2);
		static matrix* map(matrix* m, std::function<double(double, uint16_t, uint16_t)> func);
		static matrix* transpose(matrix* m);

        matrix operator+ (const matrix& b);
		matrix operator+= (const matrix& b);
        matrix operator- (const matrix& b);
        matrix operator* (const matrix& b);
        matrix operator* (const double b);

		matrix* clone();

		void map(std::function<double(double, uint16_t, uint16_t)> func);
        void print();
		void transpose();

		double** getMatrixArr() const;
};