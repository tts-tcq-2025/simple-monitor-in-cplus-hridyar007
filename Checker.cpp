#include <assert.h>
#include <iostream>
using namespace std;

bool TemperatureIsOk(float temperature) 
{
  if (temperature < 0 || temperature > 45) 
  {
    cout << "Temperature out of range!\n";
    return false;
  }
  return true;
}

bool SocIsOk(float soc) 
{
  if (soc < 20 || soc > 80) 
  {
    cout << "State of Charge out of range!\n";
    return false;
  }
  return true;
}

bool ChargeRateIsOk(float chargeRate) 
{
  if (chargeRate > 0.8) 
  {
    cout << "Charge Rate out of range!\n";
    return false;
  }
  return true;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) 
{
  return TemperatureIsOk(temperature) && SocIsOk(soc) && ChargeRateIsOk(chargeRate);
}

int main() 
{
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
