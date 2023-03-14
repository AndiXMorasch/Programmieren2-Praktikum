//
// Created by andre on 08.11.2021.
//

#include "vector"
#include <iostream>
#include <sstream>
#include "string"
using namespace std;
#include "Ringliste.h"

// Implementation des default Konstruktors mit default Wert 10
 Ringliste::Ringliste() {
     this->vec = vector<int>(10);
}

// Implementation des benutzerdefinierten Konstruktors
Ringliste::Ringliste(int kapazitaet) {
    this->kapazitaet = kapazitaet;
    this->vec = vector<int>(kapazitaet);
}

// Implementation des Zuweisungsoperators
Ringliste& Ringliste::operator=(const Ringliste& rhs) { // const sichert zu, dass der Übergabeparameter konstant (nicht änderbar) ist (lesend?)
    this->kapazitaet = rhs.kapazitaet;
    this->vec = rhs.vec;
    return *this;
}

// Implementation von toString()
string Ringliste::toString() {
    cout << "Belegung: " << fill << "/" << kapazitaet << " | ";
    stringstream ss;
    for(int i = 0; i < vec.size(); i++) {
        ss << vec[i] << " ";
    }
    ss << " | " << "lesePos=" << lesePosition << " schreibPos=" << schreibePosition;
    return ss.str();
}

// Implementation der Operatorüberladung für <<
Ringliste& Ringliste::operator<<(int element) {
    vec[schreibePosition] = element;
    schreibePosition++;

    if(schreibePosition == kapazitaet) {
        schreibePosition = 0;
    }
    if (fill < kapazitaet) {
        fill++;
    } else {
        lesePosition = schreibePosition;
    }
    return *this;
}

// Implementation der Operatorüberladung für ==
bool Ringliste::operator==(const Ringliste& ring) {

    bool erg = true;
    int leseZwischenspeicher = lesePosition;
    int ringLeseZwischenspeicher = ring.lesePosition;

    if(fill != ring.fill) {
        return false;
    }

    for(int i = 0; i < fill; i++) {

        if(leseZwischenspeicher == kapazitaet) {
            leseZwischenspeicher = 0;
        }
        if(ringLeseZwischenspeicher == ring.kapazitaet) {
            ringLeseZwischenspeicher = 0;
        }
        if(vec[leseZwischenspeicher] != ring.vec[ringLeseZwischenspeicher]) {
            erg = false;
            break;
        }
        leseZwischenspeicher++;
        ringLeseZwischenspeicher++;
    }
    return erg;
}

// Implementation der Operatorüberladung für >> (löscht ein Element bzw. setzt es auf 0)
Ringliste& Ringliste::operator>>(int& aktWert) {
    if(fill > 0) {
        vec[lesePosition] = 0;
        lesePosition++;
        fill--;
    }
    return *this;
}

// Implementation der Operatorüberladung für +=
Ringliste& Ringliste::operator+=(int element) {
    for(int i = 0; i < fill; i++) {
        vec[schreibePosition] += element;
        //Alter Code: vec[(lesePosition+i)%fill] += element;
    }
    return *this;
}

// Implementation der Operatorüberladung für <<
Ringliste& Ringliste::operator<<(Ringliste& ring) {
    for(int i = 0; i < ring.fill; i++) {
        vec[schreibePosition] = ring.vec[ring.lesePosition];
        ring.lesePosition++;
        schreibePosition++;
        if (fill < kapazitaet) {
            fill++;
        }
        if(schreibePosition == kapazitaet) {
            schreibePosition = 0;
        }
        if(ring.lesePosition == kapazitaet) {
            ring.lesePosition = 0;
        }
    }
    return *this;
}



