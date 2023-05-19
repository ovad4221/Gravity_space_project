#include <iostream>
#include <algorithm>
#include <string>
#include "../headers_oop/spc.h"

using std::string;


Spacecraft::Spacecraft(Vector &y0, double m=1, string name="with no name"): m(m), y(y0), name(name) {};
Spacecraft::Spacecraft(double m=1, string name="with no name"): m(m), y(6), name(name) {}; 
Spacecraft::~Spacecraft() = default;

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
