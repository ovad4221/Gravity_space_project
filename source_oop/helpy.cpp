#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>

using std::vector;
using std::list;

int main() {
    vector<int> v(15, 1);
    v.resize(5);
    for (auto i: v) {
        std::cout << i << ' ';
    }
}
