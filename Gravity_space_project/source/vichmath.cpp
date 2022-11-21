#include <iostream>
#include <algorithm>
#include "..\headers\vector.h"


struct spacecraft {
	// m in kg
	double m;
	// 6n-vector <y> = (x, y, z, vx, vy, vz )
	Vector y;
};

// init spc
void init_spc(spacecraft* spc, Vector* y0, double m) {
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
Vector f_func(Vector y, double t) {
	// glue of speed vector and force vector
	return glue_v(cut_v(y, 3, 6), force(t));
}


Vector runge_cutta(Vector y, double t, double dt){
	
	Vector k1 = f_func(y, t);
	Vector k2 = f_func(sum_v(y, mult_v(k1, 0.5 * dt)), t + 0.5 * dt);
	Vector k3 = f_func(sum_v(y, mult_v(k2, 0.5 * dt)), t + 0.5 * dt);
	Vector k4 = f_func(sum_v(y, mult_v(k3, dt)), t + dt);
	
	return sum_v(y, mult_v(sum_v(sum_v(k1, mult_v(k2, 2)), sum_v(mult_v(k3, 2), k4)), (dt / 6)));
}

