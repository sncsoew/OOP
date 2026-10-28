#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <string>

/**
 * @class Fraction
 * @brief Класс для работы с обыкновенными дробями.
 *
 * Класс позволяет создавать дроби, выполнять арифметические операции,
 * сравнивать дроби, изменять их значение с помощью инкремента и
 * декремента, а также выводить их в поток.
 *
 * Дробь представляется числителем и знаменателем.
 * Функция normalize() используется для приведения дроби
 * к сокращённому виду и проверки корректности знаменателя.
 *
 * @warning Знаменатель дроби не должен быть равен нулю.
 */

class Fraction {
private:
    long long numerator;    ///< Числитель дроби.
    long long denominator;  ///< Знаменатель дроби.
    mutable int accessCount = 0;    ///< Количество обращений к объекту через отслеживаемые методы.
    static int objectCount; ///< Количество существующих объектов класса Fraction.
    
    /**
     * @brief Нормализует дробь.
     *
     * Приводит дробь к стандартному виду:
     * делает знаменатель положительным и сокращает дробь,
     * если это возможно.
     *
     * @exception std::invalid_argument Если знаменатель равен нулю.
     */
    void normalize();

public:

    /**
     * @brief Конструктор по умолчанию.
     *
     * Создаёт дробь со значением по умолчанию.
     */
    Fraction();

    /**
     * @brief Конструктор для создания целого числа в виде дроби.
     * @param wholeNumber Целое число, которое будет числителем дроби.
     *
     * Знаменатель создаваемой дроби равен единице.
     *
     * @note Ключевое слово explicit запрещает неявное преобразование
     * целого числа в объект Fraction.
     */
    explicit Fraction(long long wholeNumber);

    /**
     * @brief Конструктор дроби с заданными числителем и знаменателем.
     * @param num Числитель дроби.
     * @param den Знаменатель дроби.
     *
     * После создания дробь приводится к нормализованному виду.
     *
     * @exception std::invalid_argument Если знаменатель равен нулю.
     */
    Fraction(long long num, long long den);

    /**
     * @brief Конструктор копирования.
     * @param other Объект Fraction, из которого копируются данные.
     *
     * Создаёт новый объект на основе существующей дроби.
     */
    Fraction(const Fraction& other);

    /**
     * @brief Деструктор.
     *
     * Выполняет действия, необходимые при уничтожении объекта.
     */
    ~Fraction();

    /**
     * @brief Возвращает числитель дроби.
     * @return Значение числителя.
     */
    long long getNumerator() const;

    /**
     * @brief Возвращает знаменатель дроби.
     * @return Значение знаменателя.
     */
    long long getDenominator() const;
    
    /**
     * @brief Возвращает количество обращений к объекту.
     * @return Текущее значение счётчика обращений.
     */
    int getAccessCount() const;
    
    /**
     * @brief Возвращает количество существующих объектов Fraction.
     * @return Текущее значение статического счётчика объектов.
     * @note Статический метод вызывается без создания отдельного объекта.
     */
    static int getObjectCount();

    /**
     * @brief Преобразует дробь в строку.
     * @return Строка в формате "числитель/знаменатель".
     *
     * Увеличивает счётчик обращений к объекту.
     */
    std::string toString() const;

    /**
     * @brief Выполняет префиксный инкремент.
     * @return Ссылка на изменённый объект.
     *
     * Изменяет дробь согласно реализации оператора.
     */
    Fraction& operator++();

    /**
     * @brief Выполняет постфиксный инкремент.
     * @param Параметр int используется для отличия постфиксной формы от префиксной.
     * @return Копия объекта до изменения.
     */
    Fraction operator++(int);

    /**
     * @brief Выполняет префиксный декремент.
     * @return Ссылка на изменённый объект.
     */
    Fraction& operator--();
    
    /**
     * @brief Выполняет постфиксный декремент.
     * @param Параметр int используется для отличия постфиксной формы от префиксной.
     * @return Копия объекта до изменения.
     */
    Fraction operator--(int);

    /**
     * @brief Складывает текущую дробь с другой дробью.
     * @param other Дробь, которую нужно прибавить.
     * @return Ссылка на изменённый объект.
     */
    Fraction& operator+=(const Fraction& other);
   
    /**
     * @brief Вычитает другую дробь из текущей.
     * @param other Дробь, которую нужно вычесть.
     * @return Ссылка на изменённый объект.
     */
    Fraction& operator-=(const Fraction& other);
    
    /**
     * @brief Умножает текущую дробь на другую дробь.
     * @param other Дробь, на которую выполняется умножение.
     * @return Ссылка на изменённый объект.
     */
    Fraction& operator*=(const Fraction& other);
    /**
     * @brief Делит текущую дробь на другую дробь.
     * @param other Дробь, на которую выполняется деление.
     * @return Ссылка на изменённый объект.
     * @exception std::invalid_argument Если делитель равен нулю.
     */
    Fraction& operator/=(const Fraction& other);

    /**
     * @brief Складывает две дроби.
     * @param lhs Левая дробь.
     * @param rhs Правая дробь.
     * @return Результат сложения.
     */
    friend Fraction operator+(Fraction lhs, const Fraction& rhs);
    
    /**
     * @brief Вычитает одну дробь из другой.
     * @param lhs Левая дробь.
     * @param rhs Правая дробь.
     * @return Результат вычитания.
     */
    friend Fraction operator-(Fraction lhs, const Fraction& rhs);
    
    /**
     * @brief Умножает две дроби.
     * @param lhs Левая дробь.
     * @param rhs Правая дробь.
     * @return Результат умножения.
     */
    friend Fraction operator*(Fraction lhs, const Fraction& rhs);
    
    /**
     * @brief Делит одну дробь на другую.
     * @param lhs Делимое.
     * @param rhs Делитель.
     * @return Результат деления.
     * @exception std::invalid_argument Если делитель равен нулю.
     */
    friend Fraction operator/(Fraction lhs, const Fraction& rhs);

    /**
     * @brief Проверяет равенство двух дробей.
     * @param lhs Первая дробь.
     * @param rhs Вторая дробь.
     * @return true, если дроби равны; иначе false.
     */
    friend bool operator==(const Fraction& lhs, const Fraction& rhs);
    
    /**
     * @brief Проверяет неравенство двух дробей.
     * @param lhs Первая дробь.
     * @param rhs Вторая дробь.
     * @return true, если дроби не равны; иначе false.
     */
    friend bool operator!=(const Fraction& lhs, const Fraction& rhs);

    /**
     * @brief Проверяет, меньше ли первая дробь второй.
     * @param lhs Первая дробь.
     * @param rhs Вторая дробь.
     * @return true, если lhs меньше rhs; иначе false.
     */
    friend bool operator<(const Fraction& lhs, const Fraction& rhs);
    
    /**
     * @brief Проверяет, больше ли первая дробь второй.
     * @param lhs Первая дробь.
     * @param rhs Вторая дробь.
     * @return true, если lhs больше rhs; иначе false.
     */
    friend bool operator>(const Fraction& lhs, const Fraction& rhs);
    
    /**
     * @brief Проверяет, меньше ли первая дробь второй или равна ей.
     * @param lhs Первая дробь.
     * @param rhs Вторая дробь.
     * @return true, если lhs меньше или равна rhs; иначе false.
     */
    friend bool operator<=(const Fraction& lhs, const Fraction& rhs);
    
    /**
     * @brief Проверяет, больше ли первая дробь второй или равна ей.
     * @param lhs Первая дробь.
     * @param rhs Вторая дробь.
     * @return true, если lhs больше или равна rhs; иначе false.
     */
    friend bool operator>=(const Fraction& lhs, const Fraction& rhs);

    /**
     * @brief Выводит дробь в поток.
     * @param out Поток вывода, например std::cout.
     * @param f Дробь, которую необходимо вывести.
     * @return Ссылка на поток вывода.
     *
     * Дробь выводится в формате "числитель/знаменатель".
     */
    friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
};

#endif
