
#include "Price.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Price p1(2, 50);
    Price p2(1, 50);
    std::cout << "2.50 - 1.50 = " << p1 - p2 << std::endl;
    std::cout << "1.50 - 2.50 = " << p2 - p1 << std::endl;
    std::cout << "2.50 + 1.50 = " << p1 + p2 << std::endl;

    std::cout << "2.50 * 1.50 = " << p1 * p2 << std::endl;

    std::cout << "1.50 / 2.50  = " << p2 / p1 << std::endl;

    std::cout << "2.50 / 1.50 = " << p1 / p2 << std::endl;
    return 0;
}