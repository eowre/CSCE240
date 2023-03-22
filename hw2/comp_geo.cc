/*Copyright 2020 Evan Owre
 */
#include <comp_geo.h>
#include <cmath>
#include <iostream>
using std::cout;
using std::endl;

double CalcCircumference(
  double x_center, double y_center, double x_boundary, double y_boundary) {
  double radius;
  double y_length = y_center-y_boundary;
  double x_length = x_center-x_boundary;
  radius = sqrt(pow(y_length, 2)+pow(x_length, 2));
  if (radius == 0) {
    cout << "radius equals zero" << endl;
    return 0;
  }
  double circumference = (2*k_pi)*radius;
  return circumference;
}
double CalcCircleArea(
  double x_center, double y_center, double x_boundary, double y_boundary) {
  double radius;
  double y_length = y_center-y_boundary;
  double x_length = x_center-x_boundary;
  radius = sqrt(pow(y_length, 2)+pow(x_length, 2));
  if (radius == 0) {
    cout << "radius equals zero" << endl;
    return 0;
  }
  double area = k_pi*(pow(radius, 2));
  return area;
}
double CalcPerimeter(
  double x_ll, double y_ll, double x_ur, double y_ur) {
  if (x_ll == x_ur || y_ll == y_ur) {
    cout << "distance between points equals zero" << endl;
    return 0;
  }
  double height = y_ur - y_ll;
  double width = x_ur - x_ll;
  double perimeter = (height * 2) + (width * 2);
  return perimeter;
}
double CalcRectangleArea(
  double x_ll, double y_ll, double x_ur, double y_ur) {
  if (x_ll == x_ur || y_ll == y_ur) {
    cout << "distance between points equals zero" << endl;
    return 0;
  }
  double height = y_ur - y_ll;
  double width = x_ur - x_ll;
  double area = height * width;
  return area;
}
double CalcDistanceSquared(
  double x_1, double y_1, double x_2, double y_2) {
  double height = y_2 - y_1;
  double width = x_2 - x_1;
  double distance_sqrd = pow(height, 2) + pow(width, 2);
  return distance_sqrd;
}
double CalcDistance(
  double x_1, double y_1, double x_2, double y_2) {
  double height = y_2 - y_1;
  double width = x_2 - x_1;
  double distance = sqrt(pow(height, 2) + pow(width, 2));
  return distance;
}
bool PointsEqual(
  double x_1, double y_1, double x_2, double y_2) {
  if ((x_1 - x_2) <= .0001 && (y_1 - y_2) <= .0001) {
    return true;
  }
  return false;
}
