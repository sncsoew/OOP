#include "PoweredDevice.h"

double PoweredDevice::totalEnergyKWh = 0.0;

PoweredDevice::PoweredDevice(const char* n, double power) 
    : SmartDevice(n), powerConsuption(power) {
}

PoweredDevice::PoweredDevice(const PoweredDevice& other)
    : SmartDevice(other), powerConsuption(other.powerConsuption){

}

PoweredDevice& PoweredDevice::operator=(const PoweredDevice& other){
    if (this != &other) {
        SmartDevice::operator=(other);
        powerConsuption = other.powerConsuption;
    }
    return *this;
}

PoweredDevice::~PoweredDevice() {}

void PoweredDevice::turnOn() {
    if (!isOn) {
        isOn = true;
        totalEnergyKWh += powerConsuption / 1000.0;
    }
}

void PoweredDevice::turnOff() {
    isOn = false;
}

const char* PoweredDevice::getStatus() const {
    return isOn ? "ON" : "OFF";
}

const char* PoweredDevice::getDeviceType() const {
    return "PoweredDevice";
}

double PoweredDevice::getPowerUsage() const {
    return isOn ? powerConsuption : 0.0;
}

double PoweredDevice::getTotalEnergyConsumed() {
    return totalEnergyKWh;
}

void PoweredDevice::resetTotalEnergyConsumde() {
    totalEnergyKWh = 0.0;
}