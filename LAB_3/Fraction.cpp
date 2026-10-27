#include "Fraction.h"
#include <numeric>
int Fraction::objectCount = 0;

void Fraction::normalize() {
    if (denominator == 0) {
        throw std::invalid_argument("Знаменатель не может быть равен нулю.");
    }
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    long long divisor = std::gcd(std::llabs(numerator), std::llabs(denominator));
    if (divisor != 0) {
        numerator /= divisor;
        denominator /= divisor;
    }
}

Fraction::Fraction() : numerator(0), denominator(1) {
    ++objectCount;
}

Fraction::Fraction(long long wholeNumber) : numerator(wholeNumber), denominator(1) {
    ++objectCount;
}

Fraction::Fraction(long long num, long long den) : numerator(num), denominator(den) {
    normalize();
    ++objectCount;
}

Fraction::Fraction(const Fraction& other): numerator(other.numerator), denominator(other.denominator) {
    ++objectCount;
}
