#ifndef VECTOR_H
#define VECTOR_H

#define DEBUG
#include <vector>

using std::vector;

class Vector {
    friend std::ostream& operator<<(std::ostream& os, const Vector &v);
    friend std::istream& operator>>(std::istream &is, Vector &v);
private:
    vector<double> vect;
public:
    Vector(vector<double> &vect);
    Vector(unsigned int n);
    Vector(std::initializer_list<double> l);
    
    ~Vector();

    double module_v() const;

    // Получение размерности вектора
    unsigned int getSize() const;

    // Получение значения i-ой координаты вектора
    int getValue(unsigned int i) const;

    // Задание значения i-ой координаты вектора равным value
    void setValue(unsigned int i, int value);

    bool operator== (const Vector& v2) const;

    bool operator!= (const Vector& v2) const;

    Vector operator+ (const Vector& v2) const;

    Vector operator- (const Vector& v2) const;

    void operator+= (const Vector& v2);

    void operator-= (const Vector& v2);

    Vector operator* (const int a) const;

    void operator*= (const int a);

    void resize(unsigned int n);

    // slice from vector
    Vector slice(unsigned int i0, unsigned int i1) const;

    Vector slice(unsigned int i);

    // приклеить справа
    void glue_v(const Vector &v2);
};

Vector operator* (int a, const Vector& v);

std::ostream& operator<<(std::ostream& os, const Vector &v);

std::istream& operator>>(std::istream &is, Vector &v);

#endif
