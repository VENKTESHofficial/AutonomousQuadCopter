#include "Matrix.h"

template <class U>
Matrix<U>::Matrix() {

}

template <class U>
Matrix<U>::Matrix(uint8_t dim) {
    quadratic_ = true;
    dimn_ = dim;
    dimm_ = dim;
    data_ = (Vector<U>**)malloc(sizeof (Vector<U>*) * dimm_);
    for (uint8_t i = 0; i < dimm_; ++i) {
        data_[i] = new Vector<U>(dimn_);
    }
}

template <class U>
Matrix<U>::Matrix(uint8_t dimn, uint8_t dimm) {
    quadratic_ = false;
    dimn_ = dimn;
    dimm_ = dimm;
    data_ = (Vector<U>**)malloc(sizeof (Vector<U>*) * dimm_);
    for (uint8_t i = 0; i < dimm_; ++i) {
        data_[i] = new Vector<U>(dimn_);
    }
}

template <class U>
Matrix<U>::Matrix(uint8_t dimm, Vector<U>* vec_array) {
    dimn_ = dimm;
    dimm_ = dimm;

    data_ = (Vector<U>**)malloc(sizeof (Vector<U>*) * dimm_);

    for (uint8_t i = 0; i < dimm_; ++i) {
        data_[i] = new Vector<U>(vec_array[i]);
    }
}

template <class U>
Matrix<U>::Matrix(const Matrix& orig) {
}

template <class U>
Matrix<U>::~Matrix() {

}

// Column vector

template <class U>
void Matrix<U>::AdjustCCoord(uint8_t i, uint8_t j, U value) {
    data_[i]->AdjustCoord(j, value);
}

// Row vector mode

template <class U>
void Matrix<U>::AdjustRCoord(uint8_t i, uint8_t j, U value) {
    data_[j]->AdjustCoord(i, value);
}

// column size

template <class U>
uint8_t Matrix<U>::CSize() {
    return dimn_;
}

// row size

template <class U>
uint8_t Matrix<U>::RSize() {
    return dimm_;
}

// standard column size

template <class U>
uint8_t Matrix<U>::Size() {
    return dimn_;
}

// works on column vectors

template <class U>
Vector<U>* Matrix<U>::operator[](uint8_t ind) {
    if (dimn_ > ind)
        return data_[ind];
    else
        return data_[0];
}

template <class U>
Vector<U>* Matrix<U>::GetCVector(uint8_t ind) {
    if (dimn_ > ind)
        return data_[ind];
    else
        return NULL;
}

template <class U>
Vector<U>* Matrix<U>::GetRVector(uint8_t ind) {
    if (dimm_ > ind) {
        Vector<U>* res = new Vector<U>(dimm_);

        for (uint8_t i = 0; i < dimm_; ++i) {
            res->AdjustCoord(i, data_[i]->GetCoord(ind));
        }

        return res;
    } else
        return NULL;
}

template <class U>
Matrix<U>* Matrix<U>::operator+(Matrix<U>* a) {
    Matrix<U>* res = new Matrix<U>();

    for (uint8_t i = 0; i < dimm_; ++i) {
        (*res)[i] = (*data_[i]) + (*a)[i];
    }

    return res;
}

template <class U>
Matrix<U>* Matrix<U>::operator-(Matrix<U>* a) {
    Matrix<U>* res = new Matrix<U>();

    for (uint8_t i = 0; i < dimm_; ++i) {
        (*res)[i] = (*data_[i]) + (*a)[i];
    }

    return res;
}

template <class U>
U Matrix<U>::SetRefreshNorm1() {
    U res = 0.0;
    U curr;
    for (uint8_t i = 0; i < dimn_; ++i) {
        curr = 0.0;
        for (uint8_t j = 0; j < dimm_; ++j) {
            curr += abs((*data_[i])[j]);
        }

        if (curr > res) {
            res = curr;
        }
    }

    norm_1_ = res;

    return norm_1_;
}

template <class U>
U Matrix<U>::GetNorm1() {
    return norm_1_;
}

template <class U>
U Matrix<U>::SetRefreshNorm2() {
    U res = 0.0;
    for (uint8_t i = 0; i < dimn_; ++i) {
        for (uint8_t j = 0; j < dimm_; ++j) {
            res += pow((*data_[i])[j], 2);
        }
    }

    norm_2_ = sqrt(res);

    return norm_2_;
}

template <class U>
U Matrix<U>::GetNorm2() {
    return norm_2_;
}

template <class U>
U Matrix<U>::SetRefreshNormInf() {
    U res = 0.0;
    for (uint8_t i = 0; i < dimm_; ++i) {
        for (uint8_t j = 0; j < dimn_; ++j) {
            if ((*data_[j])[i] > res) {
                res = (*data_[j])[i];
            }
        }
    }

    norm_inf_ = res;

    return norm_inf_;
}

template <class U>
U Matrix<U>::GetNormInf() {
    return norm_inf_;
}

template <class U>
uint8_t Matrix<U>::TransformToJacobian(Matrix<U>* jacobian_matrix) {
    // getting the gradient functions of the row vectors
    for(uint8_t i = 0; i < dimn_; ++i){
        for(uint8_t j = 0; j < dimm_; ++j){
            jacobian_matrix[i][j] = 
        }
    }
    return 0;
}

template <class U>
uint8_t Matrix<U>::TransformToHessian() {
    for(uint8_t i = 0; i < dimn_; ++i){
        for(uint8_t j = 0; j < dimm_; ++j){
            
        }
    }
    return 0; // 0 - transformation was successful
}

template <class U>
uint8_t Matrix<U>::TransformToLU(uint8_t pdimn, uint8_t pdimm, uint8_t precision,
        Matrix<U>* L_matrix, Matrix<U>* U_matrix) {
    // Using Gaussian distribution method


    return 0;
}

template <class U>
uint8_t Matrix<U>::TransformToQR(uint8_t pdimn, uint8_t pdimm, uint8_t precision,
        Matrix<U>* Q_matrix, Matrix<U>* R_matrix) {
    // using Householder transformation

    return 0; // Transformation was successful
}

template <class U>
uint8_t Matrix<U>::TransformToLLT(uint8_t pdimn, uint8_t pdimm, uint8_t precision) {
    return 0;
}

template <class U>
Vector<U>* Matrix<U>::SolveEquationSystem() {
    // Gauss-elimination
}

template <class U>
U Matrix<U>::GetSpectralRadius() {
    return 0.0;
}

// determinant and Jacobian as well

template <class U>
U Matrix<U>::Get2x2MatrixDeterminant(Matrix<U>* param_matrix) {
    return (*(*param_matrix)[0])[1] * (*(*param_matrix)[1])[0]
            - (*(*param_matrix)[0])[0] * (*(*param_matrix)[1])[1];
}

template <class U>
U Matrix<U>::GetDeterminant(uint8_t pdim, Matrix<U>* param_matrix) {
    // +-, chess-rule, Laplace expansion
    U partial_res = 0.0;
    if (param_matrix->Size() <= 2) {
        return Get2x2MatrixDeterminant(param_matrix);
    } else {

        for (uint8_t i = 0; i < pdim; ++i) {
            Matrix<U>* p_matrix = new Matrix<U>(pdim - 1);

            for (uint8_t j = 0; j < pdim; ++j) {
                if (i == j) ++j;

                p_matrix[j] = (*param_matrix)[j]->GetVecExcCoord(i);
            }

            partial_res += pow(-1, i) * GetDeterminant(pdim, p_matrix);
        }

        return partial_res;
    }
}

template <class U>
Polynomial<U>* Matrix<U>::GetCharacteristicPolynomial(uint8_t pdimn,
        uint8_t pdimm, Matrix<U>* param_matrix) {


    Polynomial<U>* partial_res_polynomial = new Polynomial<U>(pdimn, pdimm);

    return partial_res_polynomial;
}

template <class U>
U Matrix<U>::GetDeterminant(bool is_ch_polynomial_calc) {
    return GetDeterminant(this);
}

template <class U>
Polynomial<U>* Matrix<U>::GetCharacteristicPolynomial(uint8_t pdim, Matrix<U>* param_matrix) {
    // calls the getDeterminant()
    Polynomial<U>* characteristic_polynomial
            = new Polynomial<U>(pdim, pdim);

    characteristic_polynomial = GetCharacteristicPolynomial(pdim, param_matrix);

    return characteristic_polynomial;
}

template <class U>
uint8_t Matrix<U>::GetEigenValues(U* eigen_values) {
    U* res;


    return 0;
}

template <class U>
uint8_t Matrix<U>::GetEigenVectors(Vector<U>* eigen_vectors) {
    Vector<U>* res = new Vector<U>(dimn_);


    return 0;
}

template <class U>
uint8_t Matrix<U>::GrowDim(bool dim_id, int8_t offset_dim_val) {
    // dim_id : identifies the dimension
    

    return 0;
}
