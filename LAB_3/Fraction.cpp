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
