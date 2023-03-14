//
// Created by Admin on 10.01.2022.
//
#include "Punkt3D.h"
using namespace std;
#include <iostream>
#include <sstream>

string Punkt3D::toString() {
    stringstream ss;
    ss << "(" << this->x << ", " << this->y << ", " << this->z << ")";
    return ss.str();
}

Punkt3D::Punkt3D(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}
