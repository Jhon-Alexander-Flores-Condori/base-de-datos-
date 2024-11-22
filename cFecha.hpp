// cFecha.hpp
#ifndef CFECHA_HPP
#define CFECHA_HPP
#include <ctime>
#include <cstdio>

class cFecha {
private:
    int dia;
    int mes;
    int year;
    int hora;
    int min;
    int seg;

public:
    explicit cFecha(int day = 1, int month = 1, int year = 2024, int valor = 1);
    explicit cFecha(const cFecha &nuevo);

    cFecha& operator=(const cFecha& otra);

    void print() const;
    void actualizarFecha();

    // Métodos getter y setter
    int getDia();
    int getMes();
    int getYear();
    int getMin();
    int getSeg();
    int getHora();

    void setDia(int day);
    void setMes(int month);
    void setYear(int year);
    void setHora(int hour);
    void setMin(int minute);
    void setSeg(int second);

    void copiadoGeneral(const cFecha *otra);

    // Método que llena un puntero char* con la fecha formateada
    void getFecha(char* fecha) const {
        // Asegúrate de que `fecha` tiene suficiente memoria asignada
        snprintf(fecha, 20, "%02d/%02d/%04d %02d:%02d:%02d", dia, mes, year, hora, min, seg);
    }
};

#endif
