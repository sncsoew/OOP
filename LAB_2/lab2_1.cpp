# include "HotelRoom.h"

/**
 * @brief Точка входа в программу.
 *
 * Создаёт объекты класса HotelRoom с использованием разных конструкторов,
 * выполняет корректные и некорректные операции с гостиничными номерами,
 * а также проверяет независимость объектов и работу статического счётчика.
 *
 * @return 0 при успешном завершении программы.
 *
 * @details
 * В программе выполняются следующие проверки:
 * - создание объекта конструктором по умолчанию;
 * - создание объекта параметризованным конструктором;
 * - создание объекта конструктором копирования;
 * - заселение и выселение гостей;
 * - изменение стоимости номера;
 * - обработка некорректных операций;
 * - проверка независимости объектов;
 * - проверка статического счётчика объектов.
 */
int test0()
{
        HotelRoom room2(205, 2, 250.0);
        return 0;
}


int main()
{
    setlocale(LC_ALL, ".UTF-8");
    
    // Guest guest1("Иван Иванович", 25);

    // HotelRoom room1;

    // HotelRoom room2(205, 2, 250.0);

    // room2.checkIn(guest1);

    // HotelRoom room3(room2);

    // std::cout << "\n=== НАЧАЛЬНОЕ СОСТОЯНИЕ ===\n";

    // std::cout << "\nКомната 1:";
    // room1.printInfo();

    // std::cout << "\nКомната 2:";
    // room2.printInfo();

    // std::cout << "\nКомната 3:";
    // room3.printInfo();

    // std::cout << "\n=== КОРРЕКТНЫЕ ОПЕРАЦИИ ===\n";

    // Guest guest2("Анна Смирнова", 30);
    // room1.checkIn(guest2);

    // room2.changePrice(300.0);

    // room3.checOut();

    // std::cout << "\n=== НЕКОРРЕКТНЫЕ ОПЕРАЦИИ ===\n";

    // Guest guest3("Пётр Иванов", 40);
    // room1.checkIn(guest3);

    // room3.checOut();

    // room2.changePrice(-100.0);

    // Guest guest4("Алексей Иванов", 16);
    // room3.checkIn(guest4);

    // std::cout << "\n=== СОСТОЯНИЕ ПОСЛЕ ОПЕРАЦИЙ ===\n";

    // std::cout << "\nКомната 1:";
    // room1.printInfo();

    // std::cout << "\nКомната 2:";
    // room2.printInfo();

    // std::cout << "\nКомната 3:";
    // room3.printInfo();

    // std::cout << "\n=== ПРОВЕРКА НЕЗАВИСИМОСТИ ОБЪЕКТОВ ===\n";

    // std::cout << "\nИзменяем только room2:\n";

    // room2.changePrice(500.0);
    // room2.checOut();

    // std::cout << "\nroom2 после изменений:";
    // room2.printInfo();

    // std::cout << "\nroom3 не должен измениться:";
    // room3.printInfo();

    // std::cout << "\n=== СЧЁТЧИК ОБЪЕКТОВ ===\n";
    // std::cout << "Количество существующих объектов HotelRoom: "
    //           << HotelRoom::getObjectCount() << '\n';

    /*Guest guest1("Иван Иванович", 25);
    HotelRoom room1(202,2,250.0);
    room1.checkIn(guest1);+*/
    test0();
    int a;
    std::cin >> a;
    return 0;
}