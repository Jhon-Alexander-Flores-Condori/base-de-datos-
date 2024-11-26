#ifndef CPROVEEDOR_HPP
#define CPROVEEDOR_HPP

#include "cPersona.hpp"

class cProveedor : public cPersona {
private:
    char* tipo_servicio;  // Tipo de servicio o producto que provee
    int size_tipo_servicio;
    char* especialidad;   // Especialidad del proveedor
    int size_especialidad;
    double tarifa;        // Tarifa o precio de sus servicios

public:
    // Constructores
    cProveedor();
    cProveedor(char* name, char* code, int tam_nom, int tam_cod);
    cProveedor(const cProveedor &obj); // Constructor de copia

    // Destructor
    ~cProveedor();

    // Operador de asignación
    cProveedor& operator=(const cProveedor &obj);

    // Métodos para llenar tipo de servicio y especialidad
    bool llenado_tipo_servicio(char* serv, int size);
    bool llenado_especialidad(char* espec, int size);
    void setTarifa(double _tarifa);

    // Método para imprimir información del proveedor
    void print() override;

    // Getters
    const char* getTipoServicio();
    const char* getEspecialidad();
    double getTarifa();
    int getSize_tipo_servicio();
    int getSize_especialidad();

private:
    // Métodos privados de ayuda
    bool llenado_size_tipo_servicio(int size, char* cadena);
    void asignar_nullptr();
};

#endif // CPROVEEDOR_HPP