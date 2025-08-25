#include <iostream>
#include "battery.h"
#include "checker.h"

using namespace std;

bool reportStatus(float value, const Range& range) {
    Status s = classify(value, range);
    if (s != Status::OK) {
        cout << range.name << " " << statusToString(s) 
             << " (value=" << value 
             << ", range=" << range.min << "-" << range.max << ")\n";
        return false;
    }
    return true;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
    Range temperatureRange = {0, 45, "Temperature"};
    Range socRange         = {20, 80, "State of Charge"};
    Range chargeRateRange  = {0, 0.8, "Charge Rate"};

    bool tempOk  = reportStatus(temperature, temperatureRange);
    bool socOk   = reportStatus(soc, socRange);
    bool rateOk  = reportStatus(chargeRate, chargeRateRange);

    return tempOk && socOk && rateOk;
}
