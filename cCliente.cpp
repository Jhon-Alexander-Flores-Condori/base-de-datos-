#include "cCliente.hpp"
#include <iostream>

cCliente::~cCliente() {
    // La clase base se encarga de la liberación de memoria
}

cCliente::cCliente() : cPersona() {
}

cCliente::cCliente(char* name, char* code, int tam_nom, int tam_cod)
    : cPersona(name, code, tam_nom, tam_cod) {
}

cCliente::cCliente(const cCliente& obj) : cPersona(obj) {
}

cCliente& cCliente::operator=(const cCliente& obj) {
    if (this != &obj) {
        cPersona::operator=(obj);
    }
    return *this;
}

void cCliente::print() {
    std::cout << "=== Cliente ===" << std::endl;
    std::cout << "Nombre: " << (getNombre() ? getNombre() : "Sin nombre") << std::endl;
    std::cout << "Código: " << (getCodigo() ? getCodigo() : "Sin código") << std::endl;
    std::cout << "Último acceso: " << (getFecha() ? getFecha() : "Sin fecha") << std::endl;
}