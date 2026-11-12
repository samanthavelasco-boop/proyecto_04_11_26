#include "Propietario.h"

Propietario::Propietario(string nombre, string documento, bool vecino):Persona(nombre, documento), vecino(vecino){}

bool Propietario::esVecino()const{
    return vecino;
}

void Propietario::setVecino(bool vecino){
    this->vecino = vecino;
}

string Propietario::descripcion()const{
    string respuesta = "no";
    if(vecino){
        respuesta = "si";
    }
    return "Propietario " + nombre + "(doc " + documento + ") | Vecino: " + respuesta;
}