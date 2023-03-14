/*
 * main.cpp
 *
 *  Created on: 07.10.2021
 *     	Author: Andreas Morasch
 */

#include <iostream> // Header that defines the standard input/output stream objects
#include <fstream> // Input/output stream class to operate on files
#include <sstream> // Header providing string stream classes
#include <string> // --> Includes string? But for what? I'm also not including integer or double values, so what's the point of this?
#include <iomanip> // Header providing parametric manipulators like dec, hex, oct, endl, boolalpha, uppercase etc.

using namespace std; // Namespaces allow to group entities like classes, objects and functions under a name

int main() {
	// 1. Declare that there is this file called "eingabe.txt" (input stream)
	ifstream leseTxtDatei("eingabe.txt");
	// 2. Check if the file really exists
	if (leseTxtDatei.is_open()) {
		// 3. If it does, read and print it out
		string line; // local variable for each line being read from getline
		double doubleVar; // local variable for each double-value being read from stringstream "strom"
		int intVar; // local variable for each integer-value being read from stringstream "strom"
		string stringVar; // local variable for each string-value being read from stringstream "strom"
		int zaehler = 1; // local variable which increases by +1 every time the loop go through
		// the loop for reading out line by line from the .txt doc
		while (getline(leseTxtDatei, line)) {
			// declaring a new stringstream with the variable line (for each line being read)
			stringstream strom(line);
			// check if strom (from type stringstream) is not in this sequence? Tbh I dont know what this condition is doing...
			if (!(strom >> intVar >> doubleVar >> stringVar)) {
				// throw user information if so
				cout << "Error: Could not convert" << endl;
			} else { // if strom is in the correct sequence, "else" get triggered
				ofstream schreibeTxtDatei; // Declaration of the variable from type ofstream (output stream)
				schreibeTxtDatei.open("ausgabe.txt", ofstream::app); // opens the .txt file with the note "app" for write under each other instead of overwriting
				if(schreibeTxtDatei.is_open()) { // check if the document really exist and is opened
				// Code for manipulation of the individual data intVar, doubleVar, strVar
					schreibeTxtDatei << zaehler++ << "." << " | " << hex
						<< noshowbase << setw(4) << setfill('0') << intVar
						<< " | " << setprecision(6) << doubleVar << " | "
						<< setw(15) << setfill('-') << stringVar << endl;
				schreibeTxtDatei.close(); // Close the stream of the current file
				} else { // if the file does not exist, throw user information
					cout << "Error: Output file does not exist" << endl;
				}
				// **** Code for program to show in console if needed -> please remove the comment characters for this! ****

				/* cout << zaehler++ << "." << " | " << hex
						<< noshowbase << setw(4) << setfill('0') << intVar
						<< " | " << setprecision(6) << doubleVar << " | "
						<< setw(15) << setfill('-') << strVar << endl; */

				// ****Code for program to show in console if needed -> please remove the comment characters for this! ****
			}
		}
	}
	// 4. If the input file does not exist, throw user information
	else {
		cout << "Error: Input file not found" << endl;
	}
	// . return 0 as true
	return 0;
}

