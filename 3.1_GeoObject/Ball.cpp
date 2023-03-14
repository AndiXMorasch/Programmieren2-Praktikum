//
// Created by Admin on 10.01.2022.
//

#include <sstream>
#include "Ball.h"

Ball::Ball(const Punkt3D &p1, double r) {
    this->radius = r;
    this->zentrum = p1;
}

void Ball::setzeZentrum(const Punkt3D &p) {
    this->zentrum = p;
}

void Ball::setzeRadius(double r) {
    this->radius = r;
}

string Ball::toString() {
    stringstream ss;
    ss << "[" << zentrum.toString() << ", " << radius << "] ";
    return ss.str();
}

double Ball::inhalt() {
    double inhalt = (4.00/3.00)*M_PI*(radius*radius*radius);  // Formel: (4/3)· π · r³
    return inhalt;
}

Ball *Ball::clone() {
    return new Ball(*this); // Tiefe Kopie
    // return this;         // Flache Kopie
}

Ball &Ball::operator=(const Ball &rhs) {
    return assign(rhs);
}

Ball &Ball::assign(const GeoObjekt &rhs) {

    if(typeid(*this) != typeid(rhs)) {
        throw OperandenPassenNicht();
    }

    const auto* m2D = dynamic_cast<const Ball*>(&rhs);
    if(!m2D || this == &rhs) {
        return *this;
    }
    GeoObjekt::assign(rhs);

    this->setzeZentrum(m2D->zentrum);
    this->setzeRadius(m2D->radius);
    // alternativ würde auch gehen:
    // radius = m2D-radius;
    // zentrum = m2D->zentrum;

    return *this;
}
