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

    carro->setPropietario(vecino);
    cout << "Caso 2: " <<*carro << " | Pagar: " << carro->cobrar() <<endl;

     Moto* moto = new Moto("222EIL", 175);
    flota.push_back(moto);
    moto->setPropietario(vecino);
    cout << "Caso 3: " << *moto << " | Paga: " << moto->cobrar() << endl;

    
    Moto* motoAlta = new Moto("666NIC", 600);
    otros.push_back(motoAlta);
    string alto = "no";
    if(motoAlta->esAltoCilindraje()){
        alto = "si";
    }
    cout << "Caso 4: " << *motoAlta << " | Paga: " << motoAlta->cobrar()
         << " | Alto cilindraje: " << alto << endl;


    Bus* bus = new Bus("999CAR", 38);
    flota.push_back(bus);
    bus->setPropietario(vecino);
    cout << "Caso 5: " << *bus << " | Paga: " << bus->cobrar() << endl;

    
    Camion* camion = new Camion("987VIV", 3);
    flota.push_back(camion);
    cout << "Caso 6: " << *camion << " | Paga: " << camion->cobrar() << endl;

    
    camion->agregarEje();
    cout << "Caso 7: " << *camion << " | Paga: " << camion->cobrar() << endl;


    try{
        Carro* invalido = new Carro("", 2);
        delete invalido;
        cout << "Caso 8: no se lanzo ninguna excepcion" << endl;
    }catch(const PlacaInvalidaException& e){
        cout << "Caso 8: PlacaInvalidaException - " << e.what() << endl;
    }

    try{
        Camion* invalido = new Camion("966NAR", 1);
        delete invalido;
        cout << "Caso 9: no se lanzo ninguna excepcion" << endl;
    }catch(const DatosInvalidosException& e){
        cout << "Caso 9: DatosInvalidosException - " << e.what() << endl;
    }


    Caseta* caseta = new Caseta("Norte", operador);
    try{
        for(Vehiculo* v : flota){
            caseta->registrarPaso(v);
        }
        cout << "Caso 10: recaudo total " << caseta->getRecaudo()
             << " | pasos " << caseta->getTotalPasos()
             << " | Carro: " << caseta->getConteo("Carro")
             << " | Moto: " << caseta->getConteo("Moto")
             << " | Bus: " << caseta->getConteo("Bus")
             << " | Camion: " << caseta->getConteo("Camion") << endl;
    }catch(const DatosInvalidosException& e){
        cout << "Caso 10: DatosInvalidosException - " << e.what() << endl;
    }

    try{
        caseta->registrarPaso(nullptr);
    }catch(const DatosInvalidosException& e){
        cout << "Extra: " << e.what() << " (pasos registrados: " << caseta->getTotalPasos() << ")" << endl;
    }

    for(Vehiculo* v : otros){
        delete v;
    }

    cout << "Caso 13: orden de destruccion" << endl;
    delete caseta;
    for(Vehiculo* v : flota){
        delete v;
    }
    for(Persona* p : personas){
        delete p;
    }

    return 0;
}
