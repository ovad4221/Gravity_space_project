#include <iostream>
#include <fstream>
#include <algorithm>
#include "../headers/rc_memory.h"

using std::cout;

int main() {
    Vector a, b;
    double t = 0;
    double arr1[] = {0, 0, 0, 20, 100, 0};
    double arr2[] = {0, 0, 0, 10, 60, 0};
    init_vector(&a, 6, arr1);
    init_vector(&b, 6, arr2);

    Spacecraft spc1, spc2;
    init_spc(&spc1, a, 10);
    init_spc(&spc2, b, 20);

    print_spc(spc1);
    print_spc(spc2);

    std::ofstream f("rc.csv", std::ios::out); 
    f << "t,x1,y1,z1,vx1,vy1,vz1,x2,y2,z2,vx2,vy2,vz2,\n";

    double dt = 2;
    while (t < 30) {  
        runge_cutta(&spc1, t, dt, &force_test);
        runge_cutta(&spc2, t, dt, &force_test);
        t += dt;
        f << t << ',';
        for (double ci: spc1.y.comps) {
            f << ci << ',';
        }
        for (double ci: spc2.y.comps) {
            f << ci << ',';
        }
        f << '\n';
    }

    return 0;
}
 