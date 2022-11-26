#include <iostream>
#include <algorithm>
#include "../headers/spc.h"


Vector force(Spacecraft *spc, double t) {
	// 3-vector
	double arr[] = {0, 10 * (*spc).m, 0};

	Vector gg;
	init_vector(&gg, 3, arr);

	return gg;
}


// func f of task of Koshi
Vector f_func(Spacecraft* spc, double t) {
	// glue of speed vector and acceleration vector
	return glue_v(cut_v((*spc).y, 3, 6), mult_v(force(spc, t), (double) 1 / (*spc).m));
}


// change spc.y to new spc.y + dy
void runge_cutta(Spacecraft* spc, double t, double dt){
	// k1 = f(y, t)
	Vector k1 = f_func(spc, t);
	// k2 = f(y + 0.5 * dt * k1, t + 0.5 * dt)
	Vector k2 = f_func(&sum_vs(spc, mult_v(k1, 0.5 * dt)), t + 0.5 * dt);
	// k3 = f(y + 0.5 * dt * k2, t + 0.5 * dt)
	Vector k3 = f_func(&sum_vs(spc, mult_v(k2, 0.5 * dt)), t + 0.5 * dt);
	// k4 = f(y + dt * k3, t1 + dt)
	Vector k4 = f_func(&sum_vs(spc, mult_v(k3, dt)), t + dt);

	// y_new = y + (dt / 6) * (k1 + 2 * k2 + 2 * k3 + k4)
	plus_eq(&((*spc).y), mult_v(sum_v(sum_v(k1, mult_v(k2, 2)), sum_v(mult_v(k3, 2), k4)), (dt / 6)));
}

