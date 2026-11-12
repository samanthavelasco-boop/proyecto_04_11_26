#include "Operador.h"
#include "Excepciones.h"

Operador::Operador(string nombre, string documento, string codigoEmpleado): Persona(nombre, documento){
if (codigoEmpleado.empty()){
    throw DatosInvalidosException("El sistema necesita un codigo de empleado");
    }
    this->codigoEmpleado = codigoEmpleado;
}

string Operador::getCodigoEmpleado()const{
    return codigoEmpleado;
}

string Operador::descripcion()const{
    return "Operador " + nombre + " (doc " + documento + ") | Codigo de empleado: " + codigoEmpleado;
}