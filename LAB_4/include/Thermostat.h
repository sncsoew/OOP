#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "PoweredDevice.h"

class Thermostat : public PoweredDevice {
private:
    double temperature;
    char mode[20];
public:
    Thermostat(const char* name, double power, double temperature, const char* mode);
    Thermostat(const Thermostat& other);
    Thermostat& operator=(const Thermostat& other);

    const char* getStatus() const override;
    const char* getDeviceType() const override;
    
    double getPowerUsage() const override;

    void setTemperature(double value);
    double getTemperature() const;
};

#endif