#include "Fraction.h"
#include <iostream> 
#include <string>

int main() {
    setlocale(LC_ALL, ".UTF-8");

    Fraction zero;
    Fraction half(1, 2);
    Fraction three(3);

    Fraction explicitValue = Fraction(5);
    
    Fraction a(1, 2);
    Fraction b(1, 3);
    
    Fraction sum = a + b;
    Fraction difference = a - b;
    Fraction product = a * b;
    Fraction quotient = a / b;


    Fraction c(1, 2);
    c += b;
    
    c = Fraction(1, 2);
    c -= b;


    c = Fraction(1, 2);
    c *= b;


    c = Fraction(1, 2);
    c /= b;


    Fraction d(2, 5);
    
    std::cout << "Исходная d = " << d << '\n';
    std::cout << "++d = " << ++d << '\n';
    std::cout << "d++ вернул " << d++ << '\n';
    std::cout << "После d++: " << d << '\n';
    std::cout << "--d = " << --d << '\n';
    std::cout << "d-- вернул " << d-- << '\n';
    std::cout << "После d--: " << d << '\n';

    std::cout << "a < b: " << (a < b) << '\n';
    std::cout << "a > b: " << (a > b) << '\n';
    std::cout << "a <= b: " << (a <= b) << '\n';
    std::cout << "a >= b: " << (a >= b) << '\n';
    std::cout << "a == b: " << (a == b) << '\n';
    std::cout << "a != b: " << (a != b) << '\n';

    const Fraction constFraction(7, 9);
    std::cout << "constFraction = " << constFraction << '\n';
    std::cout << "Числитель: " << constFraction.getNumerator() << '\n';
    std::cout << "Знаменатель: " << constFraction.getDenominator() << '\n';
    std::cout << "Счётчик обращений: " << constFraction.getAccessCount() << '\n';

    std::cout << "\nКоличество созданных объектов Fraction: "<< Fraction::getObjectCount() << '\n';
    Fraction::showHistory();
}