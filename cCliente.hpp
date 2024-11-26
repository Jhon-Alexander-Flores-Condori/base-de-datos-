// cCliente.hpp
#ifndef CCLIENTE_HPP
#define CCLIENTE_HPP

#include "cPersona.hpp"

class cCliente : public cPersona {
protected: // atributos
    char* empresa;//nombre de empresa
    char* rubro;//a que se dedica la empresa 
    float montoCredito;
    int size_empresa;
    int size_rubro;
    bool estadoCliente; // Activo o inactivo

public:
    virtual ~cCliente();
    cCliente();
    cCliente(char* name, char* code, int tam_nom, int tam_cod);
    cCliente(const cCliente& obj);
    cCliente& operator=(const cCliente& obj);

    virtual void print();
    
    bool llenado_empresa(char* empresa, int size = 0);
    bool llenado_rubro(char* rubro, int size = 0);
    bool llenado_size_empresa(int size, char* cadena = nullptr);
    bool llenado_size_rubro(int size, char* cadena = nullptr);
    void setMontoCredito(float monto);
    void setEstadoCliente(bool estado);

    const char* getEmpresa();
    const char* getRubro();
    float getMontoCredito();
    bool getEstadoCliente();
    int getSize_emp();
    int getSize_rubro();

protected:
    virtual void ultimoAcceso();
    void asignar_nullptr();

private:
    void copiar_cliente(const cCliente& obj);
};
#endif // CCLIENTE_HPP