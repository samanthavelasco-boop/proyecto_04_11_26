#include "Carro.h"
#include "Excepciones.h"
#include "Variante.h"

Carro::Carro(string placa, int pasajeros):Vehiculo(placa), pasajeros(1){
    setPasajeros(pasajeros);
}

Carro::~Carro(){
    cout << "Destruyendo Carro " << placa << endl;
}

void Carro::setPasajeros(int pasajeros){
    if(pasajeros < 1){
        throw DatosInvalidosException("El carro necesita al menos 1 pasajero");
    }
    this->pasajeros = pasajeros;
}

int Carro::getPasajeros()const{
    return pasajeros;
}

void Carro::subirPasajero(){
    pasajeros++;
}

string Carro::getTipo() const{
    return "Carro";
}

string Carro::info() const{
    return Vehiculo::info() + " | Pasajeros: " + to_string(pasajeros);
}

int Carro::cobrar()const{
    return aplicarDescuentoVecino(TARIFA_CARRO);
}
