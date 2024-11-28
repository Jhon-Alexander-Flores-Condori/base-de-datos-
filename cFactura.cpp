#include "cFactura.hpp"
#include <iostream>

cFactura::cFactura() : cModoPago()
{
    razon_social = nullptr;
    numero_factura = nullptr;
    cuit = nullptr;
    size_razon_social = -1;
    size_numero_factura = -1;
    size_cuit = -1;
}

cFactura::cFactura(char* method_name, char* payment_code, char* social_reason, 
                   char* invoice_number, char* tax_id, 
                   int tam_nom, int tam_cod, int tam_razon, 
                   int tam_factura, int tam_cuit) 
                   : cModoPago(method_name, payment_code, tam_nom, tam_cod)
{
    razon_social = nullptr;
    numero_factura = nullptr;
    cuit = nullptr;

    if(llenado_razon_social(social_reason, tam_razon))
    {
        std::cout<<"RAZON SOCIAL LLENADO CON EXITO"<<std::endl;
    }
    else
    {   
        std::cout<<"RAZON SOCIAL no LLENADO CON EXITO"<<std::endl;
        size_razon_social = -1;
    }

    if(llenado_numero_factura(invoice_number, tam_factura))
    {
        std::cout<<"NUMERO FACTURA LLENADO CON EXITO"<<std::endl;
    }
    else
    {   
        std::cout<<"NUMERO FACTURA no LLENADO CON EXITO"<<std::endl;
        size_numero_factura = -1;
    }

    if(llenado_cuit(tax_id, tam_cuit))
    {
        std::cout<<"CUIT LLENADO CON EXITO"<<std::endl;
    }
    else
    {   
        std::cout<<"CUIT no LLENADO CON EXITO"<<std::endl;
        size_cuit = -1;
    }
}

cFactura::cFactura(const cFactura &obj) : cModoPago(obj)
{
    razon_social = nullptr;
    numero_factura = nullptr;
    cuit = nullptr;

    if(asignarValores(&obj)) {
        std::cout << "SE LOGRO" << std::endl;
    } else {
        std::cout << "NO SE LOGRO" << std::endl;
    }
}

cFactura& cFactura::operator=(const cFactura &obj) {
    if(this != &obj) {  // Correct self-assignment check
        cModoPago::operator=(obj);  // Call base class assignment operator
        
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
bool cFactura::asignarValores(const cFactura* obj)
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

    if(llenado_numero_factura((*obj).numero_factura, (*obj).size_numero_factura))
    {
        std::cout<<"NUMERO FACTURA LLENADO CON EXITO"<<std::endl;
    }
    else
    {
        std::cout<<"NUMERO FACTURA no LLENO"<<std::endl;
        return false;
    }

    if(llenado_cuit((*obj).cuit, (*obj).size_cuit))
    {
        std::cout<<"CUIT LLENADO CON EXITO"<<std::endl;
    }
    else
    {
        std::cout<<"CUIT no LLENO"<<std::endl;
        return false;
    }

    return true;
}

void cFactura::print()
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

    if (numero_factura != nullptr)
    {
        std::cout<<"NUMERO FACTURA: " << numero_factura << " tam:" << size_numero_factura <<std::endl;
    }
    else
    {
        std::cout << "Numero Factura no asignado (nullptr)" << std::endl;
    }

    if (cuit != nullptr)
    {
        std::cout<<"CUIT: " << cuit << " tam:" << size_cuit <<std::endl;
    }
    else
    {
        std::cout << "CUIT no asignado (nullptr)" << std::endl;
    }
}

void cFactura::ultimoAcceso()
{
    std::cout << "Ultimo acceso de FACTURA: ";
    fecha.print();
}

bool cFactura::llenado_razon_social(char* razon, int size)
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

bool cFactura::llenado_numero_factura(char* factura, int size)
{
    fecha.actualizarFecha();

    if(factura != nullptr)
    {
        if(numero_factura != nullptr) 
            liberar(&numero_factura);

        int actual_size = 0;
        for(; factura[actual_size] != '\0'; actual_size++) {}
        actual_size++;

        if(size <= 1)
            size = actual_size;

        size_numero_factura = size;

        crear_memoria(size_numero_factura, &numero_factura);
        copiar(factura, numero_factura, size_numero_factura);
        return true;
    }
    std::cout<< "ERROR AL LLENAR NUMERO FACTURA" <<std::endl;
    return false;
}

bool cFactura::llenado_cuit(char* tax_id, int size)
{
    fecha.actualizarFecha();

    if(tax_id != nullptr)
    {
        if(cuit != nullptr) 
            liberar(&cuit);

        int actual_size = 0;
        for(; tax_id[actual_size] != '\0'; actual_size++) {}
        actual_size++;

        if(size <= 1)
            size = actual_size;

        size_cuit = size;

        crear_memoria(size_cuit, &cuit);
        copiar(tax_id, cuit, size_cuit);
        return true;
    }
    std::cout<< "ERROR AL LLENAR CUIT" <<std::endl;
    return false;
}

cFactura::~cFactura()
{
    liberar(&razon_social);
    liberar(&numero_factura);
    liberar(&cuit);
}

const char* cFactura::getRazonSocial()
{
    return razon_social;
}

const char* cFactura::getNumeroFactura()
{
    return numero_factura;
}

const char* cFactura::getCuit()
{
    return cuit;
}