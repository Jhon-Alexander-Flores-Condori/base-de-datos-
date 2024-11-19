#ifndef CPELUCHE_HPP
#define CPELUCHE_HPP

#include "cPrenda.hpp"

class cPeluche:public cPrenda
{
    public:
        cPeluche();
        cPeluche(char * name, char *code, char * measure, int tam_cod, int tam_name,
                   int tam_measure,float money, char * relleno_unidad,
                   int tam_relleno_unidad, float money_relleno, float
                   money_final, float weight_relleno, float weight_final);
        cPeluche(const cPeluche &obj);
        cPeluche& operator=(const cPeluche &obj);

        bool llenado_unidad_relleno(char * cadena, int size= 0);
        bool llenado_size_unidad_relleno(int size, char * cadena = nullptr);

        bool llenado_peso_relleno(float numero);
        bool llenado_precio_relleno(float numero);
        bool llenado_precio_final();
        bool llenado_peso_final();

		const char * getUnidad_relleno();
        int getSize_unidad_relleno();

        float getPrecio_relleno();
        float getPeso_relleno();
        float getPeso_final();
        float getPrecio_final();

        ~cPeluche();



    private:
        char *unidad_relleno;

        int size_unidad_relleno;

        float peso_relleno;
        float precio_relleno;
        float precio_final;
        float peso_final;

        void llenado_nullptr();

        bool asignar_valores(const cPeluche &obj);

};

#endif
