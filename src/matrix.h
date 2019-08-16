#include <stdint.h>
#include <iostream>

class matrix {
    private:
        int16_t rows,cols;
        double **data;
    public:
        matrix(int16_t rows,int16_t cols);
        static matrix fromArray(double arr[]);
        static matrix randomize(matrix* m);
        static matrix map(matrix* m,void* func);
        static matrix transpose(matrix* m);
        matrix operator+ (const matrix& b);
        matrix operator- (const matrix& b);
        matrix operator* (const matrix& b);
        matrix operator* (const double b);
        friend std::ostream& operator<<(std::ostream &strm, const matrix &a);        
};