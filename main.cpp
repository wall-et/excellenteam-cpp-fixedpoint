#include <iostream>

#include "FixedPoint.h"

//void test_price_ctor_1() {
//    FixedPoint<2, int> p(8);
//    std::cout << "test constructor 1 ok" << std::endl;
//}
//
//
//void test_add_operator() {
//    FixedPoint<4, long> p(8, 68);
//    FixedPoint<4, long> p2(2, 11);
//    if (p + p2 == FixedPoint<4, long>(10, 79))
//        std::cout << "test operator + ok " << std::endl;
//
//}
//
//
//void test_mul_operator() {
//
//    FixedPoint<4, long> p(1, 5555);
//    FixedPoint<4, long> p2(3, 0);
//    std::cout << "test " << p * p2 << std::endl;
//    if (p * p2 == FixedPoint<4, long>(4, 6665))
//        std::cout << "test operator * ok " << p * p2 << std::endl;
//
//}
//
//
//void test_minus_operator() {
//
//    FixedPoint<2, int> p2(8, 0);
//    if (-p2 == FixedPoint<2, int>(-8))
//        std::cout << "test operator -- ok " << std::endl;
//
//}
//
//void mul_as_price() {
//
//    FixedPoint<4, long> p(3);
//    FixedPoint<4, long> r(1, 5555);
//    r *= p;
//
//    if (r == 4.6665)
//        cout << "Mul is OK " << endl;
//}

void test_pricepoint_char_numerical_limit() {

    FixedPoint<1, unsigned char> p(25, 5);
    if (numeric_limits<FixedPoint<1, unsigned char> >::max() == p) {
        std::cout << numeric_limits<FixedPoint<1, char> >::min() << std::endl;
        std::cout << "char_numerical_limit TEST passed" << std::endl;
    }
}


int main() {
//    FixedPoint<2>::T var;
//    test_add_operator();
//    test_mul_operator();
//    test_minus_operator();
    test_pricepoint_char_numerical_limit();
//    std::cout<<"numeric max "<<numeric::max();
    return 0;
}