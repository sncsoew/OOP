#include "SmartDevice.h"
#include <cstring>

SmartDevice::SmartDevice(const char* n) : isOn(false) {
    strncpy(name, n, 49);
    name[49] = '\0';
}

SmartDevice::SmartDevice(const SmartDevice& other) : isOn(other.isOn) {
    strcpy(name, other.name);
}

SmartDevice& SmartDevice::operator=(const SmartDevice& other) {
    if (this != &other){
        strcpy(name, other.name);
        isOn = other.isOn;
    }
     return *this;
}

SmartDevice::~SmartDevice() {}

const char* SmartDevice::getDeviceType() const {
    return "SmartDevice";
}

const char* SmartDevice::getName() const{
    return name;
}

std::ostream& operator<<(std::ostream& out, const SmartDevice& device) {
    out << device.getDeviceType()
        << " " << device.getName()
        << " Status: " << device.getStatus();
    return out;
}