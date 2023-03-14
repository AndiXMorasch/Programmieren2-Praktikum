//
// Created by Admin on 10.01.2022.
//

#include "MetrikVerhalten.h"

MetrikVerhalten &MetrikVerhalten::operator=(const MetrikVerhalten &rhs) {
    if (this == &rhs) {
        return *this;
    }
    return assign(rhs);
}

MetrikVerhalten &MetrikVerhalten::assign(const MetrikVerhalten& rhs) {
    const auto* mV = dynamic_cast<const MetrikVerhalten*>(&rhs);
    if(!mV) {
        return *this;
    }
    return *this;
}
