#include <assert.h>
#include "battery.h"

void runTests() {
    assert(batteryIsOk(25, 70, 0.7) == true);   // all normal
    assert(batteryIsOk(-5, 70, 0.7) == false);  // temp too low
    assert(batteryIsOk(50, 70, 0.7) == false);  // temp too high
    assert(batteryIsOk(25, 10, 0.7) == false);  // soc too low
    assert(batteryIsOk(25, 90, 0.7) == false);  // soc too high
    assert(batteryIsOk(25, 70, 0.9) == false);  // charge rate too high
    assert(batteryIsOk(0, 20, 0.8) == true);    // edge: exact lower bounds
    assert(batteryIsOk(45, 80, 0.8) == true);   // edge: exact upper bounds
}
