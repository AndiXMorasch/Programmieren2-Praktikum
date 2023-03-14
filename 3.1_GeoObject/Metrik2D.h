//
// Created by Admin on 10.01.2022.
//

#ifndef AUFGABE_3_1_METRIK2D_H
#define AUFGABE_3_1_METRIK2D_H

#include "Punkt.cpp"
#include "MetrikVerhalten.h"

class Metrik2D : public MetrikVerhalten {
public:
    Metrik2D& operator=(const Metrik2D& rhs);
    Metrik2D* clone() override;
    double abstand(Punkt const&, Punkt const&) override;
    ~Metrik2D() override = default;
    Metrik2D& assign (const MetrikVerhalten& rhs) override;
};


#endif //AUFGABE_3_1_METRIK2D_H
