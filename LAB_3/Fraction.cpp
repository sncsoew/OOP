#include "Fraction.h"
#include <numeric>

/// Инициализация статического счётчика объектов класса Fraction.
int Fraction::objectCount = 0;


/**
 * @brief Нормализует дробь.
 *
 * Проверяет знаменатель, переносит отрицательный знак в числитель
 * и сокращает дробь с помощью наибольшего общего делителя.
 *
 * @exception std::invalid_argument Если знаменатель равен нулю.
 */
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

/**
 * @brief Конструктор по умолчанию.
 *
 * Создаёт дробь со значением 0/1 и увеличивает счётчик объектов.
 */
Fraction::Fraction() : numerator(0), denominator(1) {
    ++objectCount;
}

/**
 * @brief Создаёт дробь из целого числа.
 * @param wholeNumber Целое число, которое требуется представить в виде дроби.
 *
 * Знаменатель устанавливается равным единице.
 * Увеличивает счётчик объектов.
 */
Fraction::Fraction(long long wholeNumber) : numerator(wholeNumber), denominator(1) {
    ++objectCount;
}

/**
 * @brief Создаёт дробь с указанными числителем и знаменателем.
 * @param num Числитель дроби.
 * @param den Знаменатель дроби.
 *
 * После инициализации выполняет нормализацию дроби
 * и увеличивает счётчик объектов.
 *
 * @exception std::invalid_argument Если знаменатель равен нулю.
 */
Fraction::Fraction(long long num, long long den) : numerator(num), denominator(den) {
    normalize();
    ++objectCount;
}

/**
 * @brief Конструктор копирования.
 * @param other Объект Fraction, данные которого копируются.
 *
 * Создаёт новый объект с теми же числителем и знаменателем
 * и увеличивает счётчик объектов.
 */
Fraction::Fraction(const Fraction& other): numerator(other.numerator), denominator(other.denominator) {
    ++objectCount;
}

/**
 * @brief Деструктор класса Fraction.
 *
 * Уменьшает счётчик существующих объектов и выводит сообщение
 * об уничтожении объекта.
 */
Fraction::~Fraction() {
    --objectCount;
    std::cout << "Объект Fraction уничтожен\n";
}

/**
 * @brief Возвращает числитель дроби.
 * @return Значение числителя.
 *
 * Увеличивает счётчик обращений к объекту.
 */
long long Fraction::getNumerator() const {
    ++accessCount;
    return numerator;
}

/**
 * @brief Возвращает знаменатель дроби.
 * @return Значение знаменателя.
 *
 * Увеличивает счётчик обращений к объекту.
 */
long long Fraction::getDenominator() const {
    ++accessCount;
    return denominator;
}

/**
 * @brief Возвращает счётчик обращений к объекту.
 * @return Текущее значение accessCount.
 */
int Fraction::getAccessCount() const {
    return accessCount;
}

/**
 * @brief Возвращает количество существующих объектов Fraction.
 * @return Текущее значение статического счётчика objectCount.
 */
int Fraction::getObjectCount() {
    return objectCount;
}

/**
 * @brief Преобразует дробь в строку.
 * @return Строка в формате "числитель/знаменатель".
 *
 * Увеличивает счётчик обращений к объекту.
 */
std::string Fraction::toString() const {
    ++accessCount;
    return std::to_string(numerator) + "/" + std::to_string(denominator);
}

/**
 * @brief Выполняет префиксный инкремент.
 * @return Ссылка на изменённый объект.
 *
 * Увеличивает числитель на единицу и нормализует дробь.
 */
Fraction& Fraction::operator++() {
    ++numerator;
    normalize();
    return *this;
}

/**
 * @brief Выполняет постфиксный инкремент.
 * @param dummy Фиктивный параметр, отличающий постфиксный оператор от префиксного.
 * @return Копия дроби до изменения.
 *
 * Сохраняет исходное значение, увеличивает текущую дробь
 * и возвращает сохранённую копию.
 */
Fraction Fraction::operator++(int) {
    Fraction old(*this);
    ++(*this);
    return old;
}

/**
 * @brief Выполняет префиксный декремент.
 * @return Ссылка на изменённый объект.
 *
 * Уменьшает числитель на единицу и нормализует дробь.
 */
Fraction& Fraction::operator--() {
    --numerator;
    normalize();
    return *this;
}

/**
 * @brief Выполняет постфиксный декремент.
 * @param dummy Фиктивный параметр, отличающий постфиксный оператор от префиксного.
 * @return Копия дроби до изменения.
 *
 * Сохраняет исходное значение, уменьшает текущую дробь
 * и возвращает сохранённую копию.
 */
Fraction Fraction::operator--(int) {
    Fraction old(*this);
    --(*this);
    return old;
}

/**
 * @brief Складывает текущую дробь с другой дробью.
 * @param other Дробь, которую необходимо прибавить.
 * @return Ссылка на изменённый объект.
 *
 * Результат нормализуется перед возвратом.
 */
Fraction& Fraction::operator+=(const Fraction& other) {
    numerator = numerator * other.denominator + other.numerator * denominator;
    denominator *= other.denominator;
    normalize();
    return *this;
}

/**
 * @brief Вычитает другую дробь из текущей.
 * @param other Дробь, которую необходимо вычесть.
 * @return Ссылка на изменённый объект.
 *
 * Результат нормализуется перед возвратом.
 */
Fraction& Fraction::operator-=(const Fraction& other) {
    numerator = numerator * other.denominator - other.numerator * denominator;
    denominator *= other.denominator;
    normalize();
    return *this;
}

/**
 * @brief Умножает текущую дробь на другую дробь.
 * @param other Дробь, на которую выполняется умножение.
 * @return Ссылка на изменённый объект.
 *
 * Результат нормализуется перед возвратом.
 */
Fraction& Fraction::operator*=(const Fraction& other) {
    numerator *= other.numerator;
    denominator *= other.denominator;
    normalize();
    return *this;
}

/**
 * @brief Делит текущую дробь на другую дробь.
 * @param other Дробь, на которую выполняется деление.
 * @return Ссылка на изменённый объект.
 *
 * Результат нормализуется перед возвратом.
 *
 * @exception std::invalid_argument Если числитель делителя равен нулю.
 */
Fraction& Fraction::operator/=(const Fraction& other) {
    if (other.numerator == 0) {
        throw std::invalid_argument("Деление на нулевую дробь.");
    }
    numerator *= other.denominator;
    denominator *= other.numerator;
    normalize();
    return *this;
}

/**
 * @brief Складывает две дроби.
 * @param lhs Левая дробь.
 * @param rhs Правая дробь.
 * @return Результат сложения.
 *
 * Использует оператор += для выполнения сложения.
 */
Fraction operator+(Fraction lhs, const Fraction& rhs) {
    lhs += rhs;
    return lhs;
}

/**
 * @brief Вычитает одну дробь из другой.
 * @param lhs Уменьшаемая дробь.
 * @param rhs Вычитаемая дробь.
 * @return Результат вычитания.
 *
 * Использует оператор -= для выполнения вычитания.
 */
Fraction operator-(Fraction lhs, const Fraction& rhs) {
    lhs -= rhs;
    return lhs;
}

/**
 * @brief Умножает две дроби.
 * @param lhs Левая дробь.
 * @param rhs Правая дробь.
 * @return Результат умножения.
 *
 * Использует оператор *= для выполнения умножения.
 */
Fraction operator*(Fraction lhs, const Fraction& rhs) {
    lhs *= rhs;
    return lhs;
}

/**
 * @brief Делит одну дробь на другую.
 * @param lhs Делимое.
 * @param rhs Делитель.
 * @return Результат деления.
 *
 * Использует оператор /= для выполнения деления.
 *
 * @exception std::invalid_argument Если делитель равен нулю.
 */
Fraction operator/(Fraction lhs, const Fraction& rhs) {
    lhs /= rhs;
    return lhs;
}

/**
 * @brief Проверяет равенство двух дробей.
 * @param lhs Первая дробь.
 * @param rhs Вторая дробь.
 * @return true, если числители и знаменатели совпадают; иначе false.
 */
bool operator==(const Fraction& lhs, const Fraction& rhs) {
    return lhs.numerator == rhs.numerator && lhs.denominator == rhs.denominator;
}

/**
 * @brief Проверяет неравенство двух дробей.
 * @param lhs Первая дробь.
 * @param rhs Вторая дробь.
 * @return true, если дроби не равны; иначе false.
 */
bool operator!=(const Fraction& lhs, const Fraction& rhs) {
    return !(lhs == rhs);
}

/**
 * @brief Проверяет, меньше ли первая дробь второй.
 * @param lhs Первая дробь.
 * @param rhs Вторая дробь.
 * @return true, если lhs меньше rhs; иначе false.
 *
 * Сравнивает дроби перекрёстным умножением.
 */
bool operator<(const Fraction& lhs, const Fraction& rhs) {
    return lhs.numerator * rhs.denominator < rhs.numerator * lhs.denominator;
}

/**
 * @brief Проверяет, больше ли первая дробь второй.
 * @param lhs Первая дробь.
 * @param rhs Вторая дробь.
 * @return true, если lhs больше rhs; иначе false.
 */
bool operator>(const Fraction& lhs, const Fraction& rhs) {
    return rhs < lhs;
}

/**
 * @brief Проверяет, меньше ли первая дробь второй или равна ей.
 * @param lhs Первая дробь.
 * @param rhs Вторая дробь.
 * @return true, если lhs меньше или равна rhs; иначе false.
 */
bool operator<=(const Fraction& lhs, const Fraction& rhs) {
    return !(lhs > rhs);
}

/**
 * @brief Проверяет, больше ли первая дробь второй или равна ей.
 * @param lhs Первая дробь.
 * @param rhs Вторая дробь.
 * @return true, если lhs больше или равна rhs; иначе false.
 */
bool operator>=(const Fraction& lhs, const Fraction& rhs) {
    return !(lhs < rhs);
}

/**
 * @brief Выводит дробь в поток.
 * @param out Поток вывода, например std::cout.
 * @param f Дробь, которую необходимо вывести.
 * @return Ссылка на поток вывода.
 *
 * Выводит числитель и знаменатель через символ '/'.
 */
std::ostream& operator<<(std::ostream& out, const Fraction& f) {
    out << f.numerator << "/" << f.denominator;
    return out;
}