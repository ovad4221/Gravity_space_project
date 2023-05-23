#include <iostream>
#include <ostream>
#include <istream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <initializer_list>
#include "../headers_oop/vector.h"

using std::vector;
using std::istream;
using std::ostream;
using std::cout;
using std::endl;


Vector::Vector(vector<double> &vect): vect(vect) {};
Vector::Vector(unsigned int n): vect(n, 0) {};
Vector::Vector(std::initializer_list<double> l): vect(l) {};
Vector::Vector(): Vector(6) {};

Vector::~Vector() = default;

double Vector::module_v() const {
    double sq_sum = 0;
    for (unsigned int i = 0; i < vect.size(); ++i) {
        sq_sum += pow(vect[i], 2);
    }
    return std::sqrt(sq_sum);
}

unsigned int Vector::getSize() const {
    return vect.size();
}

int Vector::getValue(unsigned int i) const {
    return vect[i];
}

double& Vector::operator[] (unsigned int i) {
    return vect[i];
}

void Vector::setValue(unsigned int i, int value) {
    vect[i] = value;
}

bool Vector::operator== (const Vector& v2) const {
    if (v2.vect.size() != vect.size()) {
        return false;
    }
    for (unsigned int i = 0; i < vect.size(); ++i) {
        if (vect[i] != v2.vect[i]) {
            return false;
        }
    }
    return true;
}

bool Vector::operator!= (const Vector& v2) const {
    return !(*this == v2);
}

Vector Vector::operator+ (const Vector& v2) const {
    if (v2.vect.size() != vect.size()) {
        cout << "ERROR +: vectors of different dimensions \n";
        return *this;
    }
    Vector v_out(vect.size());
    for (unsigned int i = 0; i < v2.vect.size(); ++i) {
        v_out.vect[i] = vect[i] + v2.vect[i];
    }
    return v_out;
}

Vector Vector::operator- (const Vector& v2) const {
    if (v2.vect.size() != vect.size()) {
        cout << "ERROR -: vectors of different dimensions \n";
        return *this;
    }
    Vector v_out(vect.size());
    for (unsigned int i = 0; i < v2.vect.size(); ++i) {
        v_out.vect[i] = vect[i] - v2.vect[i];
    }
    return v_out;
}

void Vector::operator+= (const Vector& v2) {
    if (v2.vect.size() != vect.size()) {
        cout << "ERROR +=: vectors of different dimensions \n";
    }
    else {
        for (unsigned int i = 0; i < vect.size(); ++i) {
            vect[i] += v2.vect[i];
        }
    }
}

void Vector::operator-= (const Vector& v2) {
    if (v2.vect.size() != vect.size()) {
        cout << "ERROR +=: vectors of different dimensions \n";
    }
    else {
        for (unsigned int i = 0; i < vect.size(); ++i) {
            vect[i] -= v2.vect[i];
        }
    }
}

// template<typename T>
// Vector Vector::operator* (const T a) const {
//     Vector v_out(vect.size());
//     for (unsigned int i = 0; i < vect.size(); ++i) {
//         v_out.vect[i] = vect[i] * a;
//     }
//     return v_out;
// }

Vector Vector::operator* (const double a) const {
    Vector v_out(vect.size());
    for (unsigned int i = 0; i < vect.size(); ++i) {
        v_out.vect[i] = vect[i] * a;
    }
    return v_out;
}

void Vector::operator*= (const double a) {
    for (unsigned int i = 0; i < vect.size(); ++i) {
        vect[i] *= a;
    }
}

void Vector::resize(unsigned int n) {
    vect.resize(n);
}

// slice from vector
Vector Vector::slice(unsigned int i0, unsigned int i1) const {
    if (i1 < i0){
        std::cout << "Warning. i1 must be >= i0. indexes swapped. \n";
        std::swap(i1, i0);
    }
    else if (i0 > vect.size()) {
        std::cout << "Warning. i0 must be <= vector size. Taked v.s. \n";
        i0 = vect.size();
    }
    
    if (i1 > vect.size()){
        std::cout << "Warning. i1 must be <= vector size. Taked v.s. \n";
        i1 = vect.size();
    }

    Vector out_vector(i1 - i0);
    for (unsigned int i = i0; i < i1; ++i) {
        out_vector.vect[i - i0] = vect[i];
    }

    return out_vector;
}

Vector Vector::slice(unsigned int i) {return slice(0, i);};

// приклеить справа
void Vector::glue_v(const Vector &v2) {
    unsigned int old_size = vect.size();
    vect.resize(old_size + v2.vect.size());

    for (unsigned int i = old_size; i > vect.size(); ++i) {
        vect[i] = v2.vect[i];
    }
}

// template<typename T>
// Vector operator* (T a, const Vector& v) { 
//     Vector v_out(v.getSize());
//         for (unsigned int i = 0; i < v.getSize(); ++i) {
//             v_out.setValue(i, v.getValue(i) * a);
//         }
//         return v_out;
// }

Vector operator* (double a, const Vector& v) { 
    Vector v_out(v.getSize());
        for (unsigned int i = 0; i < v.getSize(); ++i) {
            v_out.setValue(i, v.getValue(i) * a);
        }
        return v_out;
}

std::ostream& operator<<(std::ostream& os, const Vector &v) {
    os << "Vector with size " << v.vect.size() << ": ( ";
    for (auto elem: v.vect) {
        os << elem << ' ';
    }
    os << ") \n";
    return os;
};

std::istream& operator>>(std::istream &is, Vector &v) {
    for (unsigned int i = 0; i < v.vect.size(); ++i) {
        is >> v.vect[i];
    }
    return is;
};

