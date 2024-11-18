#ifndef CPRENDA_HPP
#define CPRENDA_HPP

#include "cPrenda.hpp"

class cPeluche:public cPrenda()
{
    public:
		char * getTipo_relleno();
		char * getUnidad_relleno();
		int getSize_relleno();
        float getPrecio_relleno();


    private:
        char * tipo_relleno;
        char *unidad_relleno;

        int size_relleno;
        float peso_relleno;

        void llenado_nullptr();

		bool asignarValores(const cPeluche *obj);
		void copiar(char *root, char *destino, int tam);
		int contador(const char *cadena);

        void crear_memoria(int tam, char ** destino);
		void liberar(char **target);

};

#endif
