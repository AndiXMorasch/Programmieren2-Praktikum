//
// Created by Admin on 17.11.2021.
//

#include "vector"
#include "string"
using namespace std;

#ifndef AUFGABE_1_3_RINGLISTE_H
#define AUFGABE_1_3_RINGLISTE_H


// Klasse Ringliste mit Klassenvariablen: vector / int Kapazitaet / int lesePosition / int scheibePosition
class Ringliste {
    vector<int> vec;
    int kapazitaet = 10;
    int lesePosition = 0;
    int schreibePosition = 0;
    int fill = 0;

public:
    Ringliste(); // Verweis auf Standartkonstruktor
    explicit Ringliste(int kapazitaet); // Verweis auf Konstruktor mit benutzerdefinierter Kapazitaet
    Ringliste& operator = (const Ringliste&); // Verweis auf Zuweisungsoperator (lesend?)
    ~Ringliste() = default; // Verweis Standartdestruktor
    string toString(); // Verweis auf die toString Methode

    Ringliste& operator<<(int); // Verweis auf die Operatorüberladung für <<
    bool operator==(const Ringliste&); // Verweis auf die Operatorüberladung für == (lesend?)
    Ringliste& operator>>(int&); // Verweis auf die Operatorüberladung für >>
    Ringliste& operator+=(int); // Verweis auf die Operatorüberladung für +=
    Ringliste& operator<<(Ringliste&); // Verweis auf die Operatorüberladung für << (lesend?)
};


#endif //AUFGABE_1_3_RINGLISTE_H
