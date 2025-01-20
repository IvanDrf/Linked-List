#include "Vector.hpp"

int main(int, char**) {
    Vector v1 = {1, 2, 3};
    v1.Insert(0, 7);

    std::cout << 1 << '\n';
    std::cout << v1 << '\n';
}
