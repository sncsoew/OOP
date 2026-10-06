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
}