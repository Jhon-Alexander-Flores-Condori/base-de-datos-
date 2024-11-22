#ifndef CPROVEEDOR_HPP
#define CPROVEEDOR_HPP
#include "cPersona.hpp"

class cProveedor : public cPersona {
    private:
        char* rubro;//tipo de tela
        int size_rubro;//tamaño de rubro 
        
    public:
        ~cProveedor();//destructor
        cProveedor();//constructor por defecto
        cProveedor(char* name, char* code, char* rub, int tam_nom, int tam_cod, int tam_rub);// Constructor con parámetros
        cProveedor(const cProveedor& obj);// Constructor de copia
        cProveedor& operator=(const cProveedor& obj);// Operador de asignación
        
        void print() override;//El uso de override indica que se está sobrescribiendo una función base.
        bool llenado_rubro(char* rub, int size = 0);//rub
        const char* getRubro();
        
    private:
        void ultimoAcceso() override;
        bool asignarValores(const cProveedor* obj);
};
#endif