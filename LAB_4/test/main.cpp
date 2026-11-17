#include "LightBulb.h"
#include "Thermostat.h"
#include "SmartOutlet.h"
#include "DeviceLoader.cpp"


#include <iostream>
#include <exception>

int main() {
    const int MAX = 10;

    SmartDevice* devices[MAX];

    int count = 0;

    PoweredDevice::resetTotalEnergyConsumde();

    count = loadDevices("data/devices.txt", devices, MAX);

    if (count < 0){
        std::cout << "Cannot open data file!\n";
        return 1;
    }

    std::cout << "Loaded devices: " << count << "\n\n";

    std::cout << "=== DEVICES ===\n";
    for (int i = 0; i < count; i++) {

        std::cout << *devices[i] << std::endl;

        devices[i]->turnOn();
    }

    devices[0]->turnOn();

    std::cout << "\n=== ENERGY ===\n";
    std::cout << "Total energy: " << PoweredDevice::getTotalEnergyConsumed() << " kWh\n";

    std::cout << "\n=== SENSORS ===\n";
    for (int i = 0; i < count; i++) {
        ISensor* sensor = dynamic_cast<ISensor*>(devices[i]);
        if (sensor != NULL) {
            std::cout << devices[i]->getName() << ": " << sensor->getCurrentVoltage() << " V\n";
        }
    }

    std::cout << "\n=== COPYING ===\n";
    LightBulb first("TestLamp", 10, 80, "warm");
    LightBulb second(first);
    LightBulb third("OtherLamp", 5, 10, "white");
    third = first;
    first.setBrightness(25);
    std::cout << "Original: "
              << first.getBrightness() << "\n";
    std::cout << "Copy: "
              << second.getBrightness() << "\n";
    std::cout << "Assigned: "
              << third.getBrightness() << "\n";

    std::cout << "\n=== EXCEPTIONS ===\n";
    try {
        first.setBrightness(150);
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }
    for (int i = 0; i < count; i++) {
        delete devices[i];
    }
    return 0;
}