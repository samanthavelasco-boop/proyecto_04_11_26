#include <iostream>
#include <vector>
#include "Excepciones.h"
#include "Persona.h"
#include "Propietario.h"
#include "Operador.h"
#include "Vehiculo.h"
#include "Carro.h"
#include "Moto.h"
#include "Bus.h"
#include "Camion.h"
#include "Caseta.h"

using namespace std;

int main(){
    vector<Persona*> personas;
    vector<Vehiculo*> flota;
    vector<Vehiculo*> otros;

    Propietario* noVecino = new Propietario("Caslos Velasco", "19837376", false);
    Propietario* vecino = new Propietario("Viviana Narvaez", "10097322", true);
    Operador* operador = new Operador("Antonella Velasco", "28739363", "SN2007");
    personas.push_back(noVecino);
    personas.push_back(vecino);
    personas.push_back(operador);

    cout << "Personas del sistema:" << endl;
    for(Persona* p : personas){
        cout << "  " << p->descripcion() << endl;
    }
    cout << endl;

    Carro* carro = new Carro("123SAM", 4);
    flota.push_back(carro);
    carro->setPropietario(noVecino);
    cout << "Caso 1: " << *carro << " | Paga: " << carro->cobrar() << endl;
    
}
