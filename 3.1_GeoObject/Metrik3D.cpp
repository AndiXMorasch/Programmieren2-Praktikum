//
// Created by Admin on 10.01.2022.
//

#include "Metrik3D.h"

Metrik3D *Metrik3D::clone() {
    return new Metrik3D(*this);     // Tiefe Kopie
    // return this;                 // Flache Kopie
}

Metrik3D &Metrik3D::operator=(const Metrik3D &rhs) {
    return assign(rhs);
}

Metrik3D &Metrik3D::assign(const MetrikVerhalten &rhs) {
    const auto* m3D = dynamic_cast<const Metrik3D*>(&rhs);
    if(!m3D || this == &rhs) {
        return *this;
    }
    MetrikVerhalten::assign(rhs);
    return *this;
}

double Metrik3D::abstand(const Punkt &p1, const Punkt &p2) {
    // Methode wird (in der main) nie verwendet...
    return 0;
}

