//
// Created by Admin on 10.01.2022.
//

#include <sstream>
#include "Kreis.h"
#include <cmath>

Kreis::Kreis(const Punkt2D &p1, double r) {
    this->radius = r;
    this->zentrum = p1;
}

void Kreis::setzeZentrum(const Punkt2D &p) {
    this->zentrum = p;
}

void Kreis::setzeRadius(double r) {
    this->radius = r;
}

string Kreis::toString() {
    stringstream ss;
    ss << "[" << zentrum.toString() << ", " << radius << "] ";
    return ss.str();
}

double Kreis::inhalt() {
    return radius*radius*M_PI;
}

Kreis *Kreis::clone() {
    return new Kreis(*this);    // Tiefe Kopie
    // return this;             // Flache Kopie
}

Kreis &Kreis::operator=(const Kreis &rhs) {
    return assign(rhs);
}

Kreis &Kreis::assign(const GeoObjekt &rhs) {

    if(typeid(*this) != typeid(rhs)) {
        throw OperandenPassenNicht();
    }

    const auto* m2D = dynamic_cast<const Kreis*>(&rhs);
    if(!m2D || this == &rhs) {
        return *this;
    }
    GeoObjekt::assign(rhs);

    this->setzeRadius(m2D->radius);
    this->setzeZentrum(m2D->zentrum);
    // alternativ würde auch gehen:
    // radius = m2D-radius;
    // zentrum = m2D->zentrum;

    return *this;
}
