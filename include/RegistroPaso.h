#pragma once
#include <string>
#include <iostream>

using namespace std;
class RegistroPaso{

private:
string placa;
string categoria;
int valor;

public:
RegistroPaso(string placa, string categoria, int valor);
~RegistroPaso();
string getPlaca() const;
string getCategoria() const;
int getValor() const;
};