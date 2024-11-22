#include "cPersona.hpp"
#include <iostream>

cPersona::~cPersona() {
    liberar(&nombre);
    liberar(&codigo);
    liberar(&cadena_fecha);
}

cPersona::cPersona() {
    asignar_nullptr();
}

cPersona::cPersona(char* name, char* code, int tam_nom, int tam_cod) {
    asignar_nullptr();
    llenado_size_nom(tam_nom, name);
    llenado_size_cod(tam_cod, code);
    llenado_generalFecha();
}

cPersona::cPersona(const cPersona& obj) {
    asignar_nullptr();
    asignarValores(&obj);
}

cPersona& cPersona::operator=(const cPersona& obj) {
    if (this != &obj) {
        liberar(&nombre);
        liberar(&codigo);
        liberar(&cadena_fecha);
        asignarValores(&obj);
    }
    return *this;
}

void cPersona::print() const {
    std::cout << "Nombre: " << getNombre() << std::endl;
    std::cout << "Codigo: " << getCodigo() << std::endl;
    std::cout << "Fecha de acceso: " << getFecha() << std::endl;
}

// Métodos de asignación y liberación de memoria
void cPersona::asignar_nullptr() {
    nombre = nullptr;
    codigo = nullptr;
    cadena_fecha = nullptr;
    size_nom = 0;
    size_cod = 0;
}

// Métodos de llenado y obtención de datos
const char* cPersona::getFecha() const {
    return cadena_fecha;
}

const char* cPersona::getNombre() const {
    return nombre;
}

const char* cPersona::getCodigo() const {
    return codigo;
}

int cPersona::getSize_nom() const {
    return size_nom;
}

int cPersona::getSize_cod() const {
    return size_cod;
}

// Otros métodos...
