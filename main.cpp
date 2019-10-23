
#include "Price.h"

int main() {
    try {
        std::cout << "Hello, World!" << std::endl;

        FixedPoint<2, int> p1(-2, 00);
        FixedPoint<2, int> p2(1, 50);
        FixedPoint<2, int> p4(0, -4);
//    std::cout << "2.50 - 1.50 = " << p1 - p2 << std::endl;
//    std::cout << "1.50 - 2.50 = " << p2 - p1 << std::endl;
        //std::cout << ++p1;
        p1 += p2;
        std::cout << p1 ;
        std::cout << +p1.getPrecision();
    }catch (const char* e){
        std::cout <<e<<std::endl;
    }
//
//    std::cout << "2.50 * 1.50 = " << p1 * p2 << std::endl;
//
//    std::cout << "1.50 / 2.50  = " << p2 / p1 << std::endl;
//
//    std::cout << "2.50 / 1.50 = " << p1 / p2 << std::endl;
    return 0;
}