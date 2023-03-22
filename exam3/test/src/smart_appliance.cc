/* Copyright 2020 CSCE240 Exam 3
 */
#include <test/inc/smart_appliance.h>
#include <iostream>
#include <string>
using exam3::SmartAppliance;
using exam3::SmartLight;
using exam3::SmartThermostat;
using std::cout;
using std::endl;
using std::string;


int main(int argc, char* argv[]) {
  const int kArg = 1;
  int test = atoi(argv[kArg]);
  SmartAppliance *appliance = nullptr;
  bool passed = false;

  if (test == 0) {
      cout << " Testing SmartLight::Activate 1 of 2" << endl;
      appliance = new SmartLight();
      passed = TestSmartApplianceActivate(0, appliance, "Light");
      delete appliance;
      return passed ? 0 : 1;
  } else if (test == 1) {
      cout << " Testing SmartLight::Activate 2 of 2" << endl;
      appliance = new SmartLight();
      passed = TestSmartApplianceActivate(1, appliance, "Light");
      delete appliance;
      return passed ? 0 : 1;
  } else if (test == 2) {
      cout << " Testing SmartLight::Deactivate 1 of 2" << endl;
      appliance = new SmartLight();
      passed = TestSmartApplianceDeactivate(0, appliance, "Light");
      delete appliance;
      return passed ? 0 : 1;
  } else if (test == 3) {
      cout << " Testing SmartLight::Deactivate 2 of 2" << endl;
      appliance = new SmartLight();
      passed = TestSmartApplianceDeactivate(1, appliance, "Light");
      return passed ? 0 : 1;
      delete appliance;
  } else if (3 < test && test < 9) {
    int i = test - 3;
    cout << " Testing SmartLight::Set " << i << " of 5" << endl;
    appliance = new SmartLight();
    passed = TestSmartLightSet(i, appliance);
    delete appliance;
    return passed ? 0 : 1;
  } else if (test == 9) {
    cout << " Testing SmartThermostat::Activate 1 of 2" << endl;
    appliance = new SmartThermostat;
    passed = TestSmartApplianceActivate(0, appliance, "Thermostat");
    delete appliance;
    return passed ? 0 : 1;
  } else if (test == 10) {
    cout << " Testing SmartThermostat::Activate 2 of 2" << endl;
    appliance = new SmartThermostat;
    passed = TestSmartApplianceActivate(1, appliance, "Thermostat");
    delete appliance;
    return passed ? 0 : 1;
  } else if (test == 11) {
    cout << " Testing SmartThermostat::Deactivate 1 of 2" << endl;
    appliance = new SmartThermostat;
    passed = TestSmartApplianceDeactivate(1, appliance, "Thermostat");
    delete appliance;
    return passed ? 0 : 1;
  } else if (test == 12) {
    cout << " Testing SmartThermostat::Deactivate 2 of 2" << endl;
    appliance = new SmartThermostat;
    passed = TestSmartApplianceDeactivate(1, appliance, "Thermostat");
    delete appliance;
    return passed ? 0 : 1;
  } else {
    int i = test - 12;
    cout << " Testing SmartThermostat::Set " << i << " of 3" << endl;
    appliance = new SmartThermostat;
    passed = TestSmartThermostatSet(i, appliance);
    delete appliance;
    return passed ? 0 : 1;
  }
}

                           
bool TestSmartApplianceActivate(unsigned int test,
                                SmartAppliance* appliance,
                                const string& name) {
  cout << "  Smart" << name << "::Activate : ";
  if (test == 1) {
    if (appliance->Activate() == name +  " activated") {
      cout << "PASSED" << endl;
      return true;
    } else {
      cout << "FAILED" << endl;
      return false;
    }
  } else {  // test 2
    appliance->Activate();
    if (appliance->Activate() == name +  " active") {
      cout << "PASSED" << endl;
      return true;
    } else {
      cout << "FAILED" << endl;
      return false;
    }
  }
}

bool TestSmartApplianceDeactivate(unsigned int test,
                                  SmartAppliance* appliance,
                                  const string& name) {
  cout << "  Smart" << name << "::Deactivate : ";
  if (test == 1) {
    if (appliance->Deactivate() == "") {
      cout << "PASSED" << endl;
      return true;
    } else {
      cout << "FAILED" << endl;
      return false;
    }
  } else {  // test 2
    appliance->Activate();
    if (appliance->Deactivate() == name +  " deactivated") {
      cout << "PASSED" << endl;
      return true;
    } else {
      cout << "FAILED" << endl;
      return false;
    }
  }
}

bool TestSmartLightSet(unsigned int test, exam3::SmartAppliance* appliance) {
  if (test == 1)
    return (TestSmartApplianceSet(test, 0, 0, "", appliance, "Light"));
  else if (test == 2)
    return (TestSmartApplianceSet(
        test, 0, 10, "Light set from off to on", appliance, "Light"));
  else if (test == 3)
    return (TestSmartApplianceSet(
        test, 13, 31, "Light set on", appliance, "Light"));
  else if (test == 4)
    return (TestSmartApplianceSet(
        test, 0, 0, "Light set off", appliance, "Light"));
  else  // test == 5
    return (TestSmartApplianceSet(
        test, 99, 0, "Light set from on to off", appliance, "Light"));
}

bool TestSmartThermostatSet(unsigned int test,
                            exam3::SmartAppliance* appliance) {
  if (test == 1)
    return (TestSmartApplianceSet(test, 0, 0, "", appliance, "Thermostat"));
  else if (test == 2)
    return (TestSmartApplianceSet(
        test, 10, 5, "Thermostat set from 46 to 43", appliance, "Thermostat"));
  else  // test == 3
    return (TestSmartApplianceSet(
        test, 41, 41, "Thermostat set to 65", appliance, "Thermostat"));
}

bool TestSmartApplianceSet(unsigned int test,
                           unsigned int start_setting,
                           unsigned int test_setting,
                           const string& expected,
                           exam3::SmartAppliance* appliance,
                           const string& name) {
  cout << "  Smart" << name << "::Set : ";
  if (test == 1) {
    if (appliance->Set(20) == "") {
      cout << "PASSED" << endl;
      return true;
    } else {
      cout << "FAILED" << endl;
      return false;
    }
  } else  {  // test 2 ~ 5
    appliance->Activate();
    appliance->Set(start_setting);
    if (appliance->Set(test_setting) == expected) {
      cout << "PASSED" << endl;
      return true;
    } else {
      cout << "FAILED" << endl;
      return false;
    }
  }
}
