#include "cModoPago.hpp"
#include <iostream>
#include <ctime>

cModoPago::cModoPago()
{
    asignar_nullptr();
    size_nombre_metodo = -1;
    size_codigo_pago = -1;
    monto = 0.0;
    llenado_generalFecha();
}

cModoPago::cModoPago(char* method_name, char* payment_code, int tam_nom, int tam_cod)
{
    asignar_nullptr();
    llenado_generalFecha();

    if(llenado_codigo_pago(payment_code, tam_cod))
    {
        std::cout<<"CODIGO PAGO LLENADO CON EXITO"<<std::endl;
    }
    else
    {   
        std::cout<<"CODIGO PAGO no LLENADO CON EXITO"<<std::endl;
        size_codigo_pago = -1;
    }

    if(llenado_nombre_metodo(method_name, tam_nom))
    {
        std::cout<<"NOMBRE METODO LLENADO CON EXITO"<<std::endl;
    }
    else
    {   
        std::cout<<"NOMBRE METODO no LLENADO CON EXITO"<<std::endl;
        size_nombre_metodo = -1;
    }
}

cModoPago::cModoPago(const cModoPago &obj)
{
    asignar_nullptr();

    if(asignarValores(&obj)) {
        std::cout << "SE LOGRO" << std::endl;
    } else {
        std::cout << "NO SE LOGRO" << std::endl;
    }

    std::cout << "CONSTRUCTOR DE COPIA" << std::endl;
}

cModoPago& cModoPago::operator=(const cModoPago &obj)
{
    if(this != &obj) {  // Correct self-assignment check
        if(asignarValores(&obj)) {
            std::cout << "SE LOGRO" << std::endl;
        } else {
            std::cout << "NO SE LOGRO" << std::endl;
        }
    } else {
        std::cout << "NO SE LOGRO - no copia de si mismo" << std::endl;
    }

    std::cout << "SOBRECARGA DE OPERADOR" << std::endl;
    return *this;
}

bool cModoPago::asignarValores(const cModoPago *obj)
{
    fecha.actualizarFecha();
    fecha = (*obj).fecha;

    if(llenado_codigo_pago((*obj).codigo_pago, (*obj).size_codigo_pago))
    {
        std::cout<<"CODIGO PAGO LLENADO CON EXITO"<<std::endl;
    }
    else
    {
        std::cout<<"CODIGO PAGO no LLENO"<<std::endl;
        return false;
    }

    if(llenado_nombre_metodo((*obj).nombre_metodo, (*obj).size_nombre_metodo))
    {
        std::cout<<"NOMBRE METODO LLENADO CON EXITO"<<std::endl;
    }
    else
    {   
        std::cout<<"NOMBRE METODO no LLENO"<<std::endl;
        return false;
    }

    setMonto((*obj).monto);

    return true;
}

void cModoPago::print()
{
    bool valido = true;

    if (nombre_metodo != nullptr)
    {
        std::cout<<"NOMBRE METODO: " << nombre_metodo <<" tam:" << size_nombre_metodo <<std::endl;
    }
    else
    {
        std::cout << "Nombre Metodo no asignado (nullptr)" << std::endl;
        valido = false;
    }

    if (codigo_pago != nullptr)
    {
        std::cout<<"CODIGO PAGO: " << codigo_pago << " tam:" << size_codigo_pago <<std::endl;
    }
    else
    {
        std::cout << "Codigo Pago no asignado (nullptr)" << std::endl;
        valido = false;
    }

    std::cout << "MONTO: " << monto << std::endl;

    if(valido)
    {
        std::cout << "Ultimo acceso: ";
        fecha.print();
    }
}

void cModoPago::asignar_nullptr()
{
    nombre_metodo = nullptr;
    codigo_pago = nullptr;
}

void cModoPago::llenado_generalFecha()
{
    char respuesta;

    std::cout<<"Desea inicializar fecha o por defecto? (Y/N): ";
    std::cin>>respuesta;

    if(respuesta == 'Y' || respuesta == 'y')
    {
        llenado_fecha();
    }
    else
    {   
        fecha.actualizarFecha();    
    }
}

void cModoPago::llenado_fecha()
{
    int valor = 0;

    std::cout<<"dia: ";
    std::cin>> valor;
    fecha.setDia(valor);

    std::cout<<"mes: ";
    std::cin>> valor;
    fecha.setMes(valor);

    std::cout<<"year: ";
    std::cin>> valor;
    fecha.setYear(valor);

    std::cout<<"Segundo: ";
    std::cin>> valor;
    fecha.setSeg(valor);

    std::cout<<"Minuto: ";
    std::cin>> valor;
    fecha.setMin(valor);

    std::cout<<"Hora: ";
    std::cin>> valor;
    fecha.setHora(valor);
}

bool cModoPago::llenado_nombre_metodo(char* name, int size)
{
    fecha.actualizarFecha();

    if(name != nullptr)
    {
        if(nombre_metodo != nullptr) 
            liberar(&nombre_metodo);

        int actual_size = 0;
        for(; name[actual_size] != '\0'; actual_size++) {}
        actual_size++;

        if(size <= 1)
            size = actual_size;

        size_nombre_metodo = size;

        crear_memoria(size_nombre_metodo, &nombre_metodo);
        copiar(name, nombre_metodo, size_nombre_metodo);
        return true;
    }
    std::cout<< "ERROR AL LLENAR NOMBRE METODO" <<std::endl;
    return false;
}

bool cModoPago::llenado_codigo_pago(char* code, int size)
{
    fecha.actualizarFecha();

    if(code != nullptr)
    {
        if(codigo_pago != nullptr) 
            liberar(&codigo_pago);

        int actual_size = 0;
        for(; code[actual_size] != '\0'; actual_size++) {}
        actual_size++;

        if(size <= 1)
            size = actual_size;

        size_codigo_pago = size;

        crear_memoria(size_codigo_pago, &codigo_pago);
        copiar(code, codigo_pago, size_codigo_pago);
        return true;
    }
    std::cout<< "ERROR AL LLENAR CODIGO PAGO" <<std::endl;
    return false;
}

void cModoPago::setMonto(double _monto)
{
    monto = _monto;
}

void cModoPago::copiar(char* root, char* destino, int tam)
{
    for(int i = 0; i < tam; i++)
    {
        *(destino+i) = *(root+i);
    }
    *(destino+(tam-1)) = '\0';
}

int cModoPago::contador(const char* cadena)
{
    int fin = 0;
    while(*(cadena+fin) != '\0')
    {
        fin++;
    }
    return fin+1;
}

void cModoPago::crear_memoria(int tam, char** destino)
{
    if (tam > 0)
    {   
        *destino = new char[tam]; 
    }
    else
    {
        *destino = nullptr;
        std::cout<<"array = 0 bytes?"<< std::endl;
    }
}

void cModoPago::liberar(char** target)
{
    if (*target != nullptr) {
        delete[] *target;
        *target = nullptr;
    }
}

cModoPago::~cModoPago()
{
    fecha.actualizarFecha();
    liberar(&nombre_metodo);
    liberar(&codigo_pago);
}

const char* cModoPago::getNombreMetodo()
{
    return nombre_metodo;
}

const char* cModoPago::getCodigoPago()
{
    return codigo_pago;
}

double cModoPago::getMonto()
{
    return monto;
}

int cModoPago::getSize_nombre_metodo()
{
    return size_nombre_metodo;
}

int cModoPago::getSize_codigo_pago()
{
    return size_codigo_pago;
}