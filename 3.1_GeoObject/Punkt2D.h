//
// Created by Admin on 10.01.2022.
//

#ifndef AUFGABE_3_1_PUNKT2D_H
#define AUFGABE_3_1_PUNKT2D_H
#include "Punkt.cpp"

class Punkt2D : public Punkt {
private:
    double x;
    double y;
public:
    Punkt2D() = default;
    Punkt2D(double, double);
    string toString() override;
    ~Punkt2D() override = default;
};


#endif //AUFGABE_3_1_PUNKT2D_H
