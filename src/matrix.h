#include <stdint.h>
#include <iostream>
#include <vector>
#include <functional>
#include <time.h>

class matrix {
    private:
        int16_t rows,cols;
        double **data;
    public:
        matrix(int16_t rows,int16_t cols);
        ~matrix();
        static matrix* fromArray(std::vector<double> arr);
        static matrix randomize(matrix* m);
        void map(std::function<double(double,int16_t,int16_t)> func);
        static matrix transpose(matrix* m);
        matrix operator+ (const matrix& b);
        matrix operator- (const matrix& b);
        matrix operator* (const matrix& b);
        matrix operator* (const double b);
        void print();
};