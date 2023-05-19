#include <math.h>
#include "../headers/time_jd.h"


// class Jd_time {
// private:
//     unsigned int jdn;
// public: 
//     Jd_time(int year, int month, int day) {
//         int a = floor((double) (14 - month) / 12);
//         int y = year + 4800 - a;
//         int m = month + 12 * a - 3;
//         unsigned int jdn = day + floor((double) (153 * m + 2) / 5) + 365 * y + floor((double) y / 4) - floor((double) y / 100) + floor((double) y / 400) - 32045;
//         jdn = jdn;
//     }
//     Jd_time(unsigned int jdn) {
//         jdn = jdn;
//     }
    

// }


unsigned int to_jd0(int year, int month, int day) {
    int a = floor((double) (14 - month) / 12);
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;

    unsigned int jdn = day + floor((double) (153 * m + 2) / 5) + 365 * y + floor((double) y / 4) - floor((double) y / 100) + floor((double) y / 400) - 32045;

    return jdn;
}   


double to_dt(int hours, int minutes, int seconds) {
    return (double) (hours - 12) / 24 + (double) minutes / 1440 + (double) seconds / 86400;
}


double time_stap(double jnd, int seconds) {
    return jnd + (double) seconds / 86400;
}


double zn(double jnd) {
    return (double) (int) jnd;
}

double dr(double jnd) {
    return (double) ((long int) (jnd * 10000000000) % 10000000000) / 10000000000;
}
