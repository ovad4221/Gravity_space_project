#include <iostream>
#include <cmath> 
#include "../calceph/include/calceph.h"
#include "../headers/planets.h"
#include "../headers/time_jd.h"
#include "../headers/spc.h"

void print_pl(space_object *spo) {
    std::cout << "Planet with id: " << spo->id << " radius: " << spo->R << " weight: " << spo->m_otn << std::endl;
    print_v(spo->y);
}

bool calc_vect(space_object *spo, double jnd, t_calcephbin *peph) {
    if (peph) {
        calceph_compute(peph, zn(jnd), dr(jnd), spo->id, id_c, (spo->y).comps);
        return true;
    }
    return false;
}

bool update_pl(space_object *grav_o, double jnd, t_calcephbin *peph) {
    for (unsigned int i=0; i < n_obj; i++) {
        calc_vect(&grav_o[i], jnd, peph);
    }
    return true;
}

Vector grav_force(Spacecraft *spc, space_object *grav_o) {
    // F = -G * M_pl * m_k / |r|^2
    // Fx^2 + Fy^2 + Fz^2 = F^2
    // Fx = -(G * M_pl * m_k / |r|^3) * x
    // in H
    Vector force = zeros_v(3);
    for (unsigned int i=0; i < n_obj; i++) {
        // object grav_o[i]
        // d_r = R - r
        Vector d_r = sum_v(cut_v((grav_o[i]).y, 0, 3), mult_v(cut_v(spc->y, 0, 3), -1));
        double co = (double) (G_a * spc->m * (grav_o[i]).m_otn * M_ea) / pow(module_v(&d_r), 3);
        force.comps[0] += co * d_r.comps[0];
        force.comps[1] += co * d_r.comps[1];
        force.comps[2] += co * d_r.comps[2];
    }
    return force;
}

bool init_planets(space_object *grav_o) {
    // Mercury 
    grav_o[0].id = 1;
    grav_o[0].R =  2439700;
    grav_o[0].m_otn = 0.055274;

    // Venus 
    grav_o[1].id = 2;
    grav_o[1].R =  6051800;
    grav_o[1].m_otn = 0.815;

    // Earth
    grav_o[2].id = 3;
    grav_o[2].R =  6371000;
    grav_o[2].m_otn = 1;

    // Mars 
    grav_o[3].id = 4;
    grav_o[3].R =  3389500;
    grav_o[3].m_otn = 0.11;

    // Jupiter 
    grav_o[4].id = 5;
    grav_o[4].R =  71492000;
    grav_o[4].m_otn = 318;

    // Saturn 
    grav_o[5].id = 6;
    grav_o[5].R =  60268000;
    grav_o[5].m_otn = 95;

    // Uranus 
    grav_o[6].id = 7;
    grav_o[6].R =  25362000;
    grav_o[6].m_otn = 14.54;

    // Neptune 
    grav_o[7].id = 8;
    grav_o[7].R =  24764000;
    grav_o[7].m_otn = 17.147;

    // Pluto 
    grav_o[8].id = 9;
    grav_o[8].R =  1187000;
    grav_o[8].m_otn = 0.002;

    // Moon
    grav_o[9].id = 10;
    grav_o[9].R =  1737100;
    grav_o[9].m_otn = 0.012;
    
    // Sun
    grav_o[10].id = 11;
    grav_o[10].R =  696000000;
    grav_o[10].m_otn = 332940;

    return true;
}
