// cPersona.hpp
#ifndef CPERSONA_HPP
#define CPERSONA_HPP
#include "cFecha.hpp"

class cPersona {
protected: //atributos
    cFecha fecha;
    char* nombre;
    char* codigo; //id
    char* cadena_fecha;
    char* telefono;
    char* correo;
    char* direccion;
    int edad;
    int size_nom;
    int size_cod;
    int size_tel;
    int size_correo;
    int size_dir;

public:
    virtual ~cPersona();
    cPersona();
    cPersona(char* name, char* code, int tam_nom, int tam_cod);
    cPersona(const cPersona& obj);
    cPersona& operator=(const cPersona& obj);

    virtual void print();
    bool llenado_nombre(char* name, int size = 0);
    bool llenado_codigo(char* code, int size = 0);
    bool llenado_telefono(char* tel, int size = 0);
    bool llenado_correo(char* email, int size = 0);
    bool llenado_direccion(char* dir, int size = 0);
    bool llenado_size_nom(int size, char* cadena = nullptr);
    bool llenado_size_cod(int size, char* cadena = nullptr);
    void llenado_fecha();
    void setEdad(int _edad);

    const char* getFecha();
    const char* getNombre();
    const char* getCodigo();
    const char* getTelefono();
    const char* getCorreo();
    const char* getDireccion();
    int getEdad();
    int getSize_nom();
    int getSize_cod();

protected:
    virtual void ultimoAcceso();
    void asignar_nullptr();
    void llenado_generalFecha();
    bool asignarValores(const cPersona* obj);
    void copiar(char* root, char* destino, int tam);
    int contador(const char* cadena);
    void crear_memoria(int tam, char** destino);
    void liberar(char** target);
};
#endif