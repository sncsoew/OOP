#ifndef POWEREDDEVICE_H
#define POWEREDDEVICE_H

#include "SmartDevice.h"

class PoweredDevice : public SmartDevice {
protected:
    double powerConsumption;
public:
    static double totalEnergyKWh;

    PoweredDevice(const char* name, double power);
    PoweredDevice(const PoweredDevice& other);
    PoweredDevice& operator=(const PoweredDevice& other);

    virtual ~PoweredDevice();

    void turnOn() override;
    void turnOff() override;

    const char* getStatus() const override;
    const char* getDeviceType() const override;

    virtual double getPowerUsage() const;

    static double getTotalEnergyConsumed();
    static void resetTotalEnergyConsumde();
};

#endif