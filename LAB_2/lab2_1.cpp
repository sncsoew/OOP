# include "HotelRoom.h"

int main()
{
    Guest guest1("Иван Иванович", 25);

    HotelRoom room1;

    HotelRoom room2(205, 2, 250.0);

    room2.checkIn(guest1);

    HotelRoom room3(room2);

    std::cout << "\n=== НАЧАЛЬНОЕ СОСТОЯНИЕ ===\n";

    std::cout << "\nКомната 1:";
    room1.printInfo();

    std::cout << "\nКомната 2:";
    room2.printInfo();

    std::cout << "\nКомната 3:";
    room3.printInfo();

    std::cout << "\n=== КОРРЕКТНЫЕ ОПЕРАЦИИ ===\n";

    Guest guest2("Анна Смирнова", 30);
    room1.checkIn(guest2);

    room2.changePrice(300.0);

    room3.checOut();

    std::cout << "\n=== НЕКОРРЕКТНЫЕ ОПЕРАЦИИ ===\n";

    Guest guest3("Пётр Иванов", 40);
    room1.checkIn(guest3);

    room3.checOut();

    room2.changePrice(-100.0);

    Guest guest4("Алексей Иванов", 16);
    room3.checkIn(guest4);
    
}