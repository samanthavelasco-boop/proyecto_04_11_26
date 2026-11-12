#include "Bus.h"
#include "Excepciones.h"
#include "Variante.h"

Bus::Bus(string placa, int puestos):Vehiculo(placa), puestos(1){
    setPuestos(puestos);
}

Bus::~Bus(){
    cout << "Destruyendo Bus " << placa << endl;
}

void Bus::setPuestos(int puestos){
    if(puestos < 1){
        throw DatosInvalidosException("El bus necesita al menos 1 puesto");
    }
    this->puestos = puestos;
}

int Bus::getPuestos()const{
    return puestos;
}

string Bus::getTipo() const{
    return "Bus";
}

string Bus::info() const{
    return Vehiculo::info() + " | Puestos: " + to_string(puestos);
}

int Bus::cobrar()const{
    return TARIFA_BUS;
}
