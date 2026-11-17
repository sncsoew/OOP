#ifndef SMARTOUTLET_H
#define SMARTOUTLET_H

#include "PoweredDevice.h"
#include "ISensor.h"

class SmartOutlet : public PoweredDevice, public ISensor {
private:
    double voltage;
public:
    SmartOutlet(const char* name, double power,double voltage);
    SmartOutlet(const SmartOutlet& other);
    SmartOutlet& operator=(const SmartOutlet& other);

    double getCurrentVoltage() const override;

    const char* getStatus() const override;
    const char* getDeviceType() const override;

    double getPowerUsage() const override;
};

#endif