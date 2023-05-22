#include <iostream>
#include <algorithm>
#include <vector>
#include "../headers_oop/rk.h"

using std::vector;


// func f of task of Koshi
Vector f_func(Spacecraft& spc, vector<Spacecraft>& all_obj, double t, Vector (*force)(Spacecraft &spc, vector<Spacecraft>& all_obj)) {
	// glue of speed vector and acceleration vector
	Vector vect_va = spc.get_y().slice(3, 6);
	vect_va.glue_v((*force)(spc, all_obj) * static_cast<double>(1 / spc.get_m()));
	return vect_va;
}


// change spc.y to new spc.y + dy
Vector runge_cutta(Spacecraft& spc, vector<Spacecraft>& all_obj, double t, double dt, Vector (*force)(Spacecraft &spc, vector<Spacecraft>& all_obj)) {
	// k1 = f(y, t)
	Vector k1 = f_func(spc, all_obj, t, force);
	// k2 = f(y + 0.5 * dt * k1, t + 0.5 * dt)
	Spacecraft skh = spc + k1 * (0.5 * dt);
	Vector k2 = f_func(skh, all_obj, t + 0.5 * dt, force);
	// k3 = f(y + 0.5 * dt * k2, t + 0.5 * dt)
	skh = spc + k2 * (0.5 * dt);
	Vector k3 = f_func(skh, all_obj, t + 0.5 * dt, force);
	// k4 = f(y + dt * k3, t1 + dt)
	skh = spc + k3 * dt;
	Vector k4 = f_func(skh, all_obj, t + dt, force);

	// y_new = y + (dt / 6) * (k1 + 2 * k2 + 2 * k3 + k4)
	// i prefer to return delta y
	return (k1 + k2 * 2 + k3 * 2 + k4) * (dt / 6);
}

