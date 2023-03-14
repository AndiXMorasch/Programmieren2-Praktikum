//
// Created by Admin on 10.01.2022.
//

#include "GeoObjekt.h"

GeoObjekt &GeoObjekt::operator=(const GeoObjekt &rhs) {
    if (this == &rhs) {
        return *this;
    }
    return assign(rhs);
}

GeoObjekt &GeoObjekt::assign(const GeoObjekt &rhs) {
    const auto* mV = dynamic_cast<const GeoObjekt*>(&rhs);
    if(!mV) {
        return *this;
    }
    return *this;
}
