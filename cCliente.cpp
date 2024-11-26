// cCliente.cpp
#include "cCliente.hpp"
#include <cstring>
#include <iostream>

// Constructor por defecto
cCliente::cCliente() : cPersona() {
    empresa = nullptr;
    rubro = nullptr;
    montoCredito = 0.0;
    size_empresa = 0;
    size_rubro = 0;
    estadoCliente = false;
}

// Constructor con nombre y código
cCliente::cCliente(char* name, char* code, int tam_nom, int tam_cod) 
    : cPersona(name, code, tam_nom, tam_cod) {
    empresa = nullptr;
    rubro = nullptr;
    montoCredito = 0.0;
    size_empresa = 0;
    size_rubro = 0;
    estadoCliente = false;
}

// Constructor de copia
cCliente::cCliente(const cCliente& obj) : cPersona(obj) {
    copiar_cliente(obj);
}

// Operador de asignación
cCliente& cCliente::operator=(const cCliente& obj) {
    if (this != &obj) {
        // Llamar al operador de asignación de la clase padre
        cPersona::operator=(obj);

        // Liberar memoria anterior
        liberar(&empresa);
        liberar(&rubro);

        // Copiar nuevos valores
        copiar_cliente(obj);
    }
    return *this;
}

// Método privado para copiar datos del cliente
void cCliente::copiar_cliente(const cCliente& obj) {
    // Copiar empresa
    if (obj.empresa) {
        crear_memoria(obj.size_empresa, &empresa);
        copiar(obj.empresa, empresa, obj.size_empresa);
        size_empresa = obj.size_empresa;
    }

    // Copiar rubro
    if (obj.rubro) {
        crear_memoria(obj.size_rubro, &rubro);
        copiar(obj.rubro, rubro, obj.size_rubro);
        size_rubro = obj.size_rubro;
    }

    // Copiar otros atributos
    montoCredito = obj.montoCredito;
    estadoCliente = obj.estadoCliente;
}

// Destructor
cCliente::~cCliente() {
    liberar(&empresa);
    liberar(&rubro);
}

// Método para imprimir información
void cCliente::print() {
    // Primero imprimir información de persona
    cPersona::print();
    
    // Luego imprimir información específica de cliente
    std::cout << "Empresa: " << (empresa ? empresa : "No definida") << std::endl;
    std::cout << "Rubro: " << (rubro ? rubro : "No definido") << std::endl;
    std::cout << "Monto de Crédito: $" << montoCredito << std::endl;
    std::cout << "Estado del Cliente: " << (estadoCliente ? "Activo" : "Inactivo") << std::endl;
}

// Método para llenar empresa
bool cCliente::llenado_empresa(char* empresa, int size) {
    if (size == 0) size = contador(empresa);
    
    // Liberar memoria anterior
    liberar(&(this->empresa));
    
    // Crear nueva memoria
    crear_memoria(size, &(this->empresa));
    
    // Copiar datos
    copiar(empresa, this->empresa, size);
    size_empresa = size;
    
    return true;
}

// Método para llenar rubro
bool cCliente::llenado_rubro(char* rubro, int size) {
    if (size == 0) size = contador(rubro);
    
    // Liberar memoria anterior
    liberar(&(this->rubro));
    
    // Crear nueva memoria
    crear_memoria(size, &(this->rubro));
    
    // Copiar datos
    copiar(rubro, this->rubro, size);
    size_rubro = size;
    
    return true;
}

// Método para llenar tamaño de empresa
bool cCliente::llenado_size_empresa(int size, char* cadena) {
    size_empresa = size;
    
    // Si se proporciona cadena, copiar
    if (cadena) {
        liberar(&empresa);
        crear_memoria(size, &empresa);
        copiar(cadena, empresa, size);
    }
    
    return true;
}

// Método para llenar tamaño de rubro
bool cCliente::llenado_size_rubro(int size, char* cadena) {
    size_rubro = size;
    
    // Si se proporciona cadena, copiar
    if (cadena) {
        liberar(&rubro);
        crear_memoria(size, &rubro);
        copiar(cadena, rubro, size);
    }
    
    return true;
}

// Setters
void cCliente::setMontoCredito(float monto) {
    montoCredito = monto;
}

void cCliente::setEstadoCliente(bool estado) {
    estadoCliente = estado;
}

// Getters
const char* cCliente::getEmpresa() {
    return empresa;
}

const char* cCliente::getRubro() {
    return rubro;
}

float cCliente::getMontoCredito() {
    return montoCredito;
}

bool cCliente::getEstadoCliente() {
    return estadoCliente;
}

int cCliente::getSize_emp() {
    return size_empresa;
}

int cCliente::getSize_rubro() {
    return size_rubro;
}

// Método protegido para último acceso
void cCliente::ultimoAcceso() {
    // Implementación específica para cliente
    std::cout << "Último acceso de cliente" << std::endl;
}