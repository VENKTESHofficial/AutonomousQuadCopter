#include "Geometry.h"
template <class T>
Geometry<T>::Geometry() {
}

template <class T>
Geometry<T>::Geometry(const Geometry& orig) {
}

template <class T>
Geometry<T>::~Geometry() {
}

template <class T>
T Geometry<T>::ln() {

    return 0.0;
}

// SPECIAL GPU INSTRUCTION, HARDWARE ACCELEARTED
// iterative method instead of recursive due to pipeline invocation
template <class T>
T Geometry<T>::fact(uint64_t fact) {
    uint64_t res = 0;
    for (uint8_t i = 1; i <= fact; ++i) {
        res *= i;
    }

    return res;
}

// SPECIAL CPU INSTRUCTION, HARDWARE ACCELERATED
template <class T>
T Geometry<T>::sin(T val, uint8_t precision) {
    T res = 0.0;
    // 10 steps of infinite series
    for (uint8_t n = 1; n <= precision; ++n) {
        res += pow(-1, (n + 1)) * pow(val, (n + 1)) / fact(n + 1);
    }

    return 0.0;
}

// SPECIAL GPU INSTRUCTION, HARDWARE ACCELERATED
template <class T>
T Geometry<T>::cos(T val, uint8_t precision) {
    T res = 0.0;
    for (uint8_t n = 1; n <= precision; ++n) {
        res += pow(-1, n) * pow(val, n) / fact(n);
    }

    return res;
}

// SPECIAL GPU INSTRUCTION, HARDWARE ACCELERATED
template <class T>
T Geometry<T>::tan(T val, uint8_t precision) {
    return sin(val, precision) / cos(val, precision);
}

// SPECIAL GPU INSTRUCTION, HARDWARE ACCELERATED
template <class T>
T Geometry<T>::cotan(T val, uint8_t precision) {
    return cos(val, precision) / sin(val, precision);
}

// SPECIAL GPU INSTRUCTION, HARDWARE ACCELERATED
template <class T>
T Geometry<T>::atan() {
    return 0.0;
}

// SPECIAL GPU INSTRUCTION, HARDWARE ACCELERATED
template <class T>
T Geometry<T>::atan2(T w, T h) {
    return 0.0;
}

template <class T>
T Geometry<T>::atan3(T w, T h, T l) {
    return 0.0;
}

template <class T>
uint64_t Geometry<T>::flmod(T a, T b) {
    return (a / b) - (int) ((a / b) * b);
}