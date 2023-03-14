//
// Created by Admin on 10.01.2022.
//

#include "Metrik2D.h"

Metrik2D *Metrik2D::clone(){
    return new Metrik2D(*this); // Tiefe Kopie
    // return this;             // Flache Kopie
}

Metrik2D &Metrik2D::operator=(const Metrik2D &rhs) {
    if (this == &rhs) {
        return *this;
    }
    return assign(rhs);
}

Metrik2D &Metrik2D::assign(const MetrikVerhalten &rhs) {
    const auto* m2D = dynamic_cast<const Metrik2D*>(&rhs);
    if(!m2D || this == &rhs) {
        return *this;
    }
    MetrikVerhalten::assign(rhs);
    return *this;
}

double Metrik2D::abstand(const Punkt &, const Punkt &) {
    // Methode wird (in der main) nie verwendet...
    return 0;
}



