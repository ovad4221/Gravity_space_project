#ifndef SPC_H
#define SPC_H
#include "../headers/vector.h"

#define DEBUG

struct Spacecraft {
	// m in kg
	double m;
	// 6n-vector <y> = (x, y, z, vx, vy, vz) 
	Vector y;
    // видимо стоит переделать реализацию остатка
    // и спросить про kwargs

    // side characteristics
    //name
    char name[20] = "Object with no name";
    // fuel
    double fuel = 0;
    // mass flow 
    double mass_flow = 0;
    // fuel flow rate
    double ff_rate = 0;
    // drag coefficient
    double drag_c = 0;
};


void init_spc(Spacecraft* spc, Vector y0, double m);

void print_spc(Spacecraft spc);

Spacecraft sum_vs(Spacecraft* spc, Vector vect);

#endif
