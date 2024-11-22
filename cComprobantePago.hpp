#ifndef CCOMPROBANTEPAGO_HPP
#define CCOMPROBANTEPAGO_HPP

#include "cFecha.hpp"
#include "cModoPago.hpp"
#include "cInventario.hpp"
#include <vector>

class cComprobantePago {
protected:
    char* numero_comprobante;
    cFecha fecha_emision;
    cModoPago* modo_pago;
    std::vector<cProducto*> items;
    double subtotal;
    double impuestos;
    double total;
    bool anulado;
    int size_num;

public:
    virtual ~cComprobantePago();
    cComprobantePago();
    cComprobantePago(const cComprobantePago& obj);
    cComprobantePago& operator=(const cComprobantePago& obj);

    virtual void calcularTotales() = 0;
    virtual void imprimir() const = 0;
    virtual void anular();
    
    bool agregarItem(cProducto* producto, int cantidad = 1);
    bool eliminarItem(const char* codigo);
    
    bool llenado_numero(char* _numero, int size = 0);
    void setModoPago(cModoPago* modo);
    
    const char* getNumeroComprobante() const;
    double getSubtotal() const;
    double getImpuestos() const;
    double getTotal() const;
    bool isAnulado() const;

protected:
    void liberar(char** target);
    void crear_memoria(int tam, char** destino);
    void copiar(char* root, char* destino, int tam);
    int contador(const char* cadena);
};
#endif