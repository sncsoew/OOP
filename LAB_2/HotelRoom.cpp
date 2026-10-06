#include "HotelRoom.h"

int HotelRoom::objectCount = 0;

bool HotelRoom::isValidRoomNumber(int number) const
{
    return number > 0;
}

bool HotelRoom::isValidFloor(int floorNumber) const
{
    return floorNumber >= 1 && floorNumber <= 100;
}

bool HotelRoom::isValidPrice(double price) const
{
    return price > 0;
}

HotelRoom::HotelRoom()
    : roomNumber(1),
      floor(1),
      pricePerNight(100.0),
      occupied(false),
      guest()
{
    ++objectCount;
}

HotelRoom::HotelRoom(int number, int floorNumber, double price)
    : roomNumber(1),
      floor(1),
      pricePerNight(100.0),
      occupied(false),
      guest()
{
    if (isValidRoomNumber(number))
    {
        roomNumber = number;
    }
    else
    {
        std::cout << "Ошибка: номер комнаты должен быть положительным.\n";
    }

    if (isValidFloor(floorNumber))
    {
        floor = floorNumber;
    }
    else
    {
        std::cout << "Ошибка: этаж должен быть от 1 до 100.\n";
    }

    if (isValidPrice(price))
    {
        pricePerNight = price;
    }
    else
    {
        std::cout << "Ошибка: цена должна быть положительной.\n";
    }

    ++objectCount;
}

HotelRoom::HotelRoom(const HotelRoom& other)
    : roomNumber(other.roomNumber),
      floor(other.floor),
      pricePerNight(other.pricePerNight),
      occupied(other.occupied),
      guest(other.guest)
{
    ++objectCount;
}

HotelRoom::~HotelRoom()
{
    --objectCount;
    std::cout << "Объект HotelRoom уничтожен.\n";
}

int HotelRoom::getRoomNumber() const
{
    return roomNumber;
}

int HotelRoom::getFloor() const
{
    return floor;
}

double HotelRoom::getPricePerNight() const
{
    return pricePerNight;
}

bool HotelRoom::isOccupied() const
{
    return occupied;
}

Guest HotelRoom::getGuest() const
{
    return guest;
}

bool HotelRoom::checkIn(const Guest& newGuest)
{
    if (occupied)
    {
        std::cout << "Ошибка: комната уже занята.\n";
        return false;
    }

    if (newGuest.getName() == "Не указан" ||
        newGuest.getName().empty())
    {
        std::cout << "Ошибка: имя гостя не указано.\n";
        return false;
    }

    if (newGuest.getAge() < 18)
    {
        std::cout << "Ошибка: гость должен быть совершеннолетним.\n";
        return false;
    }

    guest = newGuest;
    occupied = true;

    std::cout << "Гость успешно заселён.\n";
    return true;
}

bool HotelRoom::checOut()
{
    if (!occupied)
    {
        std::cout << "Ошибка: комната уже свободна.\n";
        return false;
    }

    occupied = false;
    guest = Guest();

    std::cout << "Гость успешно выселен.\n";
    return true;
}

bool HotelRoom::changePrice(double newPrice)
{
    if (!isValidPrice(newPrice))
    {
        std::cout << "Ошибка: цена должна быть положительной.\n";
        return false;
    }

    pricePerNight = newPrice;

    std::cout << "Цена успешно изменена.\n";
    return true;
}

void HotelRoom::printInfo() const
{
    std::cout << "\n--- Информация о номере ---\n";
    std::cout << "Номер комнаты: " << roomNumber << '\n';
    std::cout << "Этаж: " << floor << '\n';
    std::cout << "Цена за ночь: " << pricePerNight << '\n';

    if (occupied)
    {
        std::cout << "Статус: занята\n";
        guest.printInfo();
    }
    else
    {
        std::cout << "Статус: свободна\n";
    }
}

int HotelRoom::getObjectCount()
{
    return objectCount;
}
