// Matrix class
// Mathematical matrix representation and its operations
// Base matrix representation class
#ifndef MATRIX_H
#define MATRIX_H
#include "Vector.h"
//#include "Polynomial.h"
#include <stdint.h>
template <class U> class Polynomial;
// column vector representation


// CORRECTION:
// MOREOVER DUE TO INTERPOLATION, THE POLYNOMIAL DEGREE CHANGES, SO THE DIMENSION
template <class U>
class Matrix{
public:
    Matrix();
    Matrix(uint8_t dim);
    Matrix(uint8_t dimn, uint8_t dimm);
    Matrix(uint8_t dimm, Vector<U>* vec_array);
    Matrix(const Matrix& orig);
    virtual ~Matrix();
    // Column vector
    void AdjustCCoord(uint8_t i, uint8_t j, U value);
    // Row vector mode
    void AdjustRCoord(uint8_t i, uint8_t j, U value);
    // column size
    uint8_t CSize();
    // row size
    uint8_t RSize();
    // standard column size
    uint8_t Size();
    // works on column vectors
    Vector<U>* operator[](uint8_t ind);
    Vector<U>* GetCVector(uint8_t ind);
    Vector<U>* GetRVector(uint8_t ind);
    Matrix<U>* operator+(Matrix<U>* a);
    Matrix<U>* operator-(Matrix<U>* a);
    U SetRefreshNorm1();
    U GetNorm1();
    U SetRefreshNorm2();
    U GetNorm2();
    U SetRefreshNormInf();
    U GetNormInf();
    uint8_t TransformToJacobian(Matrix<U>* jacobian_matrix);
    uint8_t TransformToHessian();
    uint8_t TransformToLU(uint8_t pdimn, uint8_t pdimm, uint8_t precision,
        Matrix<U>* L_matrix, Matrix<U>* U_matrix);
    uint8_t TransformToQR(uint8_t pdimn, uint8_t pdimm, uint8_t precision,
        Matrix<U>* Q_matrix, Matrix<U>* R_matrix);
    uint8_t TransformToLLT(uint8_t pdimn, uint8_t pdimm, uint8_t precision);
    Vector<U>* SolveEquationSystem();
    U GetSpectralRadius();
    // determinant and Jacobian as well
    static U Get2x2MatrixDeterminant(Matrix<U>* param_matrix);
    static U GetDeterminant(uint8_t pdim, Matrix<U>* param_matrix);
    static Polynomial<U>* GetCharacteristicPolynomial(uint8_t pdimn,
        uint8_t pdimm, Matrix<U>* param_matrix);
    U GetDeterminant(bool is_ch_polynomial_calc);
    Polynomial<U>* GetCharacteristicPolynomial(uint8_t pdim, Matrix<U>* param_matrix);
    uint8_t GetEigenValues(U* eigen_values);
    uint8_t GetEigenVectors(Vector<U>* eigen_vectors);
    uint8_t GrowDim(bool dim_id, int8_t offset_dim_val);
    
private:
        bool quadratic_;
        uint8_t dimn_;
        uint8_t dimm_;
    
        U norm_1_;
        U norm_2_;
        U norm_inf_;

        Vector<U>** data_;
};

template class Matrix<double>;

#endif /* MATRIX_H */

