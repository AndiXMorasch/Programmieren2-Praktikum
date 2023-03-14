//
// Created by Admin on 10.01.2022.
//
#include "Punkt2D.h"
using namespace std;
#include <iostream>
#include <sstream>

string Punkt2D::toString() {
    stringstream ss;
    ss << "(" << this->x << ", " << this->y << ")";
    return ss.str();
}

Punkt2D::Punkt2D(double x, double y) {
    this->x = x;
    this->y = y;
}
