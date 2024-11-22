#include "cPersona.hpp"
#include <iostream>

cPersona::cPersona() {
    asignar_nullptr();
    size_nom = -1;
    size_cod = -1;
    llenado_generalFecha();
}

cPersona::cPersona(char* name, char* code, int tam_nom, int tam_cod) {
    asignar_nullptr();
    llenado_generalFecha();

    if(llenado_codigo(code, tam_cod)) {
        std::cout << "CODIGO LLENADO CON EXITO" << std::endl;
    } else {
        std::cout << "CODIGO no LLENADO CON EXITO" << std::endl;
        size_cod = -1;
    }

    if(llenado_nombre(name, tam_nom)) {
        std::cout << "NOMBRE LLENADO CON EXITO" << std::endl;
    } else {
        std::cout << "NOMBRE no LLENADO CON EXITO" << std::endl;
        size_nom = -1;
    }
}

cPersona::cPersona(const cPersona& obj) {
    asignar_nullptr();
    if(asignarValores(&obj)) {
        std::cout << "SE LOGRO" << std::endl;
    } else {
        std::cout << "NO SE LOGRO" << std::endl;
    }
}

cPersona& cPersona::operator=(const cPersona& obj) {
    if(this != &obj) {
        if(asignarValores(&obj)) {
            std::cout << "SE LOGRO" << std::endl;
        } else {
            std::cout << "NO SE LOGRO" << std::endl;
        }
    }
    return *this;
}

void cPersona::print() {
    char respuesta{'N'};
    bool valido = true;

    if(nombre != nullptr) {
        std::cout << "NOMBRE: " << nombre << " tam:" << size_nom << std::endl;
    } else {
        std::cout << "Nombre no asignado (nullptr)" << std::endl;
        valido = false;
    }

    if(codigo != nullptr) {
        std::cout << "CODIGO: " << codigo << " tam:" << size_cod << std::endl;
    } else {
        std::cout << "Codigo no asignado (nullptr)" << std::endl;
        valido = false;
    }

    if(!valido) {
        std::cout << "NO SE ACCEDERA A SU ULTIMO ACCESO";
    } else {
        std::cout << "¿Desea conocer el ultimo acceso? (Y/N) ";
        std::cin >> respuesta;

        if(respuesta == 'Y' || respuesta == 'y') {
            ultimoAcceso();
        }
    }
}

// The rest of the implementation remains the same as in cCliente
// Just replace cCliente with cPersona in all method definitions

void cPersona::ultimoAcceso() {
    char temp[40];
    bool flag = true;
    int i = 0;

    fecha.actualizarFecha();

    std::cout << "Ingrese codigo" << std::endl;
    std::cin >> temp;

    while(*(codigo + i) != '\0') {
        if(*(temp + i) != *(codigo + i)) {
            flag = false;
            break;
        }
        i++;
    }

    if(flag) {
        std::cout << "Ultimo acceso: ";
        fecha.print();
    } else {
        std::cout << "INCORRECTO";
    }
}

// Include all other methods from cCliente.cpp, replacing cCliente with cPersona

cPersona::~cPersona() {
    fecha.actualizarFecha();
    liberar(&nombre);
    liberar(&codigo);
    liberar(&cadena_fecha);
}