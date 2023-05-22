#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include "../headers_oop/forces.h"

Vector gravity_force(Spacecraft &spc, vector<Spacecraft>& all_obj) {
	Vector force(3);

	for (int i = 0; i <= all_obj.size(); i++) {
		Vector h = spc.get_y().slice(3) - all_obj[i].get_y().slice(3);
		double abs_f = G * all_obj[i].get_m() * spc.get_m() / (pow(h.module_v(), 2));

		force += abs_f / h.module_v() * h;
	}
	return force;
}
