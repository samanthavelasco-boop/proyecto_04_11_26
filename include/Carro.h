#pragma once
#include "Vehiculo.h"

class Carro : public Vehiculo {
    private:
    int pasajeros;

    public:
    Carro(strig placa, int pasajeros);
    Carro();
    void setPasajeros(int pasajeros);
    int getPasajeros () conts;
    string info() const override;
    int cobrar() const override;
}