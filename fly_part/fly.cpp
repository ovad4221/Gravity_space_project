#include <iostream>
#include "../calceph/include/calceph.h"
#include "../headers/time_jd.h"
#include "../headers/planets.h"
#include "../headers/runge_cutta.h"
#include <fstream>


int main() {
    int ymd[3] = {2023, 8, 21};
    int hms[3] = {22, 22, 22};
    double jnd = (double) to_jd0(ymd[0], ymd[1], ymd[2]) + to_dt(hms[0], hms[1], hms[2]);

    space_object grav_o[n_obj];
    
    t_calcephbin *peph;
    peph = calceph_open("../ephem/de405.bin");

    init_planets(grav_o);
    for (unsigned int i=0; i < n_obj; i++) {
        calc_vect(&grav_o[i], jnd, peph);
    }
    
    // in s
    const double dt = 1;

    // for (space_object spo: grav_o) {
    //     print_pl(&spo);
    // }
    
    Vector v;
    double y_0[] = {0, 0, 0, 0, 0, 0};
    init_vector(&v, 6, y_0);

    Spacecraft spc;
    init_spc(&spc, v, 721.9);

    std::ofstream f("fly.csv", std::ios::out); 
    f << "t,x1,y1,z1,vx1,vy1,vz1,\n";

    while (true) {  
        update_pl(grav_o, jnd, peph);
        runge_cutta(&spc, 0, dt, &grav_force);
        jnd = time_stap(jnd, dt);

        f << jnd << ',';
        for (double ci: spc.y.comps) {
            f << ci << ',';
        }
        f << '\n';
    }

    return 0;
}
