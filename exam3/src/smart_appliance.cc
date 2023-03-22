/* Copyright 2020 Evan Owre
 */
#include <inc/smart_appliance.h>
#include <cmath>
//  using round();
using exam3::SmartLight;
using exam3::SmartThermostat;
SmartLight::SmartLight() {
  on_ = false;
  active_ = false;
}
SmartLight::~SmartLight() {/* empty */}
const std::string SmartLight::Activate() {
  std::string ret;
  if (active_ == false) {
    ret = "Light activated";
    active_ = true;
  } else {
    ret = "Light active";
  }
  return ret;
}
const std::string SmartLight::Deactivate() {
  std::string ret;
  if (active_ == true) {
    ret = "Light deactivated";
    active_ = false;
    on_ = false;
  }
  return ret;
}
const std::string SmartLight::Set(unsigned int setting) {
  std::string ret;
  if (active_ == false)
    return ret;
  if (setting == 0) {
    if (on_ == true) {
      on_ = false;
      ret = "Light set from on to off";
    } else {
      ret = "Light set off";
    }
  }
  if (setting > 0) {
    if (on_ == true) {
      ret = "Light set on";
    } else {
      on_ = true;
      ret = "Light set from off to on";
    }
  }
  return ret;
}
SmartThermostat::SmartThermostat() {
  setting_ = -1;
  active_ = false;
}
const std::string SmartThermostat::Activate() {
  std::string ret;
  if (active_ == false) {
    ret = "Thermostat activated";
    active_ = true;
  } else {
    ret = "Thermostat active";
  }
  return ret;
}
const std::string SmartThermostat::Deactivate() {
  std::string ret;
  if (active_ == true) {
    ret = "Thermostat deactivated";
    active_ = false;
  }
  return ret;
}
const std::string SmartThermostat::Set(unsigned int setting) {
  double temp_adj = round((setting*.6)+40);
  std::string ret;
  if (active_ == false)
    return ret;
  if (temp_adj == setting_) {
    ret = "Thermostat set to " + std::to_string(static_cast<int>(setting_));
  } else {
    ret = "Thermostat set from " + std::to_string(static_cast<int>(setting_))
      + " to " + std::to_string(static_cast<int>(temp_adj));
    setting_ = temp_adj;
  }
  return ret;
}

