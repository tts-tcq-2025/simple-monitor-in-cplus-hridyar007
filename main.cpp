#include <iostream>
#include "battery.h"

void runTests();

int main() {
    runTests();
    std::cout << "All tests passed!\n";

    // Example usage
    batteryIsOk(25, 70, 0.7);
    batteryIsOk(50, 85, 0.0);

    return 0;
}
