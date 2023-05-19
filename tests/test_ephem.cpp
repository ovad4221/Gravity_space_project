#include <iostream>
#include "../calceph/include/calceph.h"


int main() {
    int res;
    int j;
    double jd0=2459922;
    double dt1=0.5235;
    double dt2=0.5236;
    t_calcephbin *peph;
    double PV[6];

    peph = calceph_open("../ephem/de405.bin");
    if (peph) {
        /* the heliocentric coordinates of Mars */
        calceph_compute(peph, jd0, dt1, 4, 11, PV);
        for (j=0; j<6; j++) {
            std::cout << PV[j] << " ";
        }
        std::cout << '\n';
        calceph_compute(peph, jd0, dt2, 4, 11, PV);
        for (j=0; j<6; j++) {
            std::cout << PV[j] << ' ';
        }
        std::cout << "\n";
        /* close the ephemeris file */
        calceph_close(peph);
    }
}
