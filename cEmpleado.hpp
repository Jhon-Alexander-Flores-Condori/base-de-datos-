// cEmpleado.hpp
#ifndef CEMPLEADO_HPP
#define CEMPLEADO_HPP
#include "cPersona.hpp"
#include <ctime>

class cEmpleado : public cPersona {
private:
    double salario;
    char* cargo;
    char* departamento;
    time_t hora_entrada;
    time_t hora_salida;
    double horas_extra;
    bool activo;
    int size_cargo;
    int size_depto;

public:
    ~cEmpleado();
    cEmpleado();
    cEmpleado(const cEmpleado& obj);
    cEmpleado& operator=(const cEmpleado& obj);

    virtual void print();
    void registrarEntrada();
    void registrarSalida();
    void agregarHorasExtra(double horas);
    double calcularSalario();
    double calcularHorasTrabajadas();
    
    bool actualizarTelefono(char* nuevo_tel);
    bool actualizarCorreo(char* nuevo_correo);
    bool actualizarDireccion(char* nueva_dir);
    void renunciar();
    void despedir();
    void mostrarDetallesEmpleado();
    
    bool llenado_cargo(char* _cargo, int size = 0);
    bool llenado_departamento(char* _depto, int size = 0);
    void setSalario(double _salario);
    
    const char* getCargo();
    const char* getDepartamento();
    double getSalario();
    bool estaActivo();

protected:
    void ultimoAcceso() override;
};
#endif



