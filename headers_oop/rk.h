#ifndef RK_H
#define RK_H
#include "../headers_oop/spc.h"

#define DEBUG

Vector f_func(Spacecraft& spc, vector<Spacecraft>& all_obj, double t, Vector (*force)(Spacecraft &spc, vector<Spacecraft>& all_obj));

// return delta y (6-vector)
Vector runge_cutta(Spacecraft& spc, vector<Spacecraft>& all_obj, double t, double dt, Vector (*force)(Spacecraft &spc, vector<Spacecraft>& all_obj));

#endif
