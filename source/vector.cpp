#include <iostream>
#include <algorithm>
#include "../headers/vector.h"


// init vector
void init_vector(Vector* vect, unsigned int n, double comps[]) {
	(*vect).n = n;
	for (unsigned int i = 0; i < n; i++){
		(*vect).comps[i] = comps[i];
	}
}


void print_v(Vector vect) {
	std::cout << "Vector with size " << vect.n << ": ( ";
	for (unsigned int i = 0; i < vect.n; i++){
		std::cout << vect.comps[i] << ' ';
	}
	std::cout << ") \n";
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
		std::cout << "Math error (+). Different size of vectors. Summary may be wrong. \n";
	}
	Vector vect_new;
	vect_new.n = std::min(vect1.n, vect2.n);
	for (unsigned int i = 0; i < vect_new.n; i++){
		vect_new.comps[i] = vect1.comps[i] + vect2.comps[i];
	}
	return vect_new;
}


// (x, y, z) + (dx, dy, dz) = (x + dx, y + dy, z + dz)
void plus_eq(Vector* vect, Vector d_vect) {
	if (d_vect.n != (*vect).n){
		std::cout << "Math error (+=). Different size of vectors. Summary may be wrong. \n";
	}
	for (unsigned int i = 0; i < (*vect).n; i++){
		(*vect).comps[i] += d_vect.comps[i];
	}
}


// vector slice fron i0 to i1
Vector cut_v(Vector vect, int i0, int i1) {
	if (i1 < i0){
		std::cout << "Warning. i1 must be >= i0. indexes swapped. \n";
		std::swap(i1, i0);
	}
	if (i0 < 0) {
		std::cout << "Warning. i0 must be > 0. Taked 0. \n";
		i0 = 0;
	}
	else if ((unsigned int) i0 > vect.n) {
		std::cout << "Warning. i0 must be <= vector size. Taked v.s. \n";
		i0 = (int) vect.n;
	}
	
	if ((unsigned int) i1 > vect.n){
		std::cout << "Warning. i1 must be <= vector size. Taked v.s. \n";
		i1 = (int) vect.n;
	}
	else if (i1 < 0){
		std::cout << "Warning. i1 must be > 0. Taked 0. \n";
		i1 = 0;
	}

	Vector new_vect;
	new_vect.n = (unsigned int) (i1 - i0);

	for (unsigned int i = (unsigned int) i0; i < (unsigned int) i1; i++){
		new_vect.comps[i - (unsigned int) i0] = vect.comps[i];
	}
	
	return new_vect;
}


// vect1 = (x1, y1, z1), vect2 = (x1, y2, z2) -> vect(x1, y1. z1, x2, y2, z2)
Vector glue_v(Vector vect1, Vector vect2) {
	if (vect1.n + vect2.n > 6){
		std::cout << "Vector math error, vect1.n + vect2.n must be <= 6. Returned vect1. \n";
		return vect1;
	
	}
	Vector new_vect;
	new_vect.n = vect1.n + vect2.n;

	for (unsigned int i = 0; i < vect1.n; i++){
		new_vect.comps[i] = vect1.comps[i];
	}
	for (unsigned int i = 0; i < vect2.n; i++){
		new_vect.comps[i + vect1.n] = vect2.comps[i];
	}

	return new_vect;
}
