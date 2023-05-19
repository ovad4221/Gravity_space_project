#ifndef VECTOR_H
#define VECTOR_H

#define DEBUG

struct Vector {
	// размерность вектора
	unsigned int n;
    // список компонент вектора(мне будут нужны 6-векторы)
	double comps[6];
};


void init_vector(Vector* vect, unsigned int n, double comps[]);

Vector zeros_v(int n);

double module_v(Vector* vect);

void print_v(Vector vect);

Vector mult_v(Vector vect, double a);

Vector sum_v(Vector vect1, Vector vect2);

void plus_eq(Vector* vect, Vector d_vect);

Vector cut_v(Vector vect, int i0, int i1);

Vector glue_v(Vector vect1, Vector vect2);

#endif
