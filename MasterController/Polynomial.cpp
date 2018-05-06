#include "Polynomial.h"
template <class X>
Polynomial<X>::Polynomial() {

}

template <class X>
Polynomial<X>::Polynomial(uint8_t deg, uint8_t dim) : deg_(deg), dim_(dim) {

}

template <class X>
Polynomial<X>::Polynomial(uint8_t deg, uint8_t dim, Vector<X>* param_data,
        Vector<X>* interval_beginings, Vector<X>* interval_endings) : deg_(deg), dim_(dim),
interval_beginings_(interval_beginings), interval_endings_(interval_endings) {
    dim_ = dim;
    deg_ = deg;

    data_ = (Vector<X>**)malloc(sizeof (Vector<X>**) * dim_);

    for (uint8_t i = 0; i < dim_ + 1 - 1; ++i) {
        data_[i] = new Vector<X>(param_data[i]);
    }
}

template <class X>
Polynomial<X>::Polynomial(const Polynomial& orig) {

}

template <class X>
Polynomial<X>::~Polynomial() {
}

template <class X>
bool Polynomial<X>::IsPrimitivePolynomial() {
    for (uint8_t i = 0; i < dim_; ++i) {
        for (uint8_t j = 0; j < deg_; ++j) {
            for (uint8_t k = 0; k < j; ++k) {
                if (0 == Geometry<X>::flmod((*data_[i])[j], (*data_[i])[k])) {
                    return false;
                }
            }
        }
    }

    return true;
}

template <class X>
uint8_t Polynomial<X>::GetPolynomialDegree() {
    return deg_;
}

template <class X>
Polynomial<X>* Polynomial<X>::Derivate() {
    Polynomial<X>* res = new Polynomial<X>(deg_, dim_);


    return res;
}

template <class X>
Polynomial<X>* Polynomial<X>::Derivate(uint8_t coord) {
    Polynomial<X>* res = new Polynomial<X>(deg_, dim_);


    return res;
}

template <class X>
Polynomial<X>* Polynomial<X>::Integrate() {
    Polynomial<X>* res = new Polynomial<X>(deg_, dim_);


    return res;
}

template <class X>
Polynomial<X>* Polynomial<X>::Integrate(uint8_t coord) {
    Polynomial<X>* res = new Polynomial<X>(deg_ + 1, dim_);


    return res;
}

template <class X>
X Polynomial<X>::LineIntegral(Vector<X>* a, Vector<X>* b) {// a, b: Vector<X>(dim_ - 1)
    //Vector<X>* a(deg_, dim_ - 1)


    X res = 0.0;



    return res;
}

template <class X>
X Polynomial<X>::SurfaceIntegral(Vector<X>** bounds) {// bounds: Vector<X>(dim_ - 1)
    X res = 0.0;


    return res;
}

template <class X>
X Polynomial<X>::VolumeIntegral(Vector<X>** bounds) {// bounds: Vector<X>(dim_ - 1)
    X res = 0.0;


    return res;
}

template <class X>
Vector<X>** Polynomial<X>::GetRoots(Vector<X>* a, Vector<X>* b) {// a, b: Vector<X>(dim_ - 1)
    Vector<X>** res; // = new Vector<X>(dim_);


    return res;
}

template <class X>
Vector<X>** Polynomial<X>::GetMaximums(Vector<X>* a, Vector<X>* b) {// a, b: Vector<X>(dim_ - 1)
    Vector<X>** res; // = new Vector<X>(dim_);


    return res;
}

template <class X>
Vector<X>** Polynomial<X>::GetMinimums(Vector<X>* a, Vector<X>* b) {// a, b: Vector<X>(dim_ -1)
    Vector<X>** res; // = new Vector<X>(dim_);



    return res;
}

template <class X>
Vector<X>** Polynomial<X>::GetInflexions(Vector<X>* a, Vector<X>* b) {// a, b: Vector<X>(dim_ - 1)
    Vector<X>** res; // = new Vector<X>(dim_);



    return res;
}

template <class X>
Vector<X>* Polynomial<X>::GetGradientRngVal(Vector<X>* val) {// val: Vector<X>(dim_)
    Vector<X>* res = new Vector<X>(dim_);
    for (uint8_t i = 0; i < dim_; ++i) {
        // memory leak, lack of deletion
        (*res)[i] = this->Derivate(i)->getRngValue(dim_, deg_, (*val)[i]);
    }
    return res;
}

template <class X>
X Polynomial<X>::GetDmnValue() {
    // Horner order solution
    X res;
    return res;
}

template <class X>
X Polynomial<X>::GetRngValue(Vector<X>* values) {
    X res = 0.0;

    for (uint8_t i = 0; i < dim_; ++i) {
        for (uint8_t j = 0; j < deg_; ++j) {
            res += (*data_[i])[j] * pow((*values)[i], j);
        }
    }

    return res;
}

template <class X>
X Polynomial<X>::GetRngValue(uint8_t pdim, uint8_t pdeg, X val) {
    X res = 0.0;

    for (uint8_t i = 0; i < pdeg; ++i) {
        res += (*data_[i])[pdim] * pow(val, pdim);
    }

    return res;
}

template <class X>
Polynomial<X>* Polynomial<X>::Interpolate(Vector<X>* control_points) {// control_points: Vector<X>(deg_)
    // using CUBIC SPLINE interpolation polynomial
    Polynomial<X>* res = new Polynomial<X>(deg_, dim_);


    return res; // process has ended successfully
}

template <class X>
Polynomial<X>* Polynomial<X>::Regression(Vector<X>* dispersion_set) {// dispersion_set: Vector<X>(dim_)
    Polynomial<X>* res = new Polynomial<X>(deg_, dim_);


    // using linear regression
    // process has ended successfully if return value is not null
    return res;
}

template <class X>
Matrix<X>* Polynomial<X>::GetResultantMatrix(uint8_t deg, uint8_t dim, Polynomial<X>* param_polynomial) {
    Matrix<X>* res = new Matrix<X>(deg, deg);

    return res;
}

template <class X>
Vector<X>* Polynomial<X>::GetIntervalBeginings() {
    return interval_beginings_;
}//Vector<X>(dim_ - 1)

template <class X>
Vector<X>* Polynomial<X>::GetIntervalEndings() {
    return interval_endings_;
}

template <class X>
Vector<X>* Polynomial<X>::operator[](uint8_t ind) {//Vector<X>(deg_)
    if (dim_ > ind) {
        return data_[ind];
    } else {
        return data_[ind];
    }
}

template <class X>
Polynomial<X>* Polynomial<X>::operator+(Polynomial<X>* a) {
    Polynomial<X>* res = new Polynomial<X>(deg_, dim_);

    return res;
}

template <class X>
Polynomial<X>* Polynomial<X>::operator-(Polynomial<X>*a) {
    Polynomial<X>* res = new Polynomial<X>(deg_, dim_);

    return res;
}

template <class X>
Polynomial<X>* Polynomial<X>::operator*(Polynomial<X>* a) {
    Polynomial<X>* res = new Polynomial<X>(deg_, dim_);

    return res;
}

template <class X>
Polynomial<X>* Polynomial<X>::operator/(Polynomial<X>* a) {
    Polynomial<X>* res = new Polynomial<X>(deg_, dim_);

    return res;
}

template <class X>
uint8_t Polynomial<X>::Parameterize() {
    // Transform polynomial(including more than dim(2))
    // into separated coordinate component-based functions
    // 

    return 0;
}

template <class X>
uint8_t Polynomial<X>::Deparameterize() {


    return 0;
}

template <class X>
bool Polynomial<X>::GetIsParametereized() {
    return is_parameterized_;
}

template <class X>
uint8_t Polynomial<X>::SetIsParameterized(bool val) {
    is_parameterized_ = val;
}