//
// Created by Admin on 10.01.2022.
//

#ifndef AUFGABE_3_1_METRIK3D_H
#define AUFGABE_3_1_METRIK3D_H

#include "Punkt.cpp"
#include "MetrikVerhalten.h"
#include <cmath>

class Metrik3D : public MetrikVerhalten {
public:
    Metrik3D& operator=(const Metrik3D& rhs);
    Metrik3D* clone() override;
    double abstand(Punkt const& p1, Punkt const& p2) override;
    ~Metrik3D() override = default;
    Metrik3D& assign (const MetrikVerhalten& rhs) override;
};


#endif //AUFGABE_3_1_METRIK3D_H
