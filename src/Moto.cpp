#include "Moto.h"
#include "Excepciones.h"
#include "Variante.h"

Moto::Moto(string placa, int cilindraje):Vehiculo(placa), cilindraje(1){
    setCilindraje(cilindraje);
}

Moto::~Moto(){
    cout << "Destruyendo Moto " << placa << endl;
}

void Moto::setCilindraje(int cilindraje){
    if(cilindraje <= 0){
        throw DatosInvalidosException("El cilindraje debe ser mayor que cero");
    }
    this->cilindraje = cilindraje;
}

int Moto::getCilindraje()const{
    return cilindraje;
}

bool Moto::esAltoCilindraje()const{
    return cilindraje > 400;
}

string Moto::getTipo() const{
    return "Moto";
}

string Moto::info() const{
    return Vehiculo::info() + " | Cilindraje: " + to_string(cilindraje) + " cc";
}

int Moto::cobrar()const{
    return aplicarDescuentoVecino(TARIFA_MOTO);
}