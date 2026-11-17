#include "SmartDevice.h"
#include "LightBulb.h"
#include "Thermostat.h"
#include "SmartOutlet.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>

int loadDevices(const char* fileName, SmartDevice* devices[], int maxCount) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL){
        return -1;
    }

    char line[256];
    int count = 0;

    while (fgets(line, sizeof(line), file) && count < maxCount) {
        
        if (line[0] == '#' || line[0] == '\n') {
            continue;
        }

        char type[30], name[50], a[30], b[30];
        double power;

        if (sscanf(line, "%29[^;];%49[^;];%lf;%29[^;];%29s",
                   type, name, &power, a, b) != 5) {
            continue;
        }

        if (strcmp(type, "LightBulb") == 0) {
            devices[count++] =
                new LightBulb(name, power, atoi(a), b);
        }
        else if (strcmp(type, "Thermostat") == 0) {
            devices[count++] =
                new Thermostat(name, power, atof(a), b);
        }
        else if (strcmp(type, "SmartOutlet") == 0) {
            devices[count++] =
                new SmartOutlet(name, power, atof(a));
        }
    }

    fclose(file);

    return count;
}