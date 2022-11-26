#include <iostream>
#include <algorithm>
#include "../headers/spc.h"


// init spc
void init_spc(Spacecraft* spc, Vector y0, double m) {
	(*spc).m = m;
	(*spc).y = y0;
    // initialization of someone else params 
    // is more lickly to do whis kwargs
}


void print_spc(Spacecraft spc) {
    std::cout << "Spacecraft: \"";
    for (char ch: spc.name) {
        std::cout << ch;
    }
    std::cout << "\" with weight: " << spc.m << " and 6-vect: ";
    print_v(spc.y);
    // for all kwargs
}


Spacecraft sum_vs(Spacecraft* spc, Vector vect) {
    Spacecraft spc_new; 
    Vector new_y = sum_v((*spc).y, vect);
    init_spc(&spc_new, new_y, (*spc).m);
    return spc_new;
}
