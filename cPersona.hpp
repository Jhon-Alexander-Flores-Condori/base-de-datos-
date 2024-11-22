#ifndef CPERSONA_HPP
#define CPERSONA_HPP

#include "cFecha.hpp"
#include <iostream>

class cPersona {
private:
    const char* nombre;
    const char* codigo;
    const char* cadena_fecha;
    int size_nom;
    int size_cod;
    cFecha fecha;

public:
    ~cPersona();
    cPersona();
    cPersona(char* name, char* code, int tam_nom, int tam_cod);
    cPersona(const cPersona& obj);
    cPersona& operator=(const cPersona& obj);

    void asignar_nullptr();
    bool llenado_nombre(char* name, int size);
    bool llenado_codigo(char* code, int size);
    bool llenado_size_nom(int size, char* cadena);
    bool llenado_size_cod(int size, char* cadena);
    void llenado_fecha();
    const char* getFecha() const;
    const char* getNombre() const;
    const char* getCodigo() const;
    int getSize_nom() const;
    int getSize_cod() const;

    void ultimoAcceso();
    void llenado_generalFecha();
    bool asignarValores(const cPersona* obj);
    void copiar(char* root, char* destino, int tam);
    int contador(const char* cadena);
    void crear_memoria(int tam, char** destino);
    void liberar(char** target);

    // Método virtual para permitir la sobrecarga en clases derivadas
    virtual void print() const; 
};

#endif
