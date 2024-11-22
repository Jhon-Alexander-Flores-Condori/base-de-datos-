#include "cProveedor.hpp"
#include <iostream>

cProveedor::cProveedor() : cPersona() {
    rubro = nullptr;
    size_rubro = -1;
}

cProveedor::cProveedor(char* name, char* code, char* rub, int tam_nom, int tam_cod, int tam_rub) 
    : cPersona(name, code, tam_nom, tam_cod) {
    rubro = nullptr;
    size_rubro = -1;
    
    if(llenado_rubro(rub, tam_rub)) {
        std::cout << "RUBRO LLENADO CON EXITO" << std::endl;
    } else {
        std::cout << "RUBRO no LLENADO CON EXITO" << std::endl;
    }
}

cProveedor::cProveedor(const cProveedor& obj) : cPersona(obj) {
    rubro = nullptr;
    if(asignarValores(&obj)) {
        std::cout << "SE LOGRO COPIA PROVEEDOR" << std::endl;
    } else {
        std::cout << "NO SE LOGRO COPIA PROVEEDOR" << std::endl;
    }
}

cProveedor& cProveedor::operator=(const cProveedor& obj) {
    if(this != &obj) {
        cPersona::operator=(obj);
        if(asignarValores(&obj)) {
            std::cout << "SE LOGRO ASIGNACION PROVEEDOR" << std::endl;
        } else {
            std::cout << "NO SE LOGRO ASIGNACION PROVEEDOR" << std::endl;
        }
    }
    return *this;
}

void cProveedor::print() {
    cPersona::print();
    if(rubro != nullptr) {
        std::cout << "RUBRO: " << rubro << " tam:" << size_rubro << std::endl;
    } else {
        std::cout << "Rubro no asignado (nullptr)" << std::endl;
    }
}

bool cProveedor::llenado_rubro(char* rub, int size) {
    fecha.actualizarFecha();
    if(rub != nullptr) {
        if(rubro != nullptr) {
            delete[] rubro;
        }
        
        if(size <= 1) {
            size = contador(rub);
            if(size <= 1) {
                std::cout << "CADENA DE LONGITUD 0 INVIABLE" << std::endl;
                return false;
            }
        }
        
        size_rubro = size;
        rubro = new char[size_rubro];
        copiar(rub, rubro, size_rubro);
        return true;
    }
    return false;
}

bool cProveedor::asignarValores(const cProveedor* obj) {
    if(obj->rubro != nullptr) {
        return llenado_rubro(obj->rubro, obj->size_rubro);
    }
    return false;
}

void cProveedor::ultimoAcceso() {
    // Implementación específica para proveedor
    cPersona::ultimoAcceso();
    std::cout << "Rubro del proveedor: " << rubro << std::endl;
}

const char* cProveedor::getRubro() {
    return rubro;
}

cProveedor::~cProveedor() {
    if(rubro != nullptr) {
        delete[] rubro;
        rubro = nullptr;
    }
}