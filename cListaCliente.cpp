#include "cListaCliente.hpp"
#include <iostream>

cListaCliente::cListaCliente()
{
    llenado_nullptr();
    size_cliente = -1;
    size_code = -1;
}

cListaCliente::cListaCliente(cCliente* nuevo, int tam, char* code, int tam_cod)
{
    llenado_nullptr();
    if (llenado_cliente(nuevo, tam))
        std::cout << "CLIENTE LLENADO" << std::endl;
    else
        std::cout << "ERROR AL LLENAR CLIENTE" << std::endl;

    if (llenado_codigo(code, tam_cod))
        std::cout << "CÓDIGO LLENADO" << std::endl;
    else
        std::cout << "ERROR AL LLENAR CÓDIGO" << std::endl;
}

cListaCliente::~cListaCliente()
{
    liberar_memoria(&manyClients);
    liberar_arrays(&codigo);
}

bool cListaCliente::llenado_codigo(char* code, int size)
{
    if (!code || size <= 0) return false;

    liberar_arrays(&codigo);
    crear_memoria_arrays(size, &codigo);
    copiar(code, codigo, size);

    size_code = size;
    return true;
}

bool cListaCliente::llenado_size_cod(int size, char* cadena)
{
    if (size <= 0) return false;

    liberar_arrays(&codigo);
    crear_memoria_arrays(size, &codigo);
    if (cadena)
        copiar(cadena, codigo, size);
    else
        for (int i = 0; i < size; i++) codigo[i] = '\0';

    size_code = size;
    return true;
}

bool cListaCliente::llenado_size(int valor)
{
    if (valor <= 0) return false;

    size_cliente = valor;
    return true;
}

bool cListaCliente::llenado_cliente(cCliente* nuevo, int value)
{
    if (!nuevo || value <= 0) return false;

    liberar_memoria(&manyClients);
    crear_memoria(value, &manyClients);
    size_cliente = value;

    return true;
}

cCliente* cListaCliente::getCliente()
{
    return manyClients;
}

char* cListaCliente::getCodigo()
{
    return codigo;
}

int cListaCliente::getSize()
{
    return size_cliente;
}

int cListaCliente::getSize_code()
{
    return size_code;
}

void cListaCliente::print()
{
    std::cout << "Clientes: " << size_cliente << std::endl;
    std::cout << "Código: " << (codigo ? codigo : "N/A") << std::endl;
}

bool cListaCliente::addContent(cCliente* nuevo, int add)
{
    if (!nuevo || add <= 0) return false;

    // Implementación básica: solo actualiza el tamaño.
    size_cliente += add;
    return true;
}

bool cListaCliente::deleteContent(int begin, int end)
{
    if (begin < 0 || end >= size_cliente || begin > end) return false;

    // Implementación básica: reduce el tamaño.
    size_cliente -= (end - begin + 1);
    return true;
}

void cListaCliente::buscarCodigo(char* codigo, int* temp)
{
    // Implementación básica de búsqueda de código
}

void cListaCliente::buscarNombre(char* codigo, int fin, int inicio, int* temp)
{
    // Implementación básica de búsqueda por nombre
}

void cListaCliente::llenado_nullptr()
{
    manyClients = nullptr;
    codigo = nullptr;
}

void cListaCliente::copiar(const char* root, char* destino, int tam)
{
    for (int i = 0; i < tam; i++)
        destino[i] = root[i];
}

int cListaCliente::contador(const char* cadena)
{
    int count = 0;
    while (cadena && cadena[count] != '\0') count++;
    return count;
}

void cListaCliente::crear_memoria_arrays(int tam, char** destino)
{
    *destino = new char[tam];
}

void cListaCliente::liberar_arrays(char** target)
{
    delete[] *target;
    *target = nullptr;
}

void cListaCliente::crear_memoria(int tam, cCliente** target)
{
    *target = new cCliente[tam];
}

void cListaCliente::liberar_memoria(cCliente** target)
{
    delete[] *target;
    *target = nullptr;
}

cListaCliente::~cListaCliente()
{
    liberar_memoria(&manyClients); // Libera la memoria de manyClients
    liberar_arrays(&codigo);      // Libera la memoria de codigo
}
