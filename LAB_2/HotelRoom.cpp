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

