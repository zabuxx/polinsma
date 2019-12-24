#include <math.h>

#include "shapes.h"


Triangle::Triangle(const string& n, double l1, double l2, double l3):
    Shape(n), length({l1, l2, l3}) { }

bool Triangle::is_valid_triangle() const {
    return length[0] + length[1] > length[2]
        && length[1] + length[2] > length[0]
        && length[0] + length[2] > length[1];
}

double Triangle::area() const {
    double p = (length[0] + length[1] + length[2]) / 2;

    double i = p * (p - length[0]) * (p -length[1]) * (p -length[2]);

    return sqrt(i);
}