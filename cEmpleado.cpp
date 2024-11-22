#include "cEmpleado.hpp"
#include "cEmpleado.hpp"
#include <iostream>
#include <iomanip>

cEmpleado::~cEmpleado() {
    liberar(&cargo);
    liberar(&departamento);
}

cEmpleado::cEmpleado() : cPersona() {
    cargo = nullptr;
    departamento = nullptr;
    salario = 0.0;
    horas_extra = 0.0;
    hora_entrada = 0;
    hora_salida = 0;
    activo = true;
    size_cargo = 0;
    size_depto = 0;
}

cEmpleado::cEmpleado(const cEmpleado& obj) : cPersona(obj) {
    cargo = nullptr;
    departamento = nullptr;
    salario = obj.salario;
    hora_entrada = obj.hora_entrada;
    hora_salida = obj.hora_salida;
    horas_extra = obj.horas_extra;
    activo = obj.activo;
    size_cargo = 0;
    size_depto = 0;

    if (obj.cargo) {
        llenado_cargo(obj.cargo);
    }
    if (obj.departamento) {
        llenado_departamento(obj.departamento);
    }
}

cEmpleado& cEmpleado::operator=(const cEmpleado& obj) {
    if (this != &obj) {
        // Llamamos al operador de asignación de la clase base
        cPersona::operator=(obj);

        // Liberamos la memoria actual
        liberar(&cargo);
        liberar(&departamento);

        // Copiamos los valores simples
        salario = obj.salario;
        hora_entrada = obj.hora_entrada;
        hora_salida = obj.hora_salida;
        horas_extra = obj.horas_extra;
        activo = obj.activo;
        size_cargo = 0;
        size_depto = 0;

        // Copiamos las cadenas dinámicas
        if (obj.cargo) {
            llenado_cargo(obj.cargo);
        }
        if (obj.departamento) {
            llenado_departamento(obj.departamento);
        }
    }
    return *this;
}

void cEmpleado::registrarEntrada() {
    if (activo) {
        hora_entrada = time(nullptr);
        ultimoAcceso();
    }
}

void cEmpleado::registrarSalida() {
    if (activo) {
        hora_salida = time(nullptr);
        ultimoAcceso();
    }
}

void cEmpleado::agregarHorasExtra(double horas) {
    if (activo && horas > 0) {
        horas_extra += horas;
        ultimoAcceso();
    }
}

double cEmpleado::calcularSalario() {
    if (!activo) return 0.0;
    double salario_total = salario;
    // Asumiendo que las horas extra se pagan al 150% del valor normal
    double valor_hora = salario / 160.0; // 160 horas mensuales estándar
    salario_total += (horas_extra * valor_hora * 1.5);
    return salario_total;
}

double cEmpleado::calcularHorasTrabajadas() {
    if (hora_entrada == 0 || hora_salida == 0) return 0.0;
    return difftime(hora_salida, hora_entrada) / 3600.0; // Convertir segundos a horas
}

bool cEmpleado::actualizarTelefono(char* nuevo_tel) {
    if (llenado_telefono(nuevo_tel)) {
        ultimoAcceso();
        return true;
    }
    return false;
}

bool cEmpleado::actualizarCorreo(char* nuevo_correo) {
    if (llenado_correo(nuevo_correo)) {
        ultimoAcceso();
        return true;
    }
    return false;
}

bool cEmpleado::actualizarDireccion(char* nueva_dir) {
    if (llenado_direccion(nueva_dir)) {
        ultimoAcceso();
        return true;
    }
    return false;
}

void cEmpleado::renunciar() {
    activo = false;
    ultimoAcceso();
}

void cEmpleado::despedir() {
    activo = false;
    ultimoAcceso();
}

void cEmpleado::print() {
    cPersona::print();
    std::cout << "Cargo: " << (cargo ? cargo : "No asignado") << std::endl;
    std::cout << "Departamento: " << (departamento ? departamento : "No asignado") << std::endl;
    std::cout << "Salario base: $" << std::fixed << std::setprecision(2) << salario << std::endl;
    std::cout << "Horas extra acumuladas: " << horas_extra << std::endl;
    std::cout << "Estado: " << (activo ? "Activo" : "Inactivo") << std::endl;
    
    if (hora_entrada != 0) {
        std::cout << "Última hora de entrada: " << ctime(&hora_entrada);
    }
    if (hora_salida != 0) {
        std::cout << "Última hora de salida: " << ctime(&hora_salida);
    }
}

void cEmpleado::mostrarDetallesEmpleado() {
    print();
    std::cout << "Salario total (incluye horas extra): $" 
              << std::fixed << std::setprecision(2) << calcularSalario() << std::endl;
    std::cout << "Horas trabajadas en último registro: " 
              << std::fixed << std::setprecision(1) << calcularHorasTrabajadas() << std::endl;
}

bool cEmpleado::llenado_cargo(char* _cargo, int size) {
    if (!_cargo) return false;
    size = size == 0 ? contador(_cargo) : size;
    crear_memoria(size, &cargo);
    copiar(_cargo, cargo, size);
    size_cargo = size;
    return true;
}

bool cEmpleado::llenado_departamento(char* _depto, int size) {
    if (!_depto) return false;
    size = size == 0 ? contador(_depto) : size;
    crear_memoria(size, &departamento);
    copiar(_depto, departamento, size);
    size_depto = size;
    return true;
}

void cEmpleado::setSalario(double _salario) {
    if (_salario >= 0) {
        salario = _salario;
        ultimoAcceso();
    }
}

const char* cEmpleado::getCargo() {
    return cargo;
}

const char* cEmpleado::getDepartamento() {
    return departamento;
}

double cEmpleado::getSalario() {
    return salario;
}

bool cEmpleado::estaActivo() {
    return activo;
}

void cEmpleado::ultimoAcceso() {
    llenado_generalFecha();
}