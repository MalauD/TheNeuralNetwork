#include <stdint.h>
#include <iostream>
#include <vector>
#include <functional>
#include <time.h>
#include <stdexcept>

class matrix {
    private:
        uint16_t rows,cols;
        double **data;
    public:
        matrix(uint16_t rows,uint16_t cols);
        ~matrix();

        static matrix* fromArray(std::vector<double> arr);
        static void randomize(matrix* m);
        

        matrix operator+ (const matrix& b);
        matrix operator- (const matrix& b);
        matrix operator* (const matrix& b);
        matrix operator* (const double b);

		void map(std::function<double(double, uint16_t, uint16_t)> func);
        void print();
		void transpose();

		double** getMatrixArr() const;
};