#include "cProveedor.hpp"
#include <iostream>
#include <iomanip>

// Constructor por defecto
cProveedor::cProveedor() : cPersona()
{
    asignar_nullptr();
    size_tipo_servicio = -1;
    size_especialidad = -1;
    tarifa = 0.0;
}

// Constructor con parámetros
cProveedor::cProveedor(char* name, char* code, int tam_nom, int tam_cod) 
    : cPersona(name, code, tam_nom, tam_cod)
{
    asignar_nullptr();
    size_tipo_servicio = -1;
    size_especialidad = -1;
    tarifa = 0.0;
}

// Constructor de copia
cProveedor::cProveedor(const cProveedor &obj) : cPersona(obj)
{
    asignar_nullptr();

    if(obj.tipo_servicio != nullptr) {
        llenado_tipo_servicio(obj.tipo_servicio, obj.size_tipo_servicio);
    }

    if(obj.especialidad != nullptr) {
        llenado_especialidad(obj.especialidad, obj.size_especialidad);
    }

    tarifa = obj.tarifa;
}

// Operador de asignación
cProveedor& cProveedor::operator=(const cProveedor &obj)
{
    if(this != &obj) {
        // Llamar al operador de asignación de la clase base
        cPersona::operator=(obj);

        // Liberar memoria existente
        liberar(&tipo_servicio);
        liberar(&especialidad);

        if(obj.tipo_servicio != nullptr) {
            llenado_tipo_servicio(obj.tipo_servicio, obj.size_tipo_servicio);
        }

        if(obj.especialidad != nullptr) {
            llenado_especialidad(obj.especialidad, obj.size_especialidad);
        }

        tarifa = obj.tarifa;
    }
    return *this;
}

// Método para asignar nullptr a los punteros
void cProveedor::asignar_nullptr()
{
    tipo_servicio = nullptr;
    especialidad = nullptr;
}

// Método para validar y asignar tamaño de tipo de servicio
bool cProveedor::llenado_size_tipo_servicio(int size, char* cadena)
{
    if(size <= 1)
    {
        size = contador(cadena);
        if(size <= 1)
        {
            size_tipo_servicio = -1;
            std::cout << "CADENA DE TIPO DE SERVICIO DE LONGITUD 0 INVIABLE" << std::endl;
            return false;
        }
    }

    size_tipo_servicio = size;
    return true;
}

// Método para llenar tipo de servicio
bool cProveedor::llenado_tipo_servicio(char* serv, int size)
{
    if(serv != nullptr)
    {
        if(tipo_servicio != nullptr) 
            liberar(&tipo_servicio);

        if(llenado_size_tipo_servicio(size, serv))
        {
            crear_memoria(size_tipo_servicio, &tipo_servicio);
            copiar(serv, tipo_servicio, size_tipo_servicio);
            return true;
        }
    }
    std::cout << "ERROR AL LLENAR TIPO DE SERVICIO" << std::endl;
    return false;
}

// Método para llenar especialidad
bool cProveedor::llenado_especialidad(char* espec, int size)
{
    if(espec != nullptr)
    {
        if(especialidad != nullptr) 
            liberar(&especialidad);

        if(llenado_size_tipo_servicio(size, espec))
        {
            crear_memoria(size_especialidad, &especialidad);
            copiar(espec, especialidad, size_especialidad);
            return true;
        }
    }
    std::cout << "ERROR AL LLENAR ESPECIALIDAD" << std::endl;
    return false;
}

// Método para establecer tarifa
void cProveedor::setTarifa(double _tarifa)
{
    tarifa = _tarifa;
}

// Método para imprimir información del proveedor
void cProveedor::print()
{
    // Llamar al método print de la clase base
    cPersona::print();

    // Imprimir información adicional de proveedor
    if (tipo_servicio != nullptr)
    {
        std::cout << "TIPO DE SERVICIO: " << tipo_servicio 
                  << " tam:" << size_tipo_servicio << std::endl;
    }
    else
    {
        std::cout << "Tipo de servicio no asignado (nullptr)" << std::endl;
    }

    if (especialidad != nullptr)
    {
        std::cout << "ESPECIALIDAD: " << especialidad 
                  << " tam:" << size_especialidad << std::endl;
    }
    else
    {
        std::cout << "Especialidad no asignada (nullptr)" << std::endl;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "TARIFA: $" << tarifa << std::endl;
}

// Destructor
cProveedor::~cProveedor()
{
    liberar(&tipo_servicio);
    liberar(&especialidad);
}

// Getters
const char* cProveedor::getTipoServicio()
{
    return tipo_servicio;
}

const char* cProveedor::getEspecialidad()
{
    return especialidad;
}

double cProveedor::getTarifa()
{
    return tarifa;
}

int cProveedor::getSize_tipo_servicio()
{
    return size_tipo_servicio;
}

int cProveedor::getSize_especialidad()
{
    return size_especialidad;
}