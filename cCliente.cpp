#include "cCliente.hpp"
#include <iostream>

cCliente::cCliente() : cPersona() {
    tipo_cliente = nullptr;
    size_tipo = -1;
}

cCliente::cCliente(char* name, char* code, char* tipo, int tam_nom, int tam_cod, int tam_tipo) 
    : cPersona(name, code, tam_nom, tam_cod) {
    tipo_cliente = nullptr;
    size_tipo = -1;
    
    if(llenado_tipo(tipo, tam_tipo)) {
        std::cout << "TIPO CLIENTE LLENADO CON EXITO" << std::endl;
    } else {
        std::cout << "TIPO CLIENTE no LLENADO CON EXITO" << std::endl;
    }
}

cCliente::cCliente(const cCliente& obj) : cPersona(obj) {
    tipo_cliente = nullptr;
    if(asignarValores(&obj)) {
        std::cout << "SE LOGRO COPIA CLIENTE" << std::endl;
    } else {
        std::cout << "NO SE LOGRO COPIA CLIENTE" << std::endl;
    }
}

cCliente& cCliente::operator=(const cCliente& obj) {
    if(this != &obj) {
        cPersona::operator=(obj);
        if(asignarValores(&obj)) {
            std::cout << "SE LOGRO ASIGNACION CLIENTE" << std::endl;
        } else {
            std::cout << "NO SE LOGRO ASIGNACION CLIENTE" << std::endl;
        }
    }
    return *this;
}

void cCliente::print() {
    cPersona::print();
    if(tipo_cliente != nullptr) {
        std::cout << "TIPO CLIENTE: " << tipo_cliente << " tam:" << size_tipo << std::endl;
    } else {
        std::cout << "Tipo cliente no asignado (nullptr)" << std::endl;
    }
}

bool cCliente::llenado_tipo(char* tipo, int size) {
    fecha.actualizarFecha();
    if(tipo != nullptr) {
        if(tipo_cliente != nullptr) {
            delete[] tipo_cliente;
        }
        
        if(size <= 1) {
            size = contador(tipo);
            if(size <= 1) {
                std::cout << "CADENA DE LONGITUD 0 INVIABLE" << std::endl;
                return false;
            }
        }
        
        size_tipo = size;
        tipo_cliente = new char[size_tipo];
        copiar(tipo, tipo_cliente, size_tipo);
        return true;
    }
    return false;
}

bool cCliente::asignarValores(const cCliente* obj) {
    if(obj->tipo_cliente != nullptr) {
        return llenado_tipo(obj->tipo_cliente, obj->size_tipo);
    }
    return false;
}

void cCliente::ultimoAcceso() {
    // Implementación específica para cliente
    cPersona::ultimoAcceso();
    std::cout << "Tipo de cliente: " << tipo_cliente << std::endl;
}

const char* cCliente::getTipo() {
    return tipo_cliente;
}

cCliente::~cCliente() {
    if(tipo_cliente != nullptr) {
        delete[] tipo_cliente;
        tipo_cliente = nullptr;
    }
}