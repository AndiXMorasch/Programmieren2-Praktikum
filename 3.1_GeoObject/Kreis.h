//
// Created by Admin on 10.01.2022.
//

#ifndef AUFGABE_3_1_KREIS_H
#define AUFGABE_3_1_KREIS_H

#include "Punkt2D.h"
#include "GeoObjekt.h"
#include "OperandenPassenNicht.h"

class Kreis : public GeoObjekt {
private:
    double radius;
    Punkt2D zentrum;
public:
    Kreis(const Punkt2D&, double r);
    void setzeZentrum(Punkt2D const& p);
    void setzeRadius(double r);
    Kreis& operator=(const Kreis& rhs);
    Kreis* clone() override;
    Kreis& assign (const GeoObjekt& rhs) override;
    string toString() override;
    double inhalt() override;
    ~Kreis() override = default;
};


#endif //AUFGABE_3_1_KREIS_H
