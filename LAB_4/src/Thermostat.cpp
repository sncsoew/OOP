#include "Thermostat.h"
#include <cstring>
#include <stdexcept>

Thermostat::Thermostat(const char* n, double power, double temp, const char* m)
    : PoweredDevice(n, power), temperature(temp) {
    
    setTemperature(temp);
    strncpy(mode, m, 19);
    mode[19] = '\0';
}

Thermostat::Thermostat(const Thermostat& other)
    : PoweredDevice(other), temperature(other.temperature) {
    
    strcpy(mode, other.mode);
}

Thermostat& Thermostat::operator=(const Thermostat& other) {
    if (this != &other){
        PoweredDevice::operator=(other);
        temperature = other.temperature;
        strcpy(mode, other.mode);
    }
    return *this;
}

const char* Thermostat::getStatus() const {
    return isOn ? "ON" : "OFF";
}

const char* Thermostat::getDeviceType() const {
    return "Thermostat";
}

double Thermostat::getPowerUsage() const {
    return isOn ? powerConsumption : 0.0;
}

void Thermostat::setTemperature(double t) {
    if (t < 5 || t > 35) {
        throw std::out_of_range("Temperature must be from 5 to 35");
    }

    temperature = t;
}

double Thermostat::getTemperature() const {
    return temperature;
}