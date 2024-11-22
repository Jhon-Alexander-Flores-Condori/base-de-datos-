#ifndef CCLIENTE_HPP
#define CCLIENTE_HPP
#include "cPersona.hpp"

class cCliente : public cPersona {
    private:
        // Add any client-specific attributes here
        char* tipo_cliente;
        int size_tipo;
        
    public:
        ~cCliente();
        cCliente();
        cCliente(char* name, char* code, char* tipo, int tam_nom, int tam_cod, int tam_tipo);
        cCliente(const cCliente& obj);
        cCliente& operator=(const cCliente& obj);
        
        void print() override;
        bool llenado_tipo(char* tipo, int size = 0);
        const char* getTipo();
        
    private:
        void ultimoAcceso() override;
        bool asignarValores(const cCliente* obj);
};
#endif