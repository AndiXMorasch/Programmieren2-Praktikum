//
// Created by andre on 06.12.2021.
//
#include <iostream>
#include "string"
#include "Fifo.h"
#include "FifoElement.h"
using namespace std;

Fifo::Fifo() = default;

Fifo::~Fifo() = default;

Fifo &Fifo::operator<<(const string &str) {
    auto *fifoElement = new FifoElement(); // statt auto stand hier vorher fifo-Element!
    fifoElement->setValue(str);
    if(top == nullptr) {
        top = fifoElement;
    } else {
        FifoElement *tmp;
        tmp = top;
        while (tmp->getNext() != nullptr) {
            tmp = tmp->getNext();
        }
        tmp->setNext(fifoElement);
    }
    return *this;
}

Fifo::operator int() const {
    int zaehler = 0;
    if(top == nullptr) {
        return zaehler;
    } else {
        FifoElement *tmp;
        tmp = top;
        while (tmp->getNext() != nullptr) {
            zaehler++;
            tmp = tmp->getNext();
        }
    }
    return zaehler;
}

string Fifo::pop(string str) {
    string s;
    if (top != nullptr) {
        FifoElement *tmp;
        tmp = top->getNext();
        delete top;
        top = tmp;
        str = top->getValue();
        //delete tmp; nicht sicher ob das delete an dieser Stelle richtig ist
    } else {
        //cout << "Ihr Fifo ist leer. Bitte fügen Sie zunächst Elemente hinzu bevor Sie welche löschen." << endl;
    }

    if(operator int() < 1) {
        top = nullptr;
    }
    return str;
}

Fifo &Fifo::operator>>(string &str) {
    str = pop(str);
    return *this;
}

void Fifo::push(const string& k) {
    operator<<(k);
}

int Fifo::size() {
    return operator int();
}

void Fifo::info() {
    if(top != nullptr) {
        FifoElement *tmp;
        tmp = top;
        while (tmp->getNext() != nullptr) {
            cout << tmp->getValue() << endl;
            tmp = tmp->getNext();
        }
    }
}

int Fifo::operator>(int i) {
    return operator int();
}



