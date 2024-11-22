// cProveedor.hpp
#ifndef CPROVEEDOR_HPP
#define CPROVEEDOR_HPP

#include "cPersona.hpp"

class cProveedor : public cPersona {
public:
    ~cProveedor();
    cProveedor();
    cProveedor(char* name, char* code, int tam_nom, int tam_cod);
    cProveedor(const cProveedor& obj);
    cProveedor& operator=(const cProveedor& obj);
    void print() override;
};

#endif // CPROVEEDOR_HPP

// cProveedor.cpp
#include "cProveedor.hpp"
#include <iostream>

cProveedor::~cProveedor() {
    // La clase base se encargará de liberar la memoria
}

cProveedor::cProveedor() : cPersona() {
    // Constructor por defecto de la clase base
}

cProveedor::cProveedor(char* name, char* code, int tam_nom, int tam_cod) 
    : cPersona(name, code, tam_nom, tam_cod) {
}

cProveedor::cProveedor(const cProveedor& obj) : cPersona(obj) {
}

cProveedor& cProveedor::operator=(const cProveedor& obj) {
    if (this != &obj) {
        cPersona::operator=(obj);
    }
    return *this;
}

void cProveedor::print() {
    std::cout << "=== Proveedor ===" << std::endl;
    std::cout << "Nombre: " << (getNombre() ? getNombre() : "Sin nombre") << std::endl;
    std::cout << "Código: " << (getCodigo() ? getCodigo() : "Sin código") << std::endl;
    std::cout << "Último acceso: " << (getFecha() ? getFecha() : "Sin fecha") << std::endl;
}