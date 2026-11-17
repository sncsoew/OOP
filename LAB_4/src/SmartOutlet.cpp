#include "SmartOutlet.h"

SmartOutlet::SmartOutlet(const char* n, double power, double v)
    : PoweredDevice(n, power), voltage(v) {
}

SmartOutlet::SmartOutlet(const SmartOutlet& other)
    : PoweredDevice(other), voltage(other.voltage) {
}

SmartOutlet& SmartOutlet::operator=(const SmartOutlet& other) {
    if(this != &other){
        PoweredDevice::operator=(other);
        voltage = other.voltage;
    }

    return * this;
}

double SmartOutlet::getCurrentVoltage() const {
    return voltage;
}

const char* SmartOutlet::getStatus() const {
    return isOn ? "ON" : "OFF";
}

const char* SmartOutlet::getDeviceType() const {
    return "SmartOutlet";
}

double SmartOutlet::getPowerUsage() const {
    return isOn ? powerConsumption : 0.0;
}