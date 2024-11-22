#ifndef CFACTURA_HPP
#define CFACTURA_HPP

#include "cComprobantePago.hpp"

class cFactura : public cComprobantePago {
private:
    char* ruc_cliente;
    char* razon_social;
    char* direccion_fiscal;
    int size_ruc;
    int size_razon;
    int size_dir;

public:
    ~cFactura();
    cFactura();
    cFactura(const cFactura& obj);
    cFactura& operator=(const cFactura& obj);

    void calcularTotales() override;
    void imprimir() const override;
    
    bool llenado_ruc(char* _ruc, int size = 0);
    bool llenado_razon_social(char* _razon, int size = 0);
    bool llenado_direccion(char* _dir, int size = 0);
    
    const char* getRUCCliente() const;
    const char* getRazonSocial() const;
    const char* getDireccionFiscal() const;
};

#endif