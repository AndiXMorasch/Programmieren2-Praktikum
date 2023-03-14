//
// Created by Admin on 10.01.2022.
//

#include <sstream>
#include "Quader.h"

Quader::Quader(const Punkt3D& luv, const Punkt3D& roh) {
    this->luv = luv;
    this->roh = roh;
}

void Quader::setzePunktLuv(const Punkt3D &p) {
    this->luv = p;
}

void Quader::setzePunktRoh(const Punkt3D &p) {
    this->roh = p;
}

string Quader::toString() {
    stringstream ss;
    ss << "[" << luv.toString() << ", " << roh.toString() << "] ";
    return ss.str();
}

double Quader::inhalt() {
    double inhalt = (abs(luv.x)+abs(roh.x)) * (abs(luv.y)+abs(roh.y)) * (abs(luv.z)+abs(roh.z));
    return inhalt;
}

Quader *Quader::clone() {
    return new Quader(*this);   // Tiefe Kopie
    // return this;             // Flache Kopie
}

Quader &Quader::operator=(const Quader &rhs) {
    return assign(rhs);
}

Quader &Quader::assign(const GeoObjekt &rhs) {

    if(typeid(*this) != typeid(rhs)) {
        throw OperandenPassenNicht();
    }

    const auto* m2D = dynamic_cast<const Quader*>(&rhs);
    if(!m2D || this == &rhs) {
        return *this;
    }
    GeoObjekt::assign(rhs);

    this->setzePunktLuv(m2D->luv);
    this->setzePunktRoh(m2D->roh);
    // alternativ würde auch gehen:
    // luv = m2D-luv;
    // roh = m2D->roh;

    return *this;
}


