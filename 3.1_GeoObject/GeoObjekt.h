//
// Created by Admin on 10.01.2022.
//

#ifndef AUFGABE_3_1_GEOOBJEKT_H
#define AUFGABE_3_1_GEOOBJEKT_H

#include "MetrikVerhalten.h"

class GeoObjekt {
protected:
    MetrikVerhalten* metrik{};
public:
    GeoObjekt& operator=(const GeoObjekt& rhs);
    virtual double inhalt() = 0;        // Wird nicht (in GeoObjekt) implementiert, sondern nur in den Unterklassen!
    virtual string toString() = 0;      // Wird nicht (in GeoObjekt) implementiert, sondern nur in den Unterklassen!
    virtual GeoObjekt* clone() = 0;     // Wird nicht (in GeoObjekt) implementiert, sondern nur in den Unterklassen!
    virtual GeoObjekt& assign(const GeoObjekt& rhs);
    virtual ~GeoObjekt() = default;
};


#endif //AUFGABE_3_1_GEOOBJEKT_H
