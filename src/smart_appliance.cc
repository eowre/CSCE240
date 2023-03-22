/* Copyright 2020 Evan Owre
 */
#include <inc/smart_appliance.h>
using exam3::SmartLight;
using exam3::SmartThermostat;
SmartAppliance::~SmartAppliance() {
}
SmartLight::SmartLight() {
  on_ = false;
  active_ = false;
}
SmartLight::~SmartLight() {
}
const std::string SmartLight::Activate() {
  std::string ret;
  if (active_ == false) {
    ret = "Light activated";
    active_ == true;
  } else {
    ret = "Light active";
  }
  return ret;
}
const std::string SmartLight::Deactivate() {
  std::string ret;
  if (active_ == true) {
    ret = "Light deactivated";
    active_ == false;
    on_ == false;
  }
  return ret;
}
const std::string SmartLight::Set(unsigned int setting) {
  std::string ret;
  if (active_ == false)
    return ret;
  if (on_ == false && setting > 0)
    ret = "Light set from off to on";
  if (on_ == true && setting >0)
    ret = "Light set on";
  if (on_ == false && setting == 0)
    ret = "Light set off";
  if (on_ == true && setting == 0)
    ret = "Light set from on to off";
  return ret;
}
SmartThermostat::SmartThermostat() {
  temp_ = -1;
  active_ = false;
}
const std::string SmartThermostat::Activate() {
  std::string ret;
  if (active_ == false) {
    ret = "Thermostat activted";
    active_ == true;
  } else {
    ret = "Thermostat active";
  }
  return ret;
}
const std::string SmartThermostat::Deactivate() {
  std::string ret;
  if (active_ == true) {
    ret = "Thermostat ddeactivated";
    active_ = false;
  }
  return ret;
}
const std::string SmartThermostat::Set(unsigned int setting) {
  double temp_adj = (setting*.6)+40;
  std::string ret;
  if (active_ == false)
    return ret;
  if (temp_adj == temp_) {
    ret = "Thermostat set to " + std::to_string(temp_);
  } else {
    ret = "Thermostat set from " + std::to_string(temp_)
      + " to " + std::to_string(temp_adj);
    temp_ = temp_adj;
  }
  return ret;
}
}
