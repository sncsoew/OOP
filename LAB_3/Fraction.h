#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <string>

class Fraction {
private:
    long long numerator;
    long long denominator;
    mutable int accessCount = 0;
    static int objectCount;
    void normalize();

public:
    Fraction();
    explicit Fraction(long long wholeNumber);
    Fraction(long long num, long long den);
    Fraction(const Fraction& other);
    ~Fraction();

    long long getNumerator() const;
    long long getDenominator() const;
    int getAccessCount() const;
    static int getObjectCount();
    std::string toString() const;

    Fraction& operator++();
    Fraction operator++(int);
    Fraction& operator--();
    Fraction operator--(int);

    Fraction& operator+=(const Fraction& other);
    Fraction& operator-=(const Fraction& other);
    Fraction& operator*=(const Fraction& other);
    Fraction& operator/=(const Fraction& other);

    friend Fraction operator+(Fraction lhs, const Fraction& rhs);
    friend Fraction operator-(Fraction lhs, const Fraction& rhs);
    friend Fraction operator*(Fraction lhs, const Fraction& rhs);
    friend Fraction operator/(Fraction lhs, const Fraction& rhs);

    friend bool operator==(const Fraction& lhs, const Fraction& rhs);
    friend bool operator!=(const Fraction& lhs, const Fraction& rhs);
    friend bool operator<(const Fraction& lhs, const Fraction& rhs);
    friend bool operator>(const Fraction& lhs, const Fraction& rhs);
    friend bool operator<=(const Fraction& lhs, const Fraction& rhs);
    friend bool operator>=(const Fraction& lhs, const Fraction& rhs);

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
};

#endif
