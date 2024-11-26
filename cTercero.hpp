#ifndef CTERCERO_HPP
#define CTERCERO_HPP

#include "cFecha.hpp"
#include "cCliente.hpp"

class cTercero : public cCliente
{

    public:
        explicit cTercero();
        explicit cTercero(char *name , char *code , char *direccion, int tam_nom, int tam_cod, int tam_direccion,
                          char *relative, char *money, int tam_relative, int tam_money);
        cTercero(const cTercero &obj);
		cTercero& operator=(const cTercero &obj);
        ~cTercero();

        bool llenado_factura(char *cadena, int size = 0);
        bool llenado_afiliado(char *cadena, int size = 0);
        bool llenado_size_factura(int size,char *cadena = nullptr);
        bool llenado_size_afiliado(int size,char *cadena = nullptr);

        const char * getAfiliado();
        const char * getFactura();
        int getSize_factura();
        int getSize_afiliado();

    private:
        char *factura;
        char *afiliado;

        int size_factura;
        int size_afiliado;

        bool asignar_valores(const cTercero &obj);
        bool llenar_nullptr();
};

#endif
