#include "RegistroPaso.h"

RegistroPaso::RegistroPaso(string placa, string categoria, int valor):placa(placa), categoria(categoria), valor(valor){}

RegistroPaso::~RegistroPaso(){
    cout << "Destruyendo RegistroPaso " << placa << endl;
}

string RegistroPaso::getPlaca()const{
    return placa;
}

string RegistroPaso::getCategoria()const{
    return categoria;
}

int RegistroPaso::getValor()const{
    return valor;
}