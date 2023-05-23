#include "../headers_oop/rk.h"
#include "../headers_oop/forces.h"

int main() {
    Vector y1({0, 0, 2, 1, 0, 0});
    Vector y2({5, 5, 2, 0, 1, 0});

    vector<Spacecraft> all_obj;
    Spacecraft spc1(y1, 1, "Object1");
    Spacecraft spc2(y2, 1, "Obkect2");
    all_obj.push_back(spc1);
    all_obj.push_back(spc2);

    std::cout << all_obj[1];

    return 0;
}
