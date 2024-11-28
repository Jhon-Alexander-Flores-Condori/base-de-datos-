#ifndef CBOLETA_HPP
#define CBOLETA_HPP
#include "cModoPago.hpp"

class cBoleta : public cModoPago {
private:
    char* razon_social;
    char* numero_boleta;
    int size_razon_social;
    int size_numero_boleta;

public:
    cBoleta();
    cBoleta(char* method_name, char* payment_code, char* social_reason, char* boleta_number, 
            int tam_nom, int tam_cod, int tam_razon, int tam_boleta);
    cBoleta(const cBoleta& obj);
    ~cBoleta();
    cBoleta& operator=(const cBoleta& obj);

    void print() override;
    bool llenado_razon_social(char* razon, int size = 0);
    bool llenado_numero_boleta(char* boleta, int size = 0);

    const char* getRazonSocial();
    const char* getNumeroboleta();

protected:
    void ultimoAcceso() override;
    bool asignarValores(const cBoleta* obj);
};
#endif