//
// Created by andre on 06.12.2021.
//

#ifndef AUFGABE_2_1_FIFOELEMENT_H
#define AUFGABE_2_1_FIFOELEMENT_H
#include <utility>
#include "string"
using namespace std;

class FifoElement {
    FifoElement *next = nullptr;
    string value;
public:
    FifoElement();
    string& getValue() {
        return value;
    }
    void setValue(string s) {
        value = s;
    }
    FifoElement*& getNext() {
        return next;
    };
    void setNext(FifoElement* p) {
        next = p;
    }
};


#endif //AUFGABE_2_1_FIFOELEMENT_H
