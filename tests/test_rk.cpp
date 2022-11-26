#include <iostream>
#include <fstream>
#include <chrono>
#include <algorithm>
#include "../headers/spc.h"

using std::cout;

int main() {
    Vector a, b;

    double arr1[] = {0, 0, 0, 20, 10, 0};
    double arr2[] = {0, 0, 0, 10, 10, 0};
    init_vector(&a, 6, arr1);
    init_vector(&b, 6, arr2);

    Spacecraft spc1, spc2;
    init_spc(&spc1, a, 10);
    init_spc(&spc2, b, 20);

    print_spc(spc1);
    print_spc(spc2);
    // std::ofstream myfile;   
    // myfile.open ("example.csv");



    // myfile.close();
    return 0;
}
 