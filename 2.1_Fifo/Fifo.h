//
// Created by andre on 06.12.2021.
//

#ifndef AUFGABE_2_1_FIFO_H
#define AUFGABE_2_1_FIFO_H
#include "FifoElement.h"

using namespace std;

class Fifo {
private:
    FifoElement *top = nullptr;
public:
    Fifo();
    ~Fifo();
    Fifo& operator<<(const string&);
    Fifo& operator>>(string&);
    explicit operator int () const;
    string pop(string s);
    void push(const string& k);
    int size();
    void info();
    int operator>(int i);
};


#endif //AUFGABE_2_1_FIFO_H
