/*
 * main.cpp
 *
 *  Created on: 09.10.2021
 *  Author: Andreas Morasch
 */

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdexcept>
using namespace std;

void abschneiden (float &x, int n);
void enthaeltGenauEinmal17(int zahl);

int main () {

	cout << "Bitte geben Sie Ihre Fließkommazahl ein: " << endl;
	float x;
	cin >> x;

	cout << "Bitte geben Sie die Anzahl der Nachkommastellen ein: " << endl;
	int n;
	cin >> n;

	if((x >= 0 && x <= 1000) && (n >= 1 && n <= 5)) {
		abschneiden(x,n);
		cout << x << endl;
	} else {
		cout << "Eine Ihrer Zahlen ist ungültig: Bitte prüfen Sie ob die Fließkommazahl "
		"zwischen 0 und 1000 liegt, sowie die Anzahl der Nachkommastellen zwischen"
		" 1 und 5 liegen muss." << endl;
	}

	cout << "Bitte geben Sie Ihre Zahl ein: " << endl;
	int zahl;
	cin >> zahl;
	enthaeltGenauEinmal17(zahl);

return 0;
}

void abschneiden (float &x, int n) {
	stringstream ss;
	ss << fixed << setprecision(n) << x;
	ss >> x;
}

void enthaeltGenauEinmal17(int zahl) {

	string s = to_string(zahl);
	size_t found = s.find('7');

	int zaehler = 0;
	int stelleAnDer7GefundenWurde[10];

	while(found != std::string::npos) {
		   cout << "7 gefunden an der Stelle: " << (int)found+1 << '\n';
		   stelleAnDer7GefundenWurde[zaehler] = (int)found+1;
		   found=s.find('7', found+1);
		   zaehler++;
	  }
	if (zaehler == 1) {
		zahl = s.size() - stelleAnDer7GefundenWurde[0] + 1;
		cout << "Die Dezimalstelle der 7 lautet: " << zahl << endl;
	} else if (zaehler == 0) {
		throw invalid_argument("Ihre Zahl enthalt keine Siebenen!");
	} else if (zaehler > 1) {
		cout << "Ihre Zahl enthalt mehr als eine 7. Siebenen wurden"
				" an folgenden Stellen ermittelt: " << endl;
		int i = 0;
		while(i < zaehler) {
		cout << i+1 << ". "<< s.size() - stelleAnDer7GefundenWurde[i] + 1 << endl;
		i++; }
		cout << "Bitte wählen Sie aus welche Stelle Sie als 'zahl' definieren möchten und bestätigen Sie mit Enter: " << endl;
		int userAuswahl;
		cin >> userAuswahl;
		cout << "Sie haben die " << userAuswahl << " ausgewählt. Ihre Auswahl wird nun übernommen." << endl;
		zahl = s.size() - stelleAnDer7GefundenWurde[userAuswahl-1] + 1;
	}
}





