#ifndef CBOLETA_HPP
#define CBOLETA_HPP

#include "cComprobantePago.hpp"

class cBoleta : public cComprobantePago {
private:
    char* dni_cliente;
    int size_dni;

public:
    ~cBoleta();
    cBoleta();
    cBoleta(const cBoleta& obj);
    cBoleta& operator=(const cBoleta& obj);

    void calcularTotales() override;
    void imprimir() const override;
    
    bool llenado_dni(char* _dni, int size = 0);
    const char* getDNICliente() const;
};