//
// Created by Admin on 10.01.2022.
//

#ifndef AUFGABE_3_1_QUADER_H
#define AUFGABE_3_1_QUADER_H

#include "Punkt3D.h"
#include "GeoObjekt.h"
#include "OperandenPassenNicht.h"

class Quader : public GeoObjekt {
private:
    Punkt3D luv;
    Punkt3D roh;
public:
    Quader(const Punkt3D&, const Punkt3D&);
    void setzePunktLuv(Punkt3D const& p);
    void setzePunktRoh(Punkt3D const& p);
    Quader& operator=(const Quader& rhs);
    Quader* clone() override;
    Quader& assign (const GeoObjekt& rhs) override;
    virtual string toString();
    double inhalt() override;
    ~Quader() override = default;
};


#endif //AUFGABE_3_1_QUADER_H
