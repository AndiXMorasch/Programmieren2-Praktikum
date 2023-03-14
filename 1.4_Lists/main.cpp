#include <iostream>
#include <math.h>
using namespace std;

#include <list>

                                                                // Grundsätzlicher Aufbau von Prädikaten:
class IstTeilerVon_n {                                          // Klasse
    int ganzeZahl;                                              // Klassenvariable(n)
public:                                                         // Öffentliche (public) Methoden
    explicit IstTeilerVon_n(int n) : ganzeZahl(n) {}            // Konstruktor
    bool operator()(int teiler) const {                         // Prädikat mit () Überladung
        cout << boolalpha << !(ganzeZahl % teiler) << endl;     // Prädikatsinhalt mit jeweiligem return-Wert
        return !(ganzeZahl % teiler);
    }
};

class BesitztMehrWorteAls {
    int anzahlWorte;
public:
    explicit BesitztMehrWorteAls(int n) : anzahlWorte(n) {}

    bool operator()(const string &s) const {
        int count = 0, i, whitespaceGefundenAn = 0, alterWhitespace = 0;
        for (i = 0; s[i] != '\0'; i++) {
            if (s[i] == ' ') {
                whitespaceGefundenAn = i;
                if(((whitespaceGefundenAn-1-alterWhitespace) >= 2)) {
                    alterWhitespace = whitespaceGefundenAn;
                    count++;
                }
            }
            if (((s.size()-1)-whitespaceGefundenAn)<2) {
                break;
            }
        }
        if(((s.size()-1)-whitespaceGefundenAn>=2)) {
            count++;
        }
        cout << boolalpha << (count > anzahlWorte) << endl;
        return (count > anzahlWorte);
    };
};

class IstNahe {
    double tolerance = 0.0001;
public:
    explicit IstNahe() = default;
    explicit IstNahe(double tol) : tolerance(tol) {} // Zweiter Konstruktor für die mögliche Veränderung von "tolerance" laut Arbeitsblatt
    bool operator()(double a, double b) const {
        // fabs auf der math.h zum Ausrechnen des Betrages
        return ((fabs(a - b) <= tolerance && fabs(a - b) >= 0) || (fabs(b - a) <= tolerance && fabs(b - a) >= 0));
    }
};

class IstKuerzerAls {
public:
    explicit IstKuerzerAls() = default;

    bool operator()(const string &a, const string &b) const {
        int zeichenImErstenWort = 0;
        int zeichenImZweitenWort = 0;

        for (int i = 0; a[i] != '\0'; i++) {
            zeichenImErstenWort++;
        }
        for (int i = 0; b[i] != '\0'; i++) {
            zeichenImZweitenWort++;
        }
        cout << boolalpha << (zeichenImErstenWort < zeichenImZweitenWort) << endl;
        return (zeichenImErstenWort < zeichenImZweitenWort);
    }
};

class GemeinsameWerte {
    IstNahe nahe{};
public:
    explicit GemeinsameWerte() = default;

    list<double> operator()(list<double> &a, list<double> &b) const {
        list<double> listeGemeinsamerWerte;
        _List_iterator<double> it1 = a.begin();
        _List_iterator<double> it2 = b.begin();
        _List_iterator<double> it3 = listeGemeinsamerWerte.begin();
        if (a.empty() || b.empty()) {
            cout << "Achtung: Einer Ihrer Listen oder beide Listen sind leer!";
        } else {
            cout << "Die gemeinsamen Elemente aus Liste A und B sind: ";
        }

        for (int i = 0; i < a.size(); i++) {

            for (int y = 0; y < b.size(); y++) {
                if (nahe(*it1, *it2)) {

                    int doppelterWert = 0;
                    for (int k = 0; k < listeGemeinsamerWerte.size(); k++) {
                        if (nahe(*it1, *it3)) {
                            doppelterWert++;
                        }
                        it3++;
                    }
                    it3 = listeGemeinsamerWerte.begin();
                    if (doppelterWert == 0) {
                        listeGemeinsamerWerte.push_back(*it1);
                        cout << *it1 << " ";
                    }
                }
                it2++;
            }
            it2 = b.begin();
            it1++;
        }

        cout << endl;
        return listeGemeinsamerWerte;
    }
};

class AuffuellenUngleicherWerte {
    IstNahe nahe{};
public:
    AuffuellenUngleicherWerte() = default;

    list<double> operator()(list<double> &a, list<double> &b) const {
        _List_iterator<double> it1 = a.begin();
        _List_iterator<double> it2 = b.begin();
        if (b.empty()) {
            cout << "Achtung: Die Liste B ist leer und hat somit keinen Effekt auf A!";
        } else {
            cout << "Die Liste A wurde mit folgenden (unterschiedlichen) Elementen von B aufgefuellt: ";
        }

        for (int i = 0; i < b.size(); i++) {

            int gleicherWert = 0;
            for (int y = 0; y < a.size(); y++) {
                if (nahe(*it2, *it1)) {
                    gleicherWert++;
                }
                it1++;
            }
            it1 = a.begin();
            if (gleicherWert == 0) {
                a.push_back(*it2);
                cout << *it2 << " ";
            }
            it2++;
        }
        cout << endl;
        return a;
    }
};

int main() {
    IstTeilerVon_n istTeilerVon_n(10);
    istTeilerVon_n(5);

    BesitztMehrWorteAls besitztMehrWorteAls(2);
    besitztMehrWorteAls("eins zwei drei vier");

    IstNahe istNahe{};
    cout << boolalpha << istNahe(5.3433, 5.3434) << endl;

    IstKuerzerAls istKuerzerAls{};
    istKuerzerAls("Flugzeug", "Schiff");

    GemeinsameWerte gemeinsameWerte{};
    list<double> a = {2.3230, 5.1111, 7.8998, 1.9191, 4.1299};
    list<double> b = {2.3229, 7.1611, 9.8598, 4.9291, 4.1298};  // Expected output: 2.3230 // 2.3229  und 4.1299 // 4.1298
    list<double> a1 = {};
    list<double> b1 = {};                                       // Expected output: Hinweis darauf, dass die Liste leer ist.
    gemeinsameWerte(a, b);
    gemeinsameWerte(a1, b1);

    AuffuellenUngleicherWerte auffuellenUngleicherWerte{};
    list<double> c = {2.3299, 5.1111, 7.8998, 1.9191, 4.1299};
    list<double> d = {2.3299, 7.1611, 7.8998, 4.9291, 4.1298};  // Expected output: 7.1611 und 4.9291
    list<double> c1 = {};
    list<double> d1 = {};                                       // Expected output: Hinweis darauf, dass die Liste B leer ist.
    auffuellenUngleicherWerte(c, d);
    auffuellenUngleicherWerte(c1, d1);

    return 0;
}