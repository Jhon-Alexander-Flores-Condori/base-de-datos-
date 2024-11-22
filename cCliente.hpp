#ifndef CCLIENTE_HPP
#define CCLIENTE_HPP

#include "cPersona.hpp"

class cCliente : public cPersona
{
public:
    ~cCliente();  // Destructor
    cCliente();   // Constructor por defecto
    cCliente(const char* name, const char* code, int tam_nom, int tam_cod);  // Constructor con parámetros
    cCliente(const cCliente& obj);  // Constructor de copia
    cCliente& operator=(const cCliente& obj);  // Operador de asignación

    // Sobrescritura del método print()
    void print() const override;
};

#endif
