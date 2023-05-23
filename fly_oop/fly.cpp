#include "../headers_oop/rk.h"
#include "../headers_oop/forces.h"
#include <fstream>

// std::ofstream myfile;
// myfile.open ("example.csv");
// myfile << "This is the first cell in the first column.\n";
// myfile << "a,b,c,\n";
// myfile << "c,s,v,\n";
// myfile << "1,2,3.456\n";
// myfile << "semi;colon";
// myfile.close();
// return 0;

int main() {
    Vector y1({0, 0, 2, 1, 0.5, 0});
    Vector y2({5, 5, 2, 0.5, 1, 0});

    vector<Spacecraft> all_obj;
    Spacecraft spc1(y1, 1, "Object1");
    Spacecraft spc2(y2, 1, "Obkect2");
    all_obj.push_back(spc1);
    all_obj.push_back(spc2);

    vector<Vector> delta_arr(all_obj.size());
    double delta_t = 1;

    // work with file
    std::ofstream f;
    f.open ("result.csv");
    f << "t,x1,y1,z1.x2,y2,z2,dt\n";
    // string writing
    f << "0,";
    for (unsigned int i = 0; i < all_obj.size(); ++i) {
        for (unsigned int j = 0; j < 3; ++j) {
            f << all_obj[i].get_y()[j] << ',';
        }
    }
    f << delta_t << '\n';


    for (double t = 0; t <= 60; t += delta_t) {
        
        for (unsigned int j = 0; j < all_obj.size(); j++) {
            delta_arr[j] = runge_cutta(all_obj[j], all_obj, t, delta_t, &gravity_force);
        }
        for (unsigned int j = 0; j < all_obj.size(); j++) {
            all_obj[j] += delta_arr[j];
        }

        // string writing
        f << t << ',';
        for (unsigned int i = 0; i < all_obj.size(); ++i) {
            for (unsigned int j = 0; j < 3; ++j) {
                f << all_obj[i].get_y()[j] << ',';
            }
        }
        f << delta_t << '\n';

    }

    f.close();
    return 0;
}
