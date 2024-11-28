#include "cBoleta.hpp"
#include"cFecha.hpp"
#include <iostream>

cBoleta::cBoleta() : cModoPago()
{
    razon_social = nullptr;
    numero_boleta = nullptr;
    size_razon_social = -1;
    size_numero_boleta = -1;
}

cBoleta::cBoleta(char* method_name, char* payment_code, char* social_reason, char* boleta_number, 
                 int tam_nom, int tam_cod, int tam_razon, int tam_boleta) 
                 : cModoPago(method_name, payment_code, tam_nom, tam_cod)
{
    razon_social = nullptr;
    numero_boleta = nullptr;

    if(llenado_razon_social(social_reason, tam_razon))
    {
        std::cout<<"RAZON SOCIAL LLENADO CON EXITO"<<std::endl;
    }
    else
    {   
        std::cout<<"RAZON SOCIAL no LLENADO CON EXITO"<<std::endl;
        size_razon_social = -1;
    }

    if(llenado_numero_boleta(boleta_number, tam_boleta))
    {
        std::cout<<"NUMERO BOLETA LLENADO CON EXITO"<<std::endl;
    }
    else
    {   
        std::cout<<"NUMERO BOLETA no LLENADO CON EXITO"<<std::endl;
        size_numero_boleta = -1;
    }
}

cBoleta::cBoleta(const cBoleta &obj) : cModoPago(obj)
{
    razon_social = nullptr;
    numero_boleta = nullptr;

    if(asignarValores(&obj)) {
        std::cout << "SE LOGRO" << std::endl;
    } else {
        std::cout << "NO SE LOGRO" << std::endl;
    }
}

cBoleta& cBoleta::operator=(const cBoleta &obj)
{
    if(this != &obj) {  // Correct self-assignment check
        cModoPago::operator=(obj);
        
        if(asignarValores(&obj)) {
            std::cout << "SE LOGRO" << std::endl;
        } else {
            std::cout << "NO SE LOGRO" << std::endl;
        }
    } else {
        std::cout << "NO SE LOGRO - no copia de si mismo" << std::endl;
    }

    return *this;
}

bool cBoleta::asignarValores(const cBoleta* obj)
{
    if(llenado_razon_social((*obj).razon_social, (*obj).size_razon_social))
    {
        std::cout<<"RAZON SOCIAL LLENADO CON EXITO"<<std::endl;
    }
    else
    {
        std::cout<<"RAZON SOCIAL no LLENO"<<std::endl;
        return false;
    }

    if(llenado_numero_boleta((*obj).numero_boleta, (*obj).size_numero_boleta))
    {
        std::cout<<"NUMERO BOLETA LLENADO CON EXITO"<<std::endl;
    }
    else
    {
        std::cout<<"NUMERO BOLETA no LLENO"<<std::endl;
        return false;
    }

    return true;
}

void cBoleta::print()
{
    cModoPago::print();

    if (razon_social != nullptr)
    {
        std::cout<<"RAZON SOCIAL: " << razon_social <<" tam:" << size_razon_social <<std::endl;
    }
    else
    {
        std::cout << "Razon Social no asignado (nullptr)" << std::endl;
    }

    if (numero_boleta != nullptr)
    {
        std::cout<<"NUMERO BOLETA: " << numero_boleta << " tam:" << size_numero_boleta <<std::endl;
    }
    else
    {
        std::cout << "Numero Boleta no asignado (nullptr)" << std::endl;
    }
}

// If fecha is a member of the base class cModoPago
void cBoleta::ultimoAcceso()
{
    std::cout << "Ultimo acceso de BOLETA: ";
    // Assuming fecha is inherited from cModoPago
    
    cModoPago::fecha.print();
}



bool cBoleta::llenado_razon_social(char* razon, int size)
{
    fecha.actualizarFecha();

    if(razon != nullptr)
    {
        if(razon_social != nullptr) 
            liberar(&razon_social);

        int actual_size = 0;
        for(; razon[actual_size] != '\0'; actual_size++) {}
        actual_size++;

        if(size <= 1)
            size = actual_size;

        size_razon_social = size;

        crear_memoria(size_razon_social, &razon_social);
        copiar(razon, razon_social, size_razon_social);
        return true;
    }
    std::cout<< "ERROR AL LLENAR RAZON SOCIAL" <<std::endl;
    return false;
}

bool cBoleta::llenado_numero_boleta(char* boleta, int size)
{
    fecha.actualizarFecha();

    if(boleta != nullptr)
    {
        if(numero_boleta != nullptr) 
            liberar(&numero_boleta);

        int actual_size = 0;
        for(; boleta[actual_size] != '\0'; actual_size++) {}
        actual_size++;

        if(size <= 1)
            size = actual_size;

        size_numero_boleta = size;

        crear_memoria(size_numero_boleta, &numero_boleta);
        copiar(boleta, numero_boleta, size_numero_boleta);
        return true;
    }
    std::cout<< "ERROR AL LLENAR NUMERO BOLETA" <<std::endl;
    return false;
}

cBoleta::~cBoleta()
{
    liberar(&razon_social);
    liberar(&numero_boleta);
}

const char* cBoleta::getRazonSocial()
{
    return razon_social;
}

const char* cBoleta::getNumeroboleta()
{
    return numero_boleta;
}