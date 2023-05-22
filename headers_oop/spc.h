#ifndef SPC_H
#define SPC_H
#include "../headers_oop/vector.h"
#include <ostream>

#define DEBUG

using std::string;

class Spacecraft {
    friend std::ostream& operator<<(std::ostream& os, const Spacecraft &spc);
    // friend std::istream& operator>>(std::istream &is, Spc &spc);
private:
    // m in kg
	double m;
	// 6n-vector <y> = (x, y, z, vx, vy, vz) 
	Vector y;
    // side characteristics
    string name;
public:
    Spacecraft(const Vector &y0, double m, string name);
    Spacecraft(const Vector &y0, double m);
    Spacecraft(const Vector &y0, string name);
    Spacecraft(const Vector &y0);
   
    Spacecraft(double m, string name);
    Spacecraft(double m);
    Spacecraft(string name);
    Spacecraft();

    ~Spacecraft();

    double get_m() const;

    Vector get_y() const;

    string get_name() const;

    Spacecraft operator+(const Vector& vect);

    // return new spc like old just with y = (*this).y + vect
    void set_y(const Vector &vect);

    // (*this).y + vect
    void operator+=(const Vector& vect);
};

std::ostream& operator<<(std::ostream& os, const Spacecraft &spc);

#endif
