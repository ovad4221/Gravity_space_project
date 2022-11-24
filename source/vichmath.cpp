#include <iostream>
#include <algorithm>
#include "../headers/vector.h"


// init spc
void init_spc(Spacecraft* spc, Vector* y0, double m) {
	(*spc).m = m;
	(*spc).y = *y0;
}


// gravity force in any moment of time
Vector force(double t){
	// pass
	// 3-vector
	return Vector();
}


// func f of task of Koshi
Vector f_func(Vector y, double t, double m) {
	// glue of speed vector and acceleration vector
	return glue_v(cut_v(y, 3, 6), mult_v(force(t), (double) 1 / m));
}

// change spc.y to new spc.y + dy
void runge_cutta(Spacecraft* spc, double t, double dt){

	Vector k1 = f_func((*spc).y, t, (*spc).m);
	Vector k2 = f_func(sum_v((*spc).y, mult_v(k1, 0.5 * dt)), t + 0.5 * dt, (*spc).m);
	Vector k3 = f_func(sum_v((*spc).y, mult_v(k2, 0.5 * dt)), t + 0.5 * dt, (*spc).m);
	Vector k4 = f_func(sum_v((*spc).y, mult_v(k3, dt)), t + dt, (*spc).m);

	plus_eq(&((*spc).y), mult_v(sum_v(sum_v(k1, mult_v(k2, 2)), sum_v(mult_v(k3, 2), k4)), (dt / 6)));
}

