#ifndef RC_H
#define RC_H
#include "../headers/spc.h"

#define DEBUG

Vector f_func(Spacecraft* spc, space_object *grav_o, Vector (*force)(Spacecraft *spc, space_object *grav_o));

void runge_cutta(Spacecraft* spc, space_object *grav_o, double dt, Vector (*force)(Spacecraft *spc, space_object *grav_o));

#endif
