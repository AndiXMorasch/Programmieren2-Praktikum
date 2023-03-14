//
// Created by Admin on 10.01.2022.
//

#include <sstream>
#include "Rechteck.h"
#include <cmath>

Rechteck::Rechteck(const Punkt2D& lu, const Punkt2D& ro) {
    this->lu = lu;
    this->ro = ro;
}

void Rechteck::setzePunktLu(const Punkt2D &p) {
    this->lu = p;
}

void Rechteck::setzePunktRo(const Punkt2D &p) {
    this->ro = p;
}

string Rechteck::toString() {
    stringstream ss;
    ss << "[" << lu.toString() << ", " << ro.toString() << "] ";
    return ss.str();
}

double Rechteck::inhalt(){
    double flaecheninhalt = (abs(lu.x) + abs(ro.x)) * (abs(lu.y) + abs(ro.y));
    return flaecheninhalt;
}

Rechteck &Rechteck::operator=(const Rechteck &rhs) {
    return assign(rhs);
}

Rechteck &Rechteck::assign(const GeoObjekt &rhs) {

    OperandenPassenNicht op;

    if(typeid(*this) != typeid(rhs)) {
        throw OperandenPassenNicht();
    }

    const auto* m2D = dynamic_cast<const Rechteck*>(&rhs);
    if(!m2D || this == &rhs) {
        return *this;
    }
    GeoObjekt::assign(rhs);

    this->setzePunktRo(m2D->ro);
    this->setzePunktLu(m2D->lu);
    // alternativ würde auch gehen:
    // ro = m2D->ro;
    // lu = m2D->lu;

    return *this;
}

Rechteck *Rechteck::clone() {
    return new Rechteck(*this); // Tiefe Kopie
    // return this;             // Flache Kopie
}
