#ifndef SPC_H
#define SPC_H
#include "../headers_oop/vector.h"

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
    Spacecraft(Vector &y0, double m=1, string name="with no name");
    Spacecraft(double m=1, string name="with no name"); 
    ~Spacecraft();

    double get_m() const {
        return m;
    }

    Vector get_y() const {
        return y;
    }

    string get_name() const {
        return name;
    }
};

std::ostream& operator<<(std::ostream& os, const Spacecraft &spc);

#endif
