//
// Created by jialei on 2023/9/19.
//

#ifndef LEETCODE_FRACTION_H
#define LEETCODE_FRACTION_H

class Fraction {
public:
    Fraction(int dividend, int divisor, bool sign) : dividend_(dividend), divisor_(divisor), sign_(sign) {}
    ~Fraction() = default;
    const Fraction &operator+ (const Fraction &frac) {
        int temp_dividend = this->sign_ *
    }

private:
    int dividend_;
    int divisor_;
    int sign_;
};
#endif//LEETCODE_FRACTION_H
