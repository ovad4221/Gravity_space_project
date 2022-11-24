#ifndef MY_HEADER_FILE_H
#define MY_HEADER_FILE_H

#define DEBUG

struct Vector {
	// размерность вектора
	unsigned int n;
    // список компонент вектора(мне будут нужны 6-векторы)
	double comps[6];
};


void init_vector(Vector* vect, unsigned int n, double comps[]);

void print_v(Vector vect);

Vector mult_v(Vector vect, double a);

Vector sum_v(Vector vect1, Vector vect2);

void plus_eq(Vector* vect, Vector d_vect);

Vector cut_v(Vector vect, int i0, int i1);

Vector glue_v(Vector vect1, Vector vect2);


struct Spacecraft {
	// m in kg
	double m;
	// 6n-vector <y> = (x, y, z, vx, vy, vz )
	Vector y;
};


void init_spc(Spacecraft* spc, Vector* y0, double m);

Vector f_func(Vector y, double t, double m);

Vector runge_cutta(Spacecraft* spc, double m, double t, double dt);

#endif
