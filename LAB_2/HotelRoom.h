#ifndef HOTELROOM_H
#define HOTELROOM_H

#include <iostream>
#include <string>


/**
 * @class Guest
 * @brief Представляет гостя гостиницы.
 *
 * Класс хранит имя и возраст гостя и предоставляет
 * методы для получения и вывода этой информации.
 */

class Guest
{
    private:
    std::string name;///< Имя гостя
    int age;         ///< Возраст гостя

    public:

    /**
     * @brief Конструктор по умолчанию
     *
     * Создаёт гостя с именем "Не указан" и возрастом 0.
     */

    Guest(): name("Не указан"), age(0) {}

    /**
     * @brief Параметризованный конструктор
     *
     * @param guestName Имя гостя
     * @param guestAge Возраст гостя
     */

    Guest(const std::string& guestName, int guestAge)
        : name(guestName), age(guestAge){}
    ~Guest();
    /**
     * @brief Возвращает имя гостя
     *
     * @return Имя гостя
     */
    std::string getName() const
    {
        return name;
    }

    /**
     * @brief Возвращает возраст гостя
     *
     * @return Возраст гостя
     */

    int getAge() const
    {
        return age;
    }

    /**
     * @brief Выводит информацию о гостt
     *
     * Выводит имя гостя и возраст
     */
    void printInfo() const
    {
        std::cout << "Имя гостя: " << name << '\n';
        std::cout << "Возраст: " << age << '\n';
    }

};


/**
 * @class HotelRoom
 * @brief Представляет гостиничный номер.
 *
 * Класс хранит информацию о номере, этаже, стоимости проживания,
 * состоянии занятости и текущем госте.
 *
 * Класс обеспечивает проверку корректности номера, этажа и цены,
 * а также операции заселения и выселения гостей.
 *
 * @warning Номер комнаты и цена должны быть положительными.
 */

class HotelRoom
{
    private:
    
    int roomNumber;         ///< Номер комнаты
    int floor;              ///< Номер этажа
    double pricePerNight;   ///< Стоимость проживания за одну ночь
    bool occupied;          ///< Состояние комнаты: занята или свободна
    Guest guest;            ///< Текущий гость комнаты  


    static int objectCount; ///< Количество существующих объектов HotelRoom

    /**
     * @brief Проверяет корректность номера комнаты
     *
     * @param number Номер комнаты
     * @return true, если номер положительный, иначе false
     */

    bool isValidRoomNumber(int number) const;
    
    /**
     * @brief Проверяет корректность номера этажа
     *
     * @param floorNumber Номер этажа
     * @return true, если этаж находится от 1 до 100, иначе false
     */

    bool isValidPrice(double price) const;
    
    /**
     * @brief Проверяет корректность цены
     *
     * @param price Цена проживания
     * @return true, если цена положительная, иначе false
     */
    
    bool isValidFloor(int floorNumber) const;

    public:
    
    /**
     * @brief Конструктор по умолчанию
     *
     * Создаёт свободный номер с номером 1,
     * этажом 1 и стоимостью 100.0.
     */

    HotelRoom();
    
    /**
     * @brief Параметризованный конструктор
     *
     * @param number Номер комнаты
     * @param floorNumber Номер этажа
     * @param price Стоимость проживания за ночь
     */
    
    HotelRoom(int number, int floorNumber, double price);
    
    /**
     * @brief Конструктор копирования
     *
     * Создаёт новый объект как копию существующего объекта HotelRoom.
     *
     * @param other Объект HotelRoom для копирования
     */

    HotelRoom(const HotelRoom& other);

    /**
     * @brief Деструктор
     *
     * Уменьшает счётчик существующих объектов HotelRoom.
     */
    
     ~HotelRoom();
    
    /**
     * @brief Возвращает номер комнаты
     *
     * @return Номер комнаты
     */

     int getRoomNumber() const;
    
    /**
     * @brief Возвращает номер этажа
     *
     * @return Номер этажа
     */
    
     int getFloor() const;
    
    /**
     * @brief Возвращает стоимость проживания за ночь
     *
     * @return Стоимость проживания
     */
    
    double getPricePerNight() const;
    
    /**
     * @brief Проверяет, занята ли комната
     *
     * @return true, если комната занята, иначе false
     */ 
    
    bool isOccupied() const;

    /**
     * @brief Возвращает текущего гостя
     *
     * @return Объект Guest
     */
    
    Guest getGuest() const;
    
    /**
     * @brief Заселяет гостя в комнату
     *
     * Комната должна быть свободной.
     * Имя гостя должно быть указано, а возраст должен быть
     * не менее 18 лет.
     *
     * @param newGuest Новый гость
     * @return true, если заселение выполнено успешно,
     *         иначе false
     */
    
    bool checkIn(const Guest& newGuest);
    
    /**
     * @brief Выселяет гостя из комнаты
     *
     * @return true, если гость успешно выселен,
     *         иначе false
     */
    bool checOut();

    /**
     * @brief Изменяет стоимость проживания
     *
     * Новая цена должна быть положительной.
     *
     * @param newPrice Новая стоимость проживания
     * @return true, если цена успешно изменена,
     *         иначе false
     */
    bool changePrice(double newPrice);

    /**
     * @brief Выводит информацию о гостиничном номере
     *
     * Выводит номер комнаты, этаж, стоимость,
     * статус занятости и информацию о госте.
     */
    void printInfo() const;
    
    /**
     * @brief Возвращает количество существующих объектов HotelRoom
     *
     * @return Количество существующих объектов
     */
    static int getObjectCount();

};

#endif