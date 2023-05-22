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

    vector<Vector> delta_arr(all_obj.size());
    double delta_t = 1;
    for (double t = 0; t <= 60; t += delta_t) {

        for (int j = 0; j < all_obj.size(); j++) {
            delta_arr[j] = runge_cutta(all_obj[j], all_obj, t, delta_t, &gravity_force);
        }
        for (int j = 0; j < all_obj.size(); j++) {
            all_obj[j] += delta_arr[j];
        }

    }


    return 0;
}