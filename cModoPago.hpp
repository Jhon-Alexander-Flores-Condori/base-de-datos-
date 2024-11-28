#ifndef CMODO_PAGO_HPP
#define CMODO_PAGO_HPP
#include "cFecha.hpp"

class cModoPago {
protected:
    cFecha fecha;
    char* nombre_metodo;
    char* codigo_pago;
    double monto;
    int size_nombre_metodo;
    int size_codigo_pago;

public:
    cModoPago();
    cModoPago(char* method_name, char* payment_code, int tam_nom, int tam_cod);
    cModoPago(const cModoPago& obj);
    virtual ~cModoPago();
    cModoPago& operator=(const cModoPago& obj);

    virtual void print();
    bool llenado_nombre_metodo(char* name, int size = 0);
    bool llenado_codigo_pago(char* code, int size = 0);
    void setMonto(double _monto);

    const char* getNombreMetodo();
    const char* getCodigoPago();
    double getMonto();
    int getSize_nombre_metodo();
    int getSize_codigo_pago();

protected:
    void asignar_nullptr();
    void llenado_generalFecha();
    void llenado_fecha();
    bool asignarValores(const cModoPago* obj);
    void copiar(char* root, char* destino, int tam);
    int contador(const char* cadena);
    void crear_memoria(int tam, char** destino);
    void liberar(char** target);
};
#endif