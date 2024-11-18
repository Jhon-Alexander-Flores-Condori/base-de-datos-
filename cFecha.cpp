#include "cFecha.hpp"
#include <iostream>
#include <ctime>

cFecha::cFecha(int day, int month, int year, int valor)
    : dia(day), mes(month), year(year), hora(valor), min(valor), seg(valor) {}

void cFecha::print() const
{
    std::cout << "dd/mm/yy : " << dia << "/" << mes << "/" << year << std::endl;
    std::cout << "hh:mm:ss : " << hora << ":" << min << ":" << seg << std::endl;
}

cFecha::cFecha(const cFecha &nuevo) {
    copiadoGeneral(&nuevo);  // Copia los miembros del objeto 'nuevo'
}

cFecha& cFecha::operator=(const cFecha& otra) {
    if (this != &otra) {  // Evitar la auto-asignación
        copiadoGeneral(&otra);  // Copia los miembros del objeto 'otra'
    }
    return *this;  // Retorna la referencia al objeto actual
}

void cFecha::copiadoGeneral(const cFecha* otra) {
    // Copiar los valores de los miembros
    dia = (*otra).dia;
    mes = (*otra).mes;
    year = (*otra).year;
    hora = (*otra).hora;
    min = (*otra).min;
    seg = (*otra).seg;
}

void cFecha::actualizarFecha()
{
    std::time_t tiempoActual = std::time(nullptr);
    std::tm* tiempoLocal = std::localtime(&tiempoActual);

    dia = tiempoLocal->tm_mday;//(*tiempoLocal).tm_day
    mes = tiempoLocal->tm_mon + 1;
    year = tiempoLocal->tm_year + 1900;
    hora = tiempoLocal->tm_hour;
    min = tiempoLocal->tm_min;
    seg = tiempoLocal->tm_sec;
}


int cFecha::getDia()
    { return dia; }

int cFecha::getMes()
    { return mes; }

int cFecha::getYear()
    { return year; }

int cFecha::getMin()
    { return min; }

int cFecha::getSeg()
    { return seg; }

int cFecha::getHora()
    { return hora; }

void cFecha::setDia(int day)
    { dia = day; }

void cFecha::setMes(int month)
    { mes = month; }

void cFecha::setYear(int year)
    { this->year = year; }

void cFecha::setHora(int hour)
    { hora = hour; }

void cFecha::setMin(int minute)
    { min = minute; }

void cFecha::setSeg(int second)
    { seg = second; }
