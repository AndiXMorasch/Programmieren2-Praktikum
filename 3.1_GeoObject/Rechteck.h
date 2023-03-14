//
// Created by Admin on 10.01.2022.
//

#ifndef AUFGABE_3_1_RECHTECK_H
#define AUFGABE_3_1_RECHTECK_H

#include "Punkt2D.h"
#include "GeoObjekt.h"
#include "OperandenPassenNicht.h"
using std::exception;

class Rechteck : public GeoObjekt {
private:
    Punkt2D lu;
    Punkt2D ro;
public:
    Rechteck(const Punkt2D&, const Punkt2D&);
    void setzePunktLu(Punkt2D const& p);
    void setzePunktRo(Punkt2D const& p);
    Rechteck& operator=(const Rechteck& rhs);
    Rechteck* clone() override;
    Rechteck& assign (const GeoObjekt& rhs) override;
    string toString() override;
    double inhalt() override;
    ~Rechteck() override = default;
};


#endif //AUFGABE_3_1_RECHTECK_H
