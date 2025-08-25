#include <iostream>
#include "battery.h"
#include "checker.h"

using namespace std;

// complexity = 1 (ternary only)
bool reportStatus(float value, const Range& range) {
    Status s = classify(value, range);
    cout << range.name << " = " << value 
         << " -> " << statusToString(s)
         << " (range " << range.min << "-" << range.max << ")\n";
    return s == Status::OK;
}

// complexity = 1 (no branching, only logical &&)
bool batteryIsOk(float temperature, float soc, float chargeRate) {
    Range temperatureRange = {0, 45, "Temperature"};
    Range socRange         = {20, 80, "State of Charge"};
    Range chargeRateRange  = {0, 0.8, "Charge Rate"};

    return reportStatus(temperature, temperatureRange)
        && reportStatus(soc, socRange)
        && reportStatus(chargeRate, chargeRateRange);
}
