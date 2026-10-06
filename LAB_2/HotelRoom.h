#ifndef HOTELROOM_H
#define HOTELROOM_H

#include <string>




class Guest
{
    
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