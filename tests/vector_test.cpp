#include <iostream>
#include <algorithm>
#include "../headers/vector.h"

using std::cout;

int main() {
    Vector a, b;

    double arr1[] = {1, 2, 3, 4, 5, 6};
    double arr2[] = {1, 1, 1, 1, 1, 1};
    init_vector(&a, 6, arr1);
    init_vector(&b, 6, arr2);
    print_v(a);
    print_v(b);

    cout << "Sum of vectors: \n";
    Vector c = sum_v(a, b);
    print_v(c);

    cout << "Mult of vector: \n";
    print_v(mult_v(a, 4));

    cout << "Pl_eq of vector: \n";
    plus_eq(&c, b);
    print_v(c);

    cout << "Cut of vector: \n";
    print_v(cut_v(a, 3, 6));
    print_v(cut_v(a, 6, 3));
    print_v(cut_v(a, 0, 3));
    print_v(cut_v(a, 0, 6));
    print_v(cut_v(a, -33, 9));
    print_v(cut_v(a, -33, -32));
    print_v(cut_v(a, 33, 99));
    print_v(cut_v(a, 2, -4));
    print_v(cut_v(a, -2, 4));
    print_v(cut_v(a, 2, 4));
    
    cout << "glue_v \n";
    // 4 5 6 1 2 3
    print_v(cut_v(a, 3, 6));
    print_v(cut_v(a, 0, 3));
    print_v(glue_v(cut_v(a, 3, 6), cut_v(a, 0, 3)));
    // 3 5
    print_v(glue_v(cut_v(a, 2, 3), cut_v(a, 4, 5)));
    // 1 1 1 1 5 6
    print_v(glue_v(cut_v(b, 0, 4), cut_v(a, 4, 6)));
    print_v(glue_v(a, b));

    return 0;
}
 