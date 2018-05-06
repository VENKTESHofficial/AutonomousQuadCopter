#include "Vector.h"

template <class T>
Vector<T>::Vector() {

}

template <class T>
Vector<T>::Vector(uint8_t dim) {
    dim_ = dim;

    data_ = (T**) malloc(sizeof (T**) * dim_);

    for (uint8_t i = 0; i < dim_; ++i) {
        *data_[i] = 0;
    }
}

template <class T>
Vector<T>::Vector(uint8_t dim, T* param_data) {
    dim_ = dim;

    data_ = (T**) malloc(sizeof (T**) * dim_);

    for (uint8_t i = 0; i < dim_; ++i) {
        *data_[i] = param_data[i];
    }
}

template <class T>
Vector<T>::Vector(uint8_t dim, Vector<T> param_data) {

}

template <class T>
Vector<T>::Vector(const Vector& orig) {

};

template <class T>
Vector<T>::~Vector() {

}

template <class T>
T** Vector<T>::GetData() {
    return data_;
}

template <class T>
T Vector<T>::GetX() {
    if (dim_ > 0)
        return *data_[0];
    else
        return 0.0;
}

template <class T>
T Vector<T>::GetY() {
    if (dim_ > 1)
        return *data_[1];
    else
        return 0.0;
}

template <class T>
T Vector<T>::GetZ() {
    if (dim_ > 2)
        return *data_[2];
    else
        return 0.0;
}

template <class T>
T Vector<T>::GetCoord(uint8_t ind) {
    if (dim_ > ind)
        return *data_[ind];
    else
        return 0.0;
}

// for matrix partitioning at determinant calculation
// and for Gauss-elimination

template <class T>
Vector<T>* Vector<T>::GetVecExcCoord(uint8_t ind) {
    Vector<T>* res = new Vector<T>(dim_ - 1);
    for (uint8_t i = 0; i < dim_; ++i) {
        if (i == ind)++i;

        (*res)[i] = (*data_[i]);
    }

    return res;
}

template <class T>
T Vector<T>::GetDist() {
    T res = 0.0;
    // sqrt and pow must be overridden to own type
    for (uint8_t i = 0; i < dim_; ++i) {
        res += pow((*data_[i]), 2);
    }

    return sqrt(res);
}

template <class T>
T Vector<T>::GetDist(Vector<T>& param_data) {//param_data : Vector<T>(dim)
    T res = 0.0;
    // sqrt and pow must be overridden to own type
    for (uint8_t i = 0; i < dim_; ++i) {
        res += pow((*data_[i] - param_data[i]), 2);
    }

    return sqrt(res);
}

template <class T>
T Vector<T>::GetPlanarDist() {
    return sqrt(pow(*data_[0], 2)
            + pow(*data_[1], 2));
}

template <class T>
T Vector<T>::GetPlanarDist(Vector& param_data) {
    return sqrt(pow((*data_[0] - param_data[0]), 2)
            + pow((*data_[1] - param_data[1]), 2));
}

template <class T>
void Vector<T>::AdjustCoord(uint8_t ind, T value) {
    if (dim_ > ind)
        *data_[ind] = value;
}

template <class T>
Vector<T>* Vector<T>::operator+(Vector<T>* a) {// a : Vector<T>(dim)
    Vector<T>* res = new Vector<T>(dim_);
    for (uint8_t i = 0; i < dim_; ++i) {
        (*res)[i] = (*a)[i] + (*data_[i]);
    }
    return res;
}

template <class T>
Vector<T>* Vector<T>::operator-(Vector<T>* a) {
    Vector<T>* res = new Vector<T>(dim_);
    for (uint8_t i = 0; i < dim_; ++i) {
        (*res)[i] = (*a)[i] - (*data_[i]);
    }

    return res;
}

/*
template <class T>
Vector<T>* Vector<T>::operator+(Vector<T> a){// a : Vector<T>(dim)
    Vector<T>* res = new Vector<T>(dim_);
    for(uint8_t i = 0; i < dim_; ++i){
        (*res)[i] = a[i] + (*data_[i]);
    }
    return res;
}
 */

/*
template <class T>
Vector<T>* Vector<T>::operator-(Vector<T> a){
    Vector<T>* res = new Vector<T>(dim_);
    for(uint8_t i = 0; i < dim_; ++i){
        (*res)[i] = a[i] - (*data_[i]);
    }
        
    return res;
}*/

// dot product

template <class T>
T Vector<T>::operator*(Vector<T>* a) {// a : Vector<T>(dim_)
    T res = 0.0;
    for (uint8_t i = 0; i < dim_; ++i) {
        res += (*a)[i] * (*data_[i]);
    }

    return res;
}

template <class T>
Vector<T>* Vector<T>::operator*(T& a) {
    Vector<T>* res = new Vector<T>(dim_);
    for (uint8_t i = 0; i < dim_; ++i) {
        (*res)[i] *= a;
    }

    return res;
}

template <class T>
T& Vector<T>::operator[](uint8_t i) {
    return *data_[i];
}

template <class T>
bool Vector<T>::operator<=(Vector<T>* param_data){
    return true;
}

template <class T>
bool Vector<T>::operator>=(Vector<T>* param_data){
    return true;
}

template <class T>
bool Vector<T>::operator<(Vector<T>* param_data){
    return true;
}

template <class T>
bool Vector<T>::operator>(Vector<T>* param_data){
    return true;
}

template <class T>
Matrix<T>* Vector<T>::operatorX(Vector<T>* a, Vector<T>* b) {
    Matrix<T>* res = new Matrix<T>(dim_);
    for (uint8_t i = 0; i < dim_; ++i) {
        for (uint8_t j = 0; j < dim_; ++j) {
            (*res)[i][j] = (*a)[i]; // * (*b)[j];
        }
    }

    return res;
}

template <class T>
T Vector<T>::SetRefreshNorm1() {
    T res = 0.0;
    for (uint8_t i = 0; i < dim_; ++i) {
        if (*data_[i] > res) {
            res = abs(*data_[i]);
        }
    }

    norm_1_ = res;
    return norm_1_;
}

template <class T>
T Vector<T>::GetNorm1() {
    return norm_1_;
}

template <class T>
T Vector<T>::SetRefreshNorm2() {
    T res = 0.0;
    for (uint8_t i = 0; i < dim_; ++i) {
        res += pow(*data_[i], 2);
    }

    norm_2_ = sqrt(res);

    return norm_2_;
}

template <class T>
T Vector<T>::GetNorm2() {
    return norm_2_;
}

template <class T>
T Vector<T>::SetRefreshNormInf() {
    T res = 0.0;
    for (uint8_t i = 0; i < dim_; ++i) {
        res += (*data_[i]);
    }

    norm_inf_ = res;

    return norm_inf_;
}

template <class T>
T Vector<T>::GetNormInf() {
    return norm_inf_;
}

template <class T>
T Vector<T>::GetDimension() {
    return dim_;
}

template <class T>
Vector<T>* Vector<T>::Triangularization(uint8_t dim_bound,
        uint8_t* weight_val_indexes, Vector<T>***& param_vectors) {// param_vectors : Vector<T>(dim_)
    Vector<T>* res = new Vector<T>(dim_bound);

    uint8_t sizeof_weight_val_indexes = sizeof (weight_val_indexes);
    uint16_t sizeof_param_vectors = sizeof (param_vectors);
    for (uint16_t i = 0; i < sizeof_param_vectors; ++i) {// go along density layers
        uint16_t sizeof_density_layer = sizeof (param_vectors[i]);
        for (uint16_t j = 0; j < sizeof_density_layer; ++j) {
            for (uint16_t k = 0; k < dim_bound; ++k) {
                for (uint16_t l = 0; l < sizeof_weight_val_indexes; ++l) {
                    (*res)[i] += ((*param_vectors[i][j])[k]
                            * (*param_vectors[i][j])[weight_val_indexes[l]]);
                }
            }
        }

        (*res)[i] /= sizeof_density_layer;
    }

    delete[] param_vectors;
    return res;
}

template <class T>
uint8_t Vector<T>::ChangeDim(int8_t offset_dim_val) {
    // negative values shrink the dimension value
    // positive values grow the dimension value



    return 0;
}

template <class T>
uint8_t Vector<T>::PushBack(T* param_data){
    data_ = (T**)realloc(data_, (sizeof(data_) + 1) * sizeof(param_data));
    ++dim_;
    data_[dim_ - 1] = param_data;
    return 0;
} 