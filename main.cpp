#include <iostream>
#include "vectors.h"

//Examples of using:

void foo(const points v) {
    std::cout << v << "\n";
} 

int main() {
    const points p1 = {1, 2, 3}; //test constructor
    const points p2(2, 2, 2);

    std::cout << (p1 == p2) << " " << (p1 != p2) << "\n"; //test == and != operators

    points p = p1; //test copy constructor

    std::cout << (p == p1) << " " << (p == p2) << "\n";
    p = p2; //test operator =

    std::cout << (p == p1) << " " << (p == p2) << "\n";

    const vectors v1 = p1; // test cast from points to vectors
    const vectors v2(p2);

    std::cout << v1 + v2 << " " << v1 - v2 << " " << 2 * v1 << " " << v2 * 2 << "\n"; //test + - * operators
    std::cout << (v1 == v2) << " " << (v1 != v2) << "\n";
    std::cout << v1.length() << " " << v2.length() << " " << (v1, v2) << "\n"; //test length method and operator ,

    vectors v3 = v1 * v2; //test * operator
    std::cout << v3 << " " << v3.length() << "\n";
    std::cout << ++v3 << "\n";
    std::cout << v3++ << " " << v3 << "\n"; //test ++

    vectors v4, v5;
    std::cin >> v4 >> v5; //test >>

    foo(v2 / 2); // test / and copy constructor again

    return 0;
}