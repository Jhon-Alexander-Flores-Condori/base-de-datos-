#ifndef CLISTAPELUCHE_HPP
#define CLISTAPELUCHE_HPP

#include "cPrenda.hpp"
#include "cListaPrenda.hpp"
#include <iostream>

class cListaPeluche : public cListaPrenda
{
    public:
        using cListaPrenda::addContent;
        cListaPeluche();
        cListaPeluche();
        cListaPeluche();

        bool llenado_codigo(char *code, int size = 0) override ;
        bool llenado_size_cod(int size, char * cadena = nullptr) override;

        bool llenado_peluche(cPeluche * nuevo, int value);
        bool llenado_maTela(char *code, int size = 0);
        bool llenado_size_maTela(int size, char * cadena = nullptr);
        bool llenado_maFill(char *code, int size = 0);
        bool llenado_size_maFill(int size, char * cadena = nullptr);

        bool llenado_size(int valor) override;
        bool llenado_precio_total() override;

        bool addContent(cPrenda *nuevo, int add);
        bool deleteContent(int begin, int end) override;

        ~cListaPeluche();

    private:
        cPeluche * manyToys;
        char * codigo;//MODELO
        char * material_telar;
        char * material_fill;
        float precio_total;

        int size_toys;
        int size_code;
        int size_material_telar;
        int size_material_fill;

        void crear_memoria() override;
        void liberar_memoria() override;
};

#endif
