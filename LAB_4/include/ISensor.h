#ifndef ISENSOR_H
#define ISENSOR_H

class ISensor{
public:
    virtual ~ISensor() {}
    virtual double getCurrentVoltage() const = 0;
};

#endif
