#include <iostream>
#include <algorithm>
#include "../headers/spc.h"
#include "../headers/planets.h"
#include "../headers/time_jd.h"


// func f of task of Koshi
Vector f_func(Spacecraft* spc, space_object *grav_o, double t, Vector (*force)(Spacecraft *spc, space_object *grav_o)) {
	// glue of speed vector and acceleration vector
	return glue_v(cut_v((*spc).y, 3, 6), mult_v((*force)(spc, grav_o), (double) 1 / (*spc).m));
}


// change spc.y to new spc.y + dy
void runge_cutta(Spacecraft* spc, space_object *grav_o, double jnd, double dt, Vector (*force)(Spacecraft *spc, space_object *grav_o)) {
	// k1 = f(y, t)
	Vector k1 = f_func(spc, grav_o, jnd, force);
	// k2 = f(y + 0.5 * dt * k1, t + 0.5 * dt)
	Spacecraft skh = sum_vs(spc, mult_v(k1, 0.5 * dt));
	Vector k2 = f_func(&skh, grav_o, time_stap(jnd, 0.5 * dt), force);
	// k3 = f(y + 0.5 * dt * k2, t + 0.5 * dt)
	skh = sum_vs(spc, mult_v(k2, 0.5 * dt));
	Vector k3 = f_func(&skh, grav_o, time_stap(jnd, 0.5 * dt), force);
	// k4 = f(y + dt * k3, t1 + dt)
	skh = sum_vs(spc, mult_v(k3, dt));
	Vector k4 = f_func(&skh, grav_o, time_stap(jnd, dt), force);

	// y_new = y + (dt / 6) * (k1 + 2 * k2 + 2 * k3 + k4)
	plus_eq(&((*spc).y), mult_v(sum_v(sum_v(k1, mult_v(k2, 2)), sum_v(mult_v(k3, 2), k4)), (dt / 6)));
}

