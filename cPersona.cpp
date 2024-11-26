#include "cPersona.hpp"
#include <iostream>
#include <ctime>

cPersona::cPersona()
{
    asignar_nullptr();
    size_nombre = -1;
    size_codigo = -1;
    size_telefono = -1;
    size_correo = -1;
    size_direccion = -1;
    edad = 0;
    llenado_generalFecha();
}

cPersona::cPersona(char* name, char* code, int tam_nom, int tam_cod)
{
    asignar_nullptr();
    llenado_generalFecha();

    if(llenado_codigo(code, tam_cod))
    {
        std::cout<<"CODIGO LLENADO CON EXITO"<<std::endl;
    }
    else
    {   
        std::cout<<"CODIGO no LLENADO CON EXITO"<<std::endl;
        size_codigo = -1;
    }

    if(llenado_nombre(name, tam_nom))
    {
        std::cout<<"NOMBRE LLENADO CON EXITO"<<std::endl;
    }
    else
    {   
        std::cout<<"NOMBRE no LLENADO CON EXITO"<<std::endl;
        size_nombre = -1;
    }
}

cPersona::cPersona(const cPersona &obj) // Constructor de copia
{
    asignar_nullptr();

    if(asignarValores(&obj)) {
        std::cout << "SE LOGRO" << std::endl;
    } else {
        std::cout << "NO SE LOGRO" << std::endl;
    }

    std::cout << "CONSTRUCTOR DE COPIA" << std::endl;
}

cPersona& cPersona::operator=(const cPersona &obj) // Operador de asignación
{
    if(&obj != this) {
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

bool cPersona::asignarValores(const cPersona *obj)
{
    fecha.actualizarFecha();
    fecha = (*obj).fecha;

    if(llenado_codigo((*obj).codigo, (*obj).size_codigo))
    {
        std::cout<<"CODIGO LLENADO CON EXITO"<<std::endl;
    }
    else
    {
        std::cout<<"CODIGO no LLENO"<<std::endl;
        return false;
    }

    if(llenado_nombre((*obj).nombre, (*obj).size_nombre))
    {
        std::cout<<"NOMBRE LLENADO CON EXITO"<<std::endl;
    }
    else
    {   
        std::cout<<"NOMBRE no LLENO"<<std::endl;
        return false;
    }

    if(llenado_telefono((*obj).telefono, (*obj).size_telefono))
    {
        std::cout<<"TELEFONO LLENADO CON EXITO"<<std::endl;
    }
    else
    {   
        std::cout<<"TELEFONO no LLENO"<<std::endl;
        return false;
    }

    if(llenado_correo((*obj).correo, (*obj).size_correo))
    {
        std::cout<<"CORREO LLENADO CON EXITO"<<std::endl;
    }
    else
    {   
        std::cout<<"CORREO no LLENO"<<std::endl;
        return false;
    }

    if(llenado_direccion((*obj).direccion, (*obj).size_direccion))
    {
        std::cout<<"DIRECCION LLENADO CON EXITO"<<std::endl;
    }
    else
    {   
        std::cout<<"DIRECCION no LLENO"<<std::endl;
        return false;
    }

    setEdad((*obj).edad);

    return true;
}

void cPersona::print()
{
    bool valido = true;

    if (nombre != nullptr)
    {
        std::cout<<"NOMBRE: " << nombre <<" tam:" << size_nombre <<std::endl;
    }
    else
    {
        std::cout << "Nombre no asignado (nullptr)" << std::endl;
        valido = false;
    }

    if (codigo != nullptr)
    {
        std::cout<<"CODIGO: " << codigo << " tam:" << size_codigo <<std::endl;
    }
    else
    {
        std::cout << "Codigo no asignado (nullptr)" << std::endl;
        valido = false;
    }

    if (telefono != nullptr)
    {
        std::cout<<"TELEFONO: " << telefono << " tam:" << size_telefono <<std::endl;
    }
    else
    {
        std::cout << "Telefono no asignado (nullptr)" << std::endl;
        valido = false;
    }

    if (correo != nullptr)
    {
        std::cout<<"CORREO: " << correo << " tam:" << size_correo <<std::endl;
    }
    else
    {
        std::cout << "Correo no asignado (nullptr)" << std::endl;
        valido = false;
    }

    if (direccion != nullptr)
    {
        std::cout<<"DIRECCION: " << direccion << " tam:" << size_direccion <<std::endl;
    }
    else
    {
        std::cout << "Direccion no asignado (nullptr)" << std::endl;
        valido = false;
    }

    std::cout << "EDAD: " << edad << std::endl;

    if(!valido)
    {
        std::cout<<"NO SE ACCEDERA A SU ULTIMO ACCESO";
    }
    else
    {
        ultimoAcceso();
    }
}

void cPersona::ultimoAcceso()
{
    std::cout << "Ultimo acceso: ";
    fecha.print();
}

void cPersona::asignar_nullptr()
{
    nombre = nullptr;
    codigo = nullptr;
    telefono = nullptr;
    correo = nullptr;
    direccion = nullptr;
}

void cPersona::llenado_generalFecha()
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

void cPersona::llenado_fecha()
{
    int valor = 0;

    std::cout<<"dia: ";
    std::cin>> valor;
    fecha.setDia(valor);
    std::cout<<" "<<std::endl;

    std::cout<<"mes: ";
    std::cin>> valor;
    fecha.setMes(valor);
    std::cout<<" "<<std::endl;

    std::cout<<"year: ";
    std::cin>> valor;
    fecha.setYear(valor);
    std::cout<<" "<<std::endl;

    std::cout<<"Segundo: ";
    std::cin>> valor;
    fecha.setSeg(valor);
    std::cout<<" "<<std::endl;

    std::cout<<"Minuto: ";
    std::cin>> valor;
    fecha.setMin(valor);
    std::cout<<" "<<std::endl;

    std::cout<<"Hora: ";
    std::cin>> valor;
    fecha.setHora(valor);
    std::cout<<" "<<std::endl;
}

bool cPersona::llenado_size_nombre(int size, char* cadena)
{
    if(size <= 1)
    {
        size = contador(cadena);
        if(size<=1)
        {
            size_nombre = -1;
            std::cout<<"CADENA DE LONGITUD 0 INVIABLE"<<std::endl;
            return false;
        }
    }

    size_nombre = size;
    return true;
}

bool cPersona::llenado_size_codigo(int size, char* cadena)
{
    if(size <= 1)
    {
        size = contador(cadena);
        if(size<=1)
        {
            size_codigo = -1;
            std::cout<<"CADENA DE LONGITUD 0 INVIABLE"<<std::endl;
            return false;
        }
    }

    size_codigo = size;
    return true;
}

bool cPersona::llenado_nombre(char* name, int size)
{
    fecha.actualizarFecha();

    if(name != nullptr)
    {
        if(nombre != nullptr) 
            liberar(&nombre);

        if(llenado_size_nombre(size, name))
        {
            crear_memoria(size_nombre, &nombre);
            copiar(name, nombre, size_nombre);
            return true;
        }
    }
    std::cout<< "ERROR AL LLENAR NOMBRE" <<std::endl;
    return false;
}

bool cPersona::llenado_codigo(char* code, int size)
{
    fecha.actualizarFecha();
    if(code != nullptr)
    {
        if(codigo != nullptr) 
            liberar(&codigo);

        if(llenado_size_codigo(size, code))
        {
            crear_memoria(size_codigo, &codigo);
            copiar(code, codigo, size_codigo);
            return true;
        }
    }
    std::cout<< "ERROR AL LLENAR CODIGO" <<std::endl;
    return false;
}

bool cPersona::llenado_telefono(char* tel, int size)
{
    fecha.actualizarFecha();

    if(tel != nullptr)
    {
        if(telefono != nullptr) 
            liberar(&telefono);

        if(llenado_size_codigo(size, tel))
        {
            crear_memoria(size_telefono, &telefono);
            copiar(tel, telefono, size_telefono);
            return true;
        }
    }
    std::cout<< "ERROR AL LLENAR TELEFONO" <<std::endl;
    return false;
}

bool cPersona::llenado_correo(char* email, int size)
{
    fecha.actualizarFecha();

    if(email != nullptr)
    {
        if(correo != nullptr) 
            liberar(&correo);

        if(llenado_size_codigo(size, email))
        {
            crear_memoria(size_correo, &correo);
            copiar(email, correo, size_correo);
            return true;
        }
    }
    std::cout<< "ERROR AL LLENAR CORREO" <<std::endl;
    return false;
}

bool cPersona::llenado_direccion(char* dir, int size)
{
    fecha.actualizarFecha();

    if(dir != nullptr)
    {
        if(direccion != nullptr) 
            liberar(&direccion);

        if(llenado_size_codigo(size, dir))
        {
            crear_memoria(size_direccion, &direccion);
            copiar(dir, direccion, size_direccion);
            return true;
        }
    }
    std::cout<< "ERROR AL LLENAR DIRECCION" <<std::endl;
    return false;
}

void cPersona::setEdad(int _edad)
{
    edad = _edad;
}

int cPersona::contador(const char* cadena)
{
    int fin = 0;
    while(*(cadena+fin) != '\0')
    {
        fin++;
    }
    return fin+1;
}

void cPersona::crear_memoria(int tam, char** destino)
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

void cPersona::copiar(char* root, char* destino, int tam)
{
    for(int i = 0; i < tam; i++)
    {
        *(destino+i) = *(root+i);
    }
    *(destino+(tam-1)) = '\0';
}

void cPersona::liberar(char** target)
{
    if (*target != nullptr) {
        delete[] *target;
        *target = nullptr;
    }
}

cPersona::~cPersona()
{
    fecha.actualizarFecha();
    liberar(&nombre);
    liberar(&codigo);
    liberar(&telefono);
    liberar(&correo);
    liberar(&direccion);
}

// Getter methods
const char* cPersona::getFecha()
{
    // Similar implementation to cCliente
    return nullptr;  // Placeholder
}

const char* cPersona::getNombre()
{
    return nombre;
}

const char* cPersona::getCodigo()
{
    return codigo;
}

const char* cPersona::getTelefono()
{
    return telefono;
}

const char* cPersona::getCorreo()
{
    return correo;
}

const char* cPersona::getDireccion()
{
    return direccion;
}

int cPersona::getEdad()
{
    return edad;
}

int cPersona::getSize_nom()
{
    return size_nombre;
}

int cPersona::getSize_cod()
{
    return size_codigo;
}