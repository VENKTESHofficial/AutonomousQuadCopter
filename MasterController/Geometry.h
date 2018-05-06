// REWRITE TO GPU
#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <stdint.h>
template <class T>
class Geometry {
public:
    Geometry();
    Geometry(const Geometry& orig);
    virtual ~Geometry();
    static T ln();
    // SPECIAL GPU INSTRUCTION, HARDWARE ACCELEARTED
    // iterative method instead of recursive due to pipeline invocation
    static T fact(uint64_t fact);
    // SPECIAL CPU INSTRUCTION, HARDWARE ACCELERATED
    static T sin(T val, uint8_t precision);
    // SPECIAL GPU INSTRUCTION, HARDWARE ACCELERATED
    static T cos(T val, uint8_t precision);
    // SPECIAL GPU INSTRUCTION, HARDWARE ACCELERATED
    static T tan(T val, uint8_t precision);
    // SPECIAL GPU INSTRUCTION, HARDWARE ACCELERATED
    static T cotan(T val, uint8_t precision);
    // SPECIAL GPU INSTRUCTION, HARDWARE ACCELERATED
    static T atan();
    // SPECIAL GPU INSTRUCTION, HARDWARE ACCELERATED
    static T atan2(T w, T h);
    static T atan3(T w, T h, T l);
    static uint64_t flmod(T a, T b);

    // Radian degree conversions
    static double DEG0 = 0;
    static double DEG90 = 3.1415 / 2;
    static double DEG180 = 3.1415;
    static double PI = DEG180;
    static double DEG270 = DEG90 + DEG180;

    static double flmod(T* a, T* b);
private:

};

#endif /* GEOMETRY_H */

