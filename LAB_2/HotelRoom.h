#ifndef HOTELROOM_H
#define HOTELROOM_H

#include <iostream>
#include <string>




class Guest
{
    private:
    std::string name;
    int age;

    public:
    Guest(): name("Не указан"), age(0) {}

    Guest(const std::string& guestName, int guestAge)
        : name(guestName), age(guestAge){}
    
    std::string getName() const
    {
        return name;
    }

    int getAge() const
    {
        return age;
    }

    void printInfo() const
    {
        std::cout << "Имя гостя: " << name << '\n';
        std::cout << "Возраст: " << age << '\n';
    }
};


class HotelRoom
{
    private:
    
    int roomNumber;
    int floor;
    double pricePerNight;
    bool occupied;
    Guest guest;


    static int objectCount;

    static bool isValidRoomNumber(int number);
    static bool isValidPrice(double price);
    static bool isValidFloor(int floorNumber);

    public:

    HotelRoom();
    HotelRoom(int number, int floorNumber, double price);
    HotelRoom(const HotelRoom& other);
     
    ~HotelRoom();

    int getRoomNumber() const;
    int getFloor() const;
    double getPricePerNight() const;
    bool isOccupied() const;
    Guest getGuest() const;

    bool checkIn(const Guest& newGuest);
    bool checOut();
    bool changePrice(double newPrice);

    void printInfo() const;
    
    static int getObjectCount();

};

#endif