#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <Operador.h>
#include <RegistroPaso.h>
#include <Vehiculo.h>

using namespace std;

class Caseta {

    private:
    string nombre;
    Operador* operador;
    vector<RegistroPaso*> registros;
    map<string, int> conteo;
    int recaudo;

    public:
    Caseta(string nombre, Operador* operador);
    ~Caseta();
    string getNombre() const;
    Operador* getOperador()const;
    void registrarPaso(Vehiculo* vehiculo);
    int getTotalPasos() const;
    int getRecaudo()const;
    int getConteo(string categoria);
};