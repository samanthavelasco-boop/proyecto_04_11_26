#include "Caseta.h"
#include "Excepciones.h"

Caseta::Caseta(string nombre, Operador* operador):nombre(nombre), operador(operador), recaudo(0){}

// solo libera los registros, el operador y los vehiculos se liberan en el main
Caseta::~Caseta(){
    cout << "Destruyendo Caseta " << nombre << endl;
    for(RegistroPaso* r : registros){
        delete r;
    }
}

string Caseta::getNombre()const{
    return nombre;
}

Operador* Caseta::getOperador()const{
    return operador;
}

void Caseta::registrarPaso(Vehiculo* vehiculo){
    if(vehiculo == nullptr){
        throw DatosInvalidosException("No se puede registrar el paso de un vehiculo nulo");
    }
    int valor = vehiculo->cobrar();
    string categoria = vehiculo->getTipo();

    registros.push_back(new RegistroPaso(vehiculo->getPlaca(), categoria, valor));
    recaudo += valor;
    conteo[categoria]++;
}

int Caseta::getTotalPasos()const{
    return registros.size();
}

int Caseta::getRecaudo()const{
    return recaudo;
}

int Caseta::getConteo(string categoria){
    return conteo[categoria];
}