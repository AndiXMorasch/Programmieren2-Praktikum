//
// Created by Admin on 10.01.2022.
//

#ifndef AUFGABE_3_1_BALL_H
#define AUFGABE_3_1_BALL_H

#include "Punkt3D.h"
#include "GeoObjekt.h"
#include <cmath>
#include "OperandenPassenNicht.h"

class Ball : public GeoObjekt {
private:
    double radius;
    Punkt3D zentrum;
public:
    Ball (const Punkt3D&, double r);
    void setzeZentrum(Punkt3D const& p);
    void setzeRadius(double r);
    Ball& operator=(const Ball& rhs);
    Ball* clone() override;
    Ball& assign (const GeoObjekt& rhs) override;
    string toString() override;
    double inhalt() override;
    ~Ball() override = default;
};


#endif //AUFGABE_3_1_BALL_H
