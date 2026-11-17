#include "LightBulb.h"
#include <cstring>
#include <stdexcept>

LightBulb::LightBulb(const char* n, double power, int b, const char* c) : PoweredDevice(n, power), brightness(b) {
    setBrightness(b);
    strncpy(color, c, 29);
    color[29] = '\0';
}

LightBulb::LightBulb(const LightBulb& other) : PoweredDevice(other), brightness(other.brightness) {
    strcpy(color, other.color);
}

LightBulb& LightBulb::operator=(const LightBulb& other) {
    if (this != &other) {
        PoweredDevice::operator=(other);

        brightness = other.brightness;
        strcpy(color, other.color);
    }

    return *this;
}

const char* LightBulb::getStatus() const {
    return isOn ? "ON" : "OFF";
}

const char* LightBulb::getDeviceType() const {
    return "LightBulb";
}

double LightBulb::getPowerUsage() const {
    return isOn ? powerConsumption * brightness / 100.0 : 0.0;
}

void LightBulb::setBrightness(int b) {
    if (b < 0 || b > 100) {
        throw std::out_of_range("Brightness must be from 0 to 100");
    }

    brightness = b;
}

int LightBulb::getBrightness() const {
    return brightness;
}