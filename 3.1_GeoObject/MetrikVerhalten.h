//
// Created by Admin on 10.01.2022.
//

#ifndef AUFGABE_3_1_METRIKVERHALTEN_H
#define AUFGABE_3_1_METRIKVERHALTEN_H
#include "Punkt.h"

class MetrikVerhalten {
public:
    MetrikVerhalten& operator=(const MetrikVerhalten& rhs);
    virtual MetrikVerhalten* clone() = 0;
    virtual double abstand(Punkt const&, Punkt const&) = 0;
    virtual ~MetrikVerhalten() = default;
    virtual MetrikVerhalten& assign(const MetrikVerhalten& rhs);
};

#endif //AUFGABE_3_1_METRIKVERHALTEN_H
