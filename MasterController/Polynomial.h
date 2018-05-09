// REWRITE TO GPU
// Base polynomial representation
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <stdint.h>
#include "Vector.h"
#include "Geometry.h"
#include "Matrix.h"
// Multidimensional(multivariable) polynomial

template <class X> 
class Polynomial{
public:
    Polynomial();
    Polynomial(uint8_t deg, uint8_t dim);
    Polynomial(uint8_t deg, uint8_t dim, Vector<X>* param_data,
        Vector<X>* interval_beginings, Vector<X>* interval_endings);
    Polynomial(const Polynomial& orig);
    virtual ~Polynomial();
    bool IsPrimitivePolynomial();
    uint8_t GetPolynomialDegree();
    Polynomial<X>* Derivate();
    Polynomial<X>* Derivate(uint8_t coord);
    Polynomial<X>* Integrate();
    Polynomial<X>* Integrate(uint8_t coord);
    X LineIntegral(Vector<X>* a, Vector<X>* b);
    X SurfaceIntegral(Vector<X>** bounds);
    X VolumeIntegral(Vector<X>** bounds);
    Vector<X>** GetRoots(Vector<X>* a, Vector<X>* b);
    Vector<X>** GetMaximums(Vector<X>* a, Vector<X>* b);
    Vector<X>** GetMinimums(Vector<X>* a, Vector<X>* b);
    Vector<X>** GetInflexions(Vector<X>* a, Vector<X>* b);
    Vector<X>* GetGradientRngVal(Vector<X>* val);
    X GetDmnValue();
    X GetRngValue(Vector<X>* values);
    X GetRngValue(uint8_t pdim, uint8_t pdeg, X val);
    Polynomial<X>* Interpolate(Vector<X>* control_points);
    Polynomial<X>* Regression(Vector<X>* dispersion_set);
    Matrix<X>* GetResultantMatrix(uint8_t deg, uint8_t dim, Polynomial<X>* param_polynomial);
    Vector<X>* GetIntervalBeginings();
    Vector<X>* GetIntervalEndings();
    Vector<X>* operator[](uint8_t ind);
    Polynomial<X>* operator+(Polynomial<X>* a);
    Polynomial<X>* operator-(Polynomial<X>*a);
    Polynomial<X>* operator*(Polynomial<X>* a);
    Polynomial<X>* operator/(Polynomial<X>* a);
    uint8_t Parameterize();
    uint8_t Deparameterize();
    bool GetIsParametereized();
    uint8_t SetIsParameterized(bool val);
private:
    
    uint8_t deg_;
    uint8_t dim_;
    
    bool is_parameterized_;
    
    // Each vector represents a polynomial
    // Starting from the constant
    // toward the highest degree monom
    Vector<X>** data_;// dim_ + 1 - 1 //Vector<X>(deg_)[]
    
    // defining interpretation intervals
    // according to number of dimensions
    Vector<X>* interval_beginings_;//Vector<X>(dim_ - 1)
    Vector<X>* interval_endings_;
};
template class Polynomial<double>;
// problem: 
#endif /* POLYNOMIAL_H */