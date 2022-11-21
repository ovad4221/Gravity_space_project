#ifndef MY_HEADER_FILE_H
#define MY_HEADER_FILE_H

#define DEBUG

struct Vector {
	// размерность вектора
	int n;
    // список компонент вектора(мне будут нужны 6-векторы)
	double comps[6];
};

void init_vect(Vector* vect, int n, double* comps);

Vector mult_v(Vector vect, double a);

Vector sum_v(Vector vect1, Vector vect2);

Vector cut_v(Vector vect, int i0, int i1);

Vector glue_v(Vector vect1, Vector vect2);

#endif
