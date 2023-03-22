/* Copyright 2020 Evan Owre
 */
#ifndef COMP_GEO_H_
#define COMP_GEO_H_
const double k_pi = 3.141592653589793;  // used for circle calculations


/* CalcCircumference
 * Function: Calculates and returns the circumference of a circle described by a
 *   point at the circle's center and a point on the circle's boundary.
 *
 * Precondition(s): The distance between center point and boundary point is
 *   greater than 0.
 *   Both points are finite and defined.
 */
double CalcCircumference(
    double x_center, double y_center, double x_boundary, double y_boundary);


/* CalcCircleArea
 * Function: Calculates and returns the area of a circle described by a
 * point at the circle's center and a point on the circle's boundary.
 *
 * Precondition(s): The distance between center point and boundary point is
 *   greater than 0.
 *   Both points are finite and defined.
 */
double CalcCircleArea(
    double x_center, double y_center, double x_boundary, double y_boundary);


/* CalcPerimeter
 * Function: Calculates and returns the perimenter of a rectangle described by a
 *   point at the lower left vertex of the rectangle and a point at the upper
 *   right.
 *
 * Precondition(s): The distance between the lower left point and upper right is
 *   greater than 0.
 *   Both points are finite and defined.
 */
double CalcPerimeter(double x_ll, double y_ll, double x_ur, double y_ur);


/* CalcRectangleArea
 * Function: Calculates and returns the area of a rectangle described by a point
 *   at the lower left vertex of the rectangle and a point at the upper
 *   right.
 *
 * Precondition(s): The distance between the lower left point and upper right is
 *   greater than 0.
 *   Both points are finite and defined.
 */
double CalcRectangleArea(double x_ll, double y_ll, double x_ur, double y_ur);


/* CalcDistanceSquared
 * Function: Calculates the squared distance between two points, using the
 *   Euclidean distance equation but without the final square root calculation.
 *
 * Precondition: Both points are finite and defined.
 */
double CalcDistanceSquared(double x_1, double y_1, double x_2, double y_2);


/* CalcDistance
 * Function: Calculates and returns the distance between two points.
 *
 * Precondition: Both points are finite and defined.
 */
double CalcDistance(double x_1, double y_1, double x_2, double y_2);


/* PointsEqual
 * Function: Determine whethers two points are approximately equal.
 *
 * Precondition: Both points are finite and defined.
 */
bool PointsEqual(double x_1, double y_1, double x_2, double y_2);

#endif  // COMP_GEO_H_
