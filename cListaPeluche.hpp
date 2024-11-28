#ifndef CLISTAPELUCHE_HPP
#define CLISTAPELUCHE_HPP

#include "cPrenda.hpp"
#include "cListaPrenda.hpp"
#include <iostream>

class cListaPeluche : public cListaPrenda
{
    public:
        cListaPeluche();
        cListaPeluche(cPrenda * nuevo, int tam, char *code, char * source, char * fill,
                      int tam_code, int tam_source, int tam_fill);
        cListaPeluche();

        bool llenado_peluche(cPeluche * nuevo, int value);
        bool llenado_maFill(char *code, int size = 0);
        bool llenado_size_maFill(int size, char * cadena = nullptr);

        bool llenado_precio_total() override;

        const char* getRelleno();
        int getRelleno_size();

        bool addContent(cPrenda *nuevo, int add);
        bool deleteContent(int begin, int end) override;

        ~cListaPeluche() override;

    private:
        char * material_fill;
        float precio_total;

        int size_material_fill;

        void crear_memoria() override;

        void llenado_default();
};

#endif
