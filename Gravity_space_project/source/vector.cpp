#include <iostream>
#include <algorithm>
#include "..\headers\vector.h"


// init vector
void init_vect(Vector* vect, int n, double* comps) {
	(*vect).n = n;
	for (unsigned int i = 0; i < n; i++){
		(*vect).comps[i] = comps[i];
	}
}


// vector * double
Vector mult_v(Vector vect, double a) {
    Vector vect_new;
	vect_new.n = vect.n;

	for (unsigned int i = 0; i < vect.n; i++){
		vect_new.comps[i] = vect.comps[i] * a;
	}

    return vect_new;
}


// (x1, y1, z1) + (x2, y2, z2) = (x1 + x2, y1 + y2, z1 + z2)
Vector sum_v(Vector vect1, Vector vect2) {
	if (vect1.n != vect2.n){
		std::cout << "Math error. Different size of vectors. Summary may be wrong.";
	}
	Vector vect_new;
	vect_new.n = std::min(vect1.n, vect2.n);
	for (unsigned int i = 0; i < vect_new.n; i++){
		vect_new.comps[i] = vect1.comps[i] + vect2.comps[i];
	}
	return vect_new;
}


// vector slice
Vector cut_v(Vector vect, int i0, int i1) {
	if (i0 < 0) {
		std::cout << "Warning. i0 must be > 0. Taked 0.";
		i0 = 0;
	}
	if (i1 > vect.n){
		std::cout << "Warning. i1 must be <= vector size. Taked v.s.";
		i0 = vect.n;
	}
	if (i1 < i0){
		std::cout << "Warning. i1 must be >= i0. indexes swapped.";
		std::swap(i1, i0);
	}

	Vector new_vect;
	new_vect.n = i1 - i0;

	for (unsigned int i = i0; i < i1; i++){
		new_vect.comps[i - i0] = vect.comps[i];
	}
	
	return new_vect;
}


// vect1 = (x1, y1, z1), vect2 = (x1, y2, z2) -> vect(x1, y1. z1, x2, y2, z2)
Vector glue_v(Vector vect1, Vector vect2) {
	if (vect1.n + vect2.n > 6){
		return;
	}
	Vector new_vect;
	new_vect.n = vect1.n + vect2.n;

	for (unsigned int i = 0; i < vect1.n; i++){
		new_vect.comps[i] = vect1.comps[i];
	}
	for (unsigned int i = 0; i < vect2.n; i++){
		new_vect.comps[i + vect1.n - 1] = vect2.comps[i];
	}

	return new_vect;
}
