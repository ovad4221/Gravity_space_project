#include <ostream>
#include <algorithm>
#include <string>
#include "../headers_oop/spc.h"

using std::string;


Spacecraft::Spacecraft(const Vector &y0, double m, string name): m(m), y(y0), name(name) {};
Spacecraft::Spacecraft(const Vector &y0, double m): Spacecraft(y0, m, "with no name") {};
Spacecraft::Spacecraft(const Vector &y0, string name): Spacecraft(y0, 1, name) {};
Spacecraft::Spacecraft(const Vector &y0): Spacecraft(y0, 1, "with no name") {};

Spacecraft::Spacecraft(double m, string name): m(m), y(6), name(name) {}; 
Spacecraft::Spacecraft(double m): Spacecraft(m, "with no name") {};
Spacecraft::Spacecraft(string name): Spacecraft(1, name) {};
Spacecraft::Spacecraft(): Spacecraft(1, "with no name") {};

Spacecraft::~Spacecraft() = default;

double Spacecraft::get_m() const {
    return m;
}

Vector Spacecraft::get_y() const {
    return y;
}

string Spacecraft::get_name() const {
    return name;
}

void Spacecraft::set_y(const Vector &vect) {
    y = vect;
}

Spacecraft Spacecraft::operator+(const Vector& vect) {
    Spacecraft new_spc(y + vect, m, name);
    return new_spc;
}

void Spacecraft::operator+=(const Vector& vect) {
    y += vect;
}


std::ostream& operator<<(std::ostream& os, const Spacecraft &spc) {
    os << "Spacecraft: " << spc.name << " with weight: " << spc.m << " and 6-vect: " << spc.y;
    return os;
}

// std::istream& operator>>(std::istream &is, Spacecraft &spc) {

// }

// int main() {
//     Vector y0(6);
//     Spacecraft spc(y0, 16.3);

//     std::cout << spc;

//     return 0;
// }
