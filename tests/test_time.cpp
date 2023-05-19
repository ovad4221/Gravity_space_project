#include <iostream>
#include "../headers/time_jd.h"


int main() {
    int year = 2023;
    int month = 1;
    int day = 11;
    int tm[3] = { 21, 30, 30 };
    double jnd = (double) to_jd0(year, month, day) + to_dt(tm[0], tm[1], tm[2]);
    double jnd0 = jnd;
    std::cout << std::fixed << jnd << '\n' << std::endl;
    tm[2] += 1;
    std::cout << std::fixed << time_stap(jnd0, 1) << std::endl;
    jnd = (double) to_jd0(year, month, day) + to_dt(tm[0], tm[1], tm[2]);
    std::cout << std::fixed << jnd << '\n' << std::endl;

    tm[2] += 1;
    std::cout << std::fixed << time_stap(jnd0, 2) << std::endl;
    jnd = (double) to_jd0(year, month, day) + to_dt(tm[0], tm[1], tm[2]);
    std::cout << std::fixed << jnd << '\n' << std::endl;

    tm[2] += 1;
    std::cout << std::fixed << time_stap(jnd0, 3) << std::endl;
    jnd = (double) to_jd0(year, month, day) + to_dt(tm[0], tm[1], tm[2]);
    std::cout << std::fixed << jnd << std::endl;
}
