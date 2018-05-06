#ifndef VECTOR_H
#define VECTOR_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Vector class
// Mathematical vector representation and its operations
// REWRITE TO GPU
// Base vector representation
template <class T>
class Matrix;
template <class T>
class Vector;

template <class T>
class Vector {
public:
    Vector();
    Vector(uint8_t dim);
    Vector(uint8_t dim, T* param_data);
    Vector(uint8_t dim, Vector<T> param_data);
    Vector(const Vector& orig);
    virtual ~Vector();
    T** GetData();
    T GetX();
    T GetY();
    T GetZ();
    T GetCoord(uint8_t ind);
    // for matrix partitioning at determinant calculation
    // and for Gauss-elimination
    Vector<T>* GetVecExcCoord(uint8_t ind);
    T GetDist();
    T GetDist(Vector<T>& param_data);
    T GetPlanarDist();
    T GetPlanarDist(Vector& param_data);
    void AdjustCoord(uint8_t ind, T value);
    Vector<T>* operator+(Vector<T>* a);
    Vector<T>* operator-(Vector<T>* a);
    // Vector<T>* operator+(Vector<T> a);
    // Vector<T>* operator-(Vector<T> a);
    
    // dot product
    T operator*(Vector<T>* a);
    Vector<T>* operator*(T& a);
    T& operator[](uint8_t i);
    bool operator<=(Vector<T>* param_data);
    bool operator>=(Vector<T>* param_data);
    bool operator<(Vector<T>* param_data);
    bool operator>(Vector<T>* param_data);
    Matrix<T>* operatorX(Vector<T>* a, Vector<T>* b);
    T SetRefreshNorm1();
    T GetNorm1();
    T SetRefreshNorm2();
    T GetNorm2();
    T SetRefreshNormInf();
    T GetNormInf();
    T GetDimension();
    static Vector<T>* Triangularization(uint8_t dim_bound,
        uint8_t* weight_val_indexes, Vector<T>***& param_vectors);
    uint8_t ChangeDim(int8_t offset_dim_val);
    uint8_t PushBack(T* param_data);
private:
    uint8_t dim_;
    T** data_;

protected:
    T norm_1_;
    T norm_2_;
    T norm_inf_;
};

template class Vector<uint8_t>;
template class Vector<uint16_t>;
template class Vector<uint32_t>;
template class Vector<uint64_t>;
template class Vector<float>;
template class Vector<double>;
template class Vector<void*>
#endif /* VECTOR_H */

