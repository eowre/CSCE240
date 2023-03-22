/* Copyright 2020 CSCE240 Exam 3
 */
#ifndef TEST_INC_EMPLOYEE_H_
#define TEST_INC_EMPLOYEE_H_


#include <inc/employee.h>

#include <cmath>
// using fabs
#include <cstddef>
// using atoi
#include <iostream>
#include <string>


bool TestDemographicFirstName();  // 1 point
bool TestDemographicLastName();  // 1 point
bool TestDemographicDateOfBirth();  // 1 point

bool TestEmployeeEmployeeId();  // 1 point

bool TestHourlyEmployeePayRate(double hourly_rate);  // 1.5 points
bool TestHourlyEmployeeCalculatePay(double hourly_rate,
                                    double hours_worked);  // 2 points

bool TestSalaryEmployeePayRate(double salary);  // 1.5 points
bool TestSalaryEmployeeCalculatePay(double salary,
                                    double annual_percentage);  // 2 points

const std::string kFirst_name = "Jackson";
const std::string kLast_name = "Seller";
const std::string kDate_of_birth = "1999 10 14";
const std::string kEmployee_id = "911911";
const double kAbs_diff = 0.0001;

#endif  // TEST_INC_EMPLOYEE_H_
