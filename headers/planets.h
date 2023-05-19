#ifndef PLANETS
#define PLANETS
#include "../headers/vector.h"

#define DEBUG

struct space_object {
    int id;
    Vector y = zeros_v(6);
    // радиус в метрах
    long int R;
    // масса относительно земли %
    double m_otn;
};

const int n_obj = 11;
const int id_c = 11;
// G and M_e / ae
const double G_a = 4.461493983;
const double M_ea = 3.992169121 * pow(10, 13);

bool init_planets(space_object *grav_o);

bool calc_vect(space_object *spo, double jnd, t_calcephbin *peph);

bool update_pl(space_object *grav_o, double jnd, t_calcephbin *peph);

Vector grav_force(Spacecraft *spc, space_object *grav_o);

void print_pl(space_object *spo);

#endif
