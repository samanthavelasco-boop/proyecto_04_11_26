#pragma once
#include <iostream>
#include <string>
using namespace std;

class Vehiculo {
protected:
    string placa;
public:
    Vehiculo(string placa);
    virtual ~Vehiculo();
    virtual string getTipo() const = 0;

    string getPlaca() const;
    void setPlaca(string placa);
    virtual string info() const;
    virtual int cobrar() const;
};

ostream &operator<<(ostream &os, Vehiculo &vehiculo);