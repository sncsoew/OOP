#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include <iostream>

class SmartDevice {
protected:
    char name[50];
    bool isOn;
public:
    SmartDevice(const char* name);
    SmartDevice(const SmartDevice& other);
    SmartDevice& operator=(const SmartDevice& other);

    virtual ~SmartDevice();

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual const char* getStatus() const = 0;

    virtual const char* getDeviceType() const;

    const char* getName() const;

    friend std::ostream& operator<<(
        std::ostream& out,
        const SmartDevice& device
    );
};

#endif
