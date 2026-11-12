#include "Vehiculo.h"
#include "Propietario.h"
#include "Excepciones.h"
#include "Variante.h"

Vehiculo::Vehiculo(string placa):propietario(nullptr){
    setPlaca(placa);
}

Vehiculo::~Vehiculo(){}

string Vehiculo::getPlaca()const{
    return placa;
}

void Vehiculo::setPlaca(string placa){
    if(placa.empty()){
        throw PlacaInvalidaException("La placa no puede estar vacia ");
    }
    this->placa = placa;
}

Propietario* Vehiculo::getPropietario()const{
    return propietario;
}

void Vehiculo::setPropietario(Propietario* propietario){
    this->propietario = propietario;
}

string Vehiculo::info()const{
    return "Placa: " + placa;
}


//Descuento para los vecinos
int Vehiculo::aplicarDescuentoVecino(int tarifa) const{
    if(propietario != nullptr && propietario->esVecino()){
        return tarifa * (100 - DESCUENTO_VECINO) / 100;
    }
    return tarifa;
}

ostream &operator <<(ostream &os, const Vehiculo &v){
    os << v.getTipo() << " | " << v.info();
    return os;
}