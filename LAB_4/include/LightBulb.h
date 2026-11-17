#ifndef LIGHTBULB_H
#define LIGHTBULB_H

#include "PoweredDevice.h"

class LightBulb : public PoweredDevice {
private:
    int brightness;
    char color[30];

public:
    LightBulb(const char* name, double power, int brightness, const char* color);
    LightBulb(const LightBulb& other);
    LightBulb& operator=(const LightBulb& other);

    const char* getStatus() const override;
    const char* getDeviceType() const override;

    double getPowerUsage() const override;

    void setBrightness(int value);
    int getBrightness() const;
};

#endif