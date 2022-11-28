#ifndef RC_H
#define RC_H
#include "../headers/spc.h"

#define DEBUG

Vector force_test(Spacecraft *spc, double t);

Vector f_func(Spacecraft* spc, double t, Vector (*force)(Spacecraft *spc, double t));

void runge_cutta(Spacecraft* spc, double t, double dt, Vector (*force)(Spacecraft *spc, double t));

#endif
