//
// Created by Admin on 10.01.2022.
//

#ifndef AUFGABE_3_1_PUNKT3D_H
#define AUFGABE_3_1_PUNKT3D_H
#include "Punkt.cpp"

class Punkt3D : public Punkt {
public:
    double x;
    double y;
    double z;
    Punkt3D() = default;
    Punkt3D(double, double, double);
    string toString() override;
    ~Punkt3D() override = default;
};


#endif //AUFGABE_3_1_PUNKT3D_H
