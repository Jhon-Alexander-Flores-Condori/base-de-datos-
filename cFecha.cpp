#include "cFecha.hpp"
#include <iostream>

cFecha::cFecha(int day, int month, int year, int valor) {
    // Inicialización con valores por defecto o proporcionados
    dia = (day > 0 && day <= 31) ? day : 1;
    mes = (month > 0 && month <= 12) ? month : 1;
    year = (year > 0) ? year : 2024;
    
    // Inicializar hora con el valor proporcionado o por defecto
    hora = (valor > 0 && valor < 24) ? valor : 1;
    min = (valor > 0 && valor < 60) ? valor : 1;
    seg = (valor > 0 && valor < 60) ? valor : 1;
}

cFecha::cFecha(const cFecha &nuevo) {
    copiadoGeneral(&nuevo);
}

cFecha& cFecha::operator=(const cFecha& otra) {
    if(&otra != this) {
        copiadoGeneral(&otra);
    }
    return *this;
}

void cFecha::actualizarFecha() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    
    year = 1900 + ltm->tm_year;
    mes = 1 + ltm->tm_mon;
    dia = ltm->tm_mday;
    hora = ltm->tm_hour;
    min = ltm->tm_min;
    seg = ltm->tm_sec;
}

void cFecha::print() const {
    std::cout << dia << "/" << mes << "/" << year;
    std::cout << " " << hora << ":" << min << ":" << seg << std::endl;
}

// Implementación de getters
int cFecha::getDia() {
    return dia;
}

int cFecha::getMes() {
    return mes;
}

int cFecha::getYear() {
    return year;
}

int cFecha::getHora() {
    return hora;
}

int cFecha::getMin() {
    return min;
}

int cFecha::getSeg() {
    return seg;
}

// Implementación de setters con validación
void cFecha::setDia(int day) {
    if(day > 0 && day <= 31) {
        dia = day;
    } else {
        std::cout << "Dia invalido. Se mantiene el valor actual." << std::endl;
    }
}

void cFecha::setMes(int month) {
    if(month > 0 && month <= 12) {
        mes = month;
    } else {
        std::cout << "Mes invalido. Se mantiene el valor actual." << std::endl;
    }
}

void cFecha::setYear(int yr) {
    if(yr > 0) {
        year = yr;
    } else {
        std::cout << "Anno invalido. Se mantiene el valor actual." << std::endl;
    }
}

void cFecha::setHora(int hour) {
    if(hour >= 0 && hour < 24) {
        hora = hour;
    } else {
        std::cout << "Hora invalida. Se mantiene el valor actual." << std::endl;
    }
}

void cFecha::setMin(int minute) {
    if(minute >= 0 && minute < 60) {
        min = minute;
    } else {
        std::cout << "Minuto invalido. Se mantiene el valor actual." << std::endl;
    }
}

void cFecha::setSeg(int second) {
    if(second >= 0 && second < 60) {
        seg = second;
    } else {
        std::cout << "Segundo invalido. Se mantiene el valor actual." << std::endl;
    }
}

void cFecha::copiadoGeneral(const cFecha *otra) {
    if(otra != nullptr) {
        dia = otra->dia;
        mes = otra->mes;
        year = otra->year;
        hora = otra->hora;
        min = otra->min;
        seg = otra->seg;
    }
}