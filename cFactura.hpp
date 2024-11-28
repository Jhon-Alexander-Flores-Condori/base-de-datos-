#ifndef CFACTURA_HPP
#define CFACTURA_HPP
#include "cModoPago.hpp"

class cFactura : public cModoPago {
private:
    char* razon_social;
    char* numero_factura;
    char* cuit;
    int size_razon_social;
    int size_numero_factura;
    int size_cuit;

public:
    cFactura();
    cFactura(char* method_name, char* payment_code, char* social_reason, 
             char* invoice_number, char* tax_id, 
             int tam_nom, int tam_cod, int tam_razon, int tam_factura, int tam_cuit);
    cFactura(const cFactura& obj);
    ~cFactura();
    cFactura& operator=(const cFactura& obj);

    void print() override;
    bool llenado_razon_social(char* razon, int size = 0);
    bool llenado_numero_factura(char* factura, int size = 0);
    bool llenado_cuit(char* tax_id, int size = 0);

    const char* getRazonSocial();
    const char* getNumeroFactura();
    const char* getCuit();

protected:
    void ultimoAcceso() override;
    bool asignarValores(const cFactura* obj);
};
#endif