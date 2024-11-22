/*// cModoPago.hpp
#ifndef CMODOPAGO_HPP
#define CMODOPAGO_HPP

#include "cFecha.hpp"

class cModoPago {
protected:
    char* tipo;
    char* codigo_transaccion;
    double monto;
    bool aprobado;
    cFecha fecha_pago;
    int size_tipo;
    int size_cod;

public:
    virtual ~cModoPago();
    cModoPago();
    cModoPago(const cModoPago& obj);
    cModoPago& operator=(const cModoPago& obj);

    virtual bool procesarPago() = 0;
    virtual void anularPago();
    virtual bool validarPago() const = 0;
    
    bool llenado_tipo(char* _tipo, int size = 0);
    bool llenado_codigo(char* _codigo, int size = 0);
    void setMonto(double _monto);
    
    const char* getTipo() const;
    const char* getCodigoTransaccion() const;
    double getMonto() const;
    bool isAprobado() const;
    const char* getFechaPago() const;

protected:
    void liberar(char** target);
    void crear_memoria(int tam, char** destino);
    void copiar(char* root, char* destino, int tam);
    int contador(const char* cadena);
};
#endif
*/