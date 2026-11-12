#include "Camion.h"
#include "Excepciones.h"
#include "Variante.h"

Camion::Camion(string placa, int ejes):Vehiculo(placa), ejes(2){
    setEjes(ejes);
}

Camion::~Camion(){
    cout << "Destruyendo Camion " << placa << endl;
}

void Camion::setEjes(int ejes){
    if(ejes < 2){
        throw DatosInvalidosException("El camion necesita al menos 2 ejes");
    }
    this->ejes = ejes;
}

int Camion::getEjes()const{
    return ejes;
}

void Camion::agregarEje(){
    ejes++;
}

string Camion::getTipo() const{
    return "Camion";
}

string Camion::info() const{
    return Vehiculo::info() + " | Ejes: " + to_string(ejes);
}

int Camion::cobrar()const{
    return ejes * TARIFA_EJE_CAMION;
}
