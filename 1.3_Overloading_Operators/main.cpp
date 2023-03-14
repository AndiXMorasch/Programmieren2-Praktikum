/*
 * -----------------------------------------------------------------------------
 *
 * Beispielprogramm: RinglisteSpielerei.cpp
 *
 * Verwendungsbeispiel der Klasse Ringliste
 *
 * Praktikum Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include "Ringliste.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Anlegen einer Ringliste" << endl;
    Ringliste rListe(5);               // Kapazitaet=5
    cout << rListe.toString() << endl; // toString-Methode

    cout << "Befuellen einer Ringliste" << endl;
    // TODO: Wieso werden hier int's in ein Objekt der Klasse rListe gestreamt?
    rListe << 1 << 2 << 3; // operator<< geeignet ueberladen
    cout << rListe.toString() << endl;
    // TODO: Wie bekomme ich hier hin, dass die int's in einen Vector und nicht in ein Objekt (von Ringliste) gestreamt werden?
    rListe << 4 << 5 << 6;
    cout << rListe.toString() << endl;

    cout << "Vergleich zweier Ringlisten" << endl;
    Ringliste vergleich(5);
    vergleich << 2 << 3 << 4 << 5 << 6;
    // erwartet: true, da beide Ringlisten dieselbe
    // Abfolge von Elementen enthalten
    cout << boolalpha << (rListe==vergleich) << endl;

    // Auslesen von Werten ab aktueller Leseposition
    cout << "Auslesen von Werten" << endl;
    int aktWert;
    cout << rListe.toString() << endl
         << (rListe >> aktWert).toString() << endl
         << (rListe >> aktWert).toString() << endl;

    cout << "Demonstration von operator+=" << endl;
    Ringliste drei; // Kapazitaet=10 (Default)
    drei << 3 << 3 << 3;
    drei+=6;        // operator+= geeignet ueberladen
    cout << drei.toString() << endl;

    cout << "Verketten zweier Ringlisten" << endl;
    rListe << drei; // operator<< geeignet ueberladen
    cout << rListe.toString() << endl;
    cout << drei.toString() << endl;

    return 0;
}



