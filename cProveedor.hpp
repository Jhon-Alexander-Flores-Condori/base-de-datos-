#ifndef CPROVEEDOR_HPP
#define CPROVEEDOR_HPP

#include "cPersona.hpp"

class cProveedor : public cPersona {
public:
    ~cProveedor();  // Destructor

    cProveedor();  // Constructor por defecto
    cProveedor(const char* name, const char* code, int tam_nom, int tam_cod);  // Constructor con parámetros

    cProveedor(const cProveedor& obj);  // Constructor de copia
    cProveedor& operator=(const cProveedor& obj);  // Operador de asignación

    void print() override;  // Método print (heredado de cPersona)
};

#endif // CPROVEEDOR_HPP
