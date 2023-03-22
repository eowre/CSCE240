/* Copyright 2020
 * Points:
 *   Compilation: 1 point
 *   Style: 2 points
 *   Demographic::first_name() : 1 point
 *   Demographic::last_name() : 1 point
 *   Demographic::date_of_birth() : 1 point
 *   Employee::employee_id() : 1 point (requires child class)
 *   HourlyEmpolyee::pay_rate() : 1.5 points
 *   HourlyEmployee::CalculatePay(double) : 2 points
 *   SalaryEmployee::pay_rate() : 1.5 points
 *   SalaryEmployee::CalculatePay(double) : 2 points
 */
#ifndef INC_EMPLOYEE_H_
#define INC_EMPLOYEE_H_

#include <string>

/* The Demographic class provides a base for people in the system. It will be
 * extended by other classes, such as Employee and must be in the exam3
 * namespace.
 *
 * The class provides a constructor, a virtual destructor, and three accessor
 * methods for the class members passed into the constructor.
 */
namespace exam3 {
class Demographic {
 public:
  Demographic(const std::string& first_name,
              const std::string& last_name,
              const std::string& date_of_birth);
  virtual ~Demographic() { /* empty */ }
  // accessors
  const std::string first_name() const;
  const std::string last_name() const;
  const std::string date_of_birth() const;
 private:
  std::string first_name_;
  std::string last_name_;
  std::string date_of_birth_;
};


/* Employee extends Demographic and must be in the exam3 namespace.
 */
class Employee:public Demographic {
 public:
  /* Additional parameter employee_id stored by the Employee class
   */
  Employee(const std::string& first_name,
           const std::string& last_name,
           const std::string& date_of_birth,
           const std::string& employee_id);
  virtual ~Employee();  // not a pure virtual method

  // accessor
  const std::string employee_id() const;

  /* Must be defined by child
   * Returns the payment unit of a child class, i.e. salary or hourly rate
   */
  virtual double pay_rate() const = 0;

  /* Must be defined by child
   * Calculates and returns the payment based on child class behavior.
   */
  virtual double CalculatePay(double) const = 0;
 private:
  std::string employee_id_;
};

/* HourlyEmplyee extends the Employee class and provides the following methods:
 * - Constructor: accepts 4 const pass-by-reference strings, representing
 *     first_name, last_name, date_of_birth, employee_id, and a double
 *     representing the instance's hourly_rate.
 *
 * - pay_rate: access for the hourly_rate parameter above
 * - CalculatePay: accepts number of hours worked and returns the pay for the
 *     hourly rate based on hours worked.
 * It must be in the exam3 namespace.
 */
class HourlyEmployee:public Employee {
 public:
  /* Additional parameter hourly_rate is stored privately in HourlyEmployee
   */
  HourlyEmployee(const std::string& first_name,
                 const std::string& last_name,
                 const std::string& date_of_birth,
                 const std::string& employee_id,
                 double hourly_rate);
  ~HourlyEmployee();

  /* accessor for hourly_rate
   */
  double pay_rate() const;

  /* Calculates payment based on the employee's hourly_rate and the
   * hours_worked.
   */
  double CalculatePay(double hours_worked) const;
 private:
  double hourly_rate_;
};


/* SalaryEmplyee extends the Employee class and provides the following methods:
 * - Constructor: accepts 4 const pass-by-reference strings, representing
 *     first_name, last_name, date_of_birth, employee_id, and a double
 *     representing the instance's salary.
 *
 * - pay_rate: accessor for the salary parameter above
 * - CalculatePay: accepts a double representing the percentage of the year for
 *   which the salaried employee is paid, e.g. a week is 1/52 of a year ~1.923%.
 * It must be in the exam3 namespace.
 */
class SalaryEmployee:public Employee {
 public:
  /* Additional parameter salary is stored privately in SalaryEmployee
   */
  SalaryEmployee(const std::string& first_name,
                 const std::string& last_name,
                 const std::string& date_of_birth,
                 const std::string& employee_id,
                 double salary);

  /* accessor for salary
   */
  double pay_rate() const;

  /* Calculates payment based on the worker's salary and the percentage of the
   * year for which payment is made e.g. a week payment is ~1.923% (1/52).
   */
  double CalculatePay(double annual_percentage) const;
 private:
  double salary_;
};
}  // namespace exam3
#endif  // INC_EMPLOYEE_H_
