#include <iostream>


int main() {
    double k = 234.4297865;
    std::cout << (double) (int) k << ' ' << (double) ((long int) (k * 10000000000) % 10000000000) / 10000000000;

    return 0;
}
